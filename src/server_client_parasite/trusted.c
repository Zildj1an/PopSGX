/*
 *	PopSGX trusted binary management.
 *	@author Carlos Bilbao
 *	bilbao [at] vt [dot] edu
 */
#include <string.h>

#include "trusted.h"
#include "dsm_statemachine.h"

int is_address;
long unsigned int waiting_func_reply, result_func_reply;

/*
 *	Execute the binary on the server side.
 */
void prepare_trusted_side(binary* tbin)
{
	char *user_args[3], i = 'a';
	FILE *bin_aux;
	pid_t child;
	const char* filename = "/dev/null";
	int fd, wstatus;

	pid_server_bin = -1;
	
	/* Let the binary know we are the server */
	bin_aux = fopen("aux_server_popsgx","w+");

	if (!bin_aux){
		log_error("Error opening file aux_server_popsgx");
		abort();
	}

	fprintf(bin_aux,"%d",getpid());
	fclose(bin_aux);
	
	user_args[0] = tbin->uname;
	user_args[1] = "NULL";
	user_args[2] = NULL;

	/* Register the signal handler for the binary */
	prepare_parenthood(tbin->uname);

	child = fork();

	if (child == 0){

		fd = open(filename, O_WRONLY, 0666);

		/* Redirect server child's output */
		dup2(fd, STDOUT_FILENO);

		if (execve(user_args[0],user_args,NULL) == -1){
			errExit("running untrusted binary");
		}
	}
	else if (child < 0){
		errExit("forking dummy child failed");
	}

	set_child_pid(child);

	/* Just handle requests from child and other side now... */
	while(1){
		if (waitpid(child,&wstatus,0) != 1){
			/* Just keep waiting if it gets stopped or signaled... */
	   		if(WIFEXITED(wstatus)) {
	   			notify_terminate_enclave();
	   			log_info("<< Server side child exited!!");
	   			abort();
				break;
	   		}
	   	}
	}
}
