/*
 *	PopSGX untrusted binary management (client).
 *	@author Carlos Bilbao 😎
 *	bilbao [at] vt [dot] edu
 */
#include "untrusted.h"

char* DEFAULT_BINARY = "helloworld";

static void __sanitize_args(char **user_args)
{
	// Future work don't hardcode this (ask)
	if (!strcmp(user_args[0],"file-encryptorhostbin")){
		
		user_args[2] = user_args[1];
		user_args[1] = malloc(strlen("test_file"));
		strncpy(user_args[1],"test_file",9); 
		user_args[3] = NULL;
		log_info("./%s %s %s",user_args[0], user_args[1], user_args[2]);	
	}
	else {	
		if (!strcmp(user_args[1], "virtual-assistantenc.signed")) {
			free(user_args[0]);
			user_args[0] = calloc(30,1);
			strcpy(user_args[0],"virtual-assistanthostbin");
		}
		log_info("./%s %s",user_args[0], user_args[1]);	
	}

}

static void parse_args_run_untrusted(binary *ubin, char **user_args)
{
	char fgets_buffer[100];

	for (;;){
		printf("Execute binary %s? [y/n]: ",ubin->uname);

                if (!fgets(fgets_buffer, INPUT_CMD_LEN, stdin)){
                        errExit("fgets error");
                } 

                if (!strncmp(fgets_buffer, "y", 1)){
repeat_question:
			printf("Use enclave image (%s) as only argument? [y/n]: "
			,ubin->signed_enc);

			if (!fgets(fgets_buffer, INPUT_CMD_LEN, stdin)){
                	        errExit("fgets error");
                	} 

                        if (!strncmp(fgets_buffer, "y", 1)){
	      			user_args[1] = malloc(strlen(ubin->signed_enc));
				strcpy(user_args[1],ubin->signed_enc);
				user_args[2] = NULL;         		
				break;
			}
			else if (!strncmp(fgets_buffer, "n",1)){
				printf("Args for the binary: ");
				// TODO
			}
			else goto repeat_question;
                }
                else if (!strncmp(fgets_buffer, "n", 1)){
                        return;
                }
	}

}

void __run_child(char **user_args, int ptrace_socket)
{
	pid_t me;
	int err = 0;

	/* Wait for the parent to attach */
	if (recv(ptrace_socket, &me, sizeof(me),0) != sizeof(me)){
		err = 1;
	}

	close(ptrace_socket);
	
	if (err){
		errExit("ptrace could not attach correctly");
	}

	/* Trace-stop so that the parent can configure ptrace */
	if (raise(SIGSTOP)){
		errExit("child could not raise SIGSTOP");
	}

	log_info("Ptrace configuration concluded...");
	__sanitize_args(user_args);

	if (execve(user_args[0],user_args,NULL) == -1){
		errExit("running untrusted binary");
	}
}

/*  ///////////////////////////////////////////////
    //                                          //
    //   Run the untrusted binary.              //
    //   This function is important!            //
    //                                          //
    //   child binary  ->  __run_child()        //
    //   parent server ->  __trace_untrusted()  //
    //                                          //
    //////////////////////////////////////////////
 */
void run_untrusted(binary* ubin)
{
	int ret, image=1, wstatus, write_ret, ptrace_sockets[2];
	char *user_args[10];
	pid_t child;

	parse_args_run_untrusted(ubin,user_args);

	user_args[0] = ubin->uname;

	/* Register the signal handler for the binary */
	prepare_parenthood(ubin->uname);

	/* Register two sockets to synchronize the parent attached to its 
	   child via ptrace 
	*/
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, ptrace_sockets) == -1)
		errExit("ptrace sockets pairing failed");

	log_info("........................................");

	child = fork();

	if (child == 0){
		__run_child(user_args,ptrace_sockets[1]);	
	}
	else if (child < 0){
		errExit("forking child failed");
	}

	set_child_pid(child);
	ubin->pid = child;

	ret = 0;

	/* Attach via seizing (so we can interrupt the child) */
	if (!attach_traicee(child) ||
		send(ptrace_sockets[0],&child,sizeof(child),0) != sizeof(child)){
		ret = 1;
	}	

	close(ptrace_sockets[0]);
	close(ptrace_sockets[1]);

	if (ret){
		errExit("Could not attach traicee");
	}

	/* Wait until the child trace-stops and configure ptrace */
	if (!wait_trace(child)){
		errExit("waiting for trace failed");
	}
	
	status = STOPPED;

	if (!traceable()){
		errExit("Process is not traceable");
	}
	if (!trace_process(child)){
		errExit("trace set up failed");
	}

	log_info("Ptrace setup succeed! Resuming child...");

	/* Make the child execute the untrusted binary with execve */
	if (!resume(child)){
		errExit("could not resume the child");
	}

	/* Update the child's status */
	status = RUNNING;

	/* Wait for child to reach trace-stop and initialize */
	if (initialize_ptrace(child)){
		errExit("could not initialize ptrace");
	}

	log_info("Ptrace fully initialized...");

	/* Just handle requests from child and other side until child finishes. 
	 * When that happens, let server know when untrusted child is done - to 
	 * terminate enclave 
	*/
	while (1){
		if (waitpid(child,&wstatus,0) != 1){
			/* Just keep waiting if it gets stopped or signaled... */
	   		if (WIFEXITED(wstatus)) {
terminate_enc:
	   			notify_terminate_enclave();
	   			log_info("........................................");
	   			break;
	   		}
			else if (WIFSTOPPED(wstatus)){
				status = STOPPED;
				// TODO See reason
				if (!resume(child)) {
					goto terminate_enc;
				}
			}		
		}
		else {
			errExit("waitpid on parent failed");
		}
	}
}

/*
   Send untrusted binary file to the client. 
*/
void send_untrusted(SSL *ssl, binary* ubin, char *name_bin, int got_name)
{
        char fgets_buffer[100], binary_file[INPUT_CMD_LEN];

	if (!got_name){

        	printf("Name of binary?: ");

        	if (!fgets(binary_file, INPUT_CMD_LEN, stdin)){
                	errExit("fgets error");
        	}

		//strcpy(binary_file,DEFAULT_BINARY); 
	}
	else {
		strcpy(binary_file,name_bin);
	}

	bin_ssl = ssl;
	
	/* Copy (un)trusted binary name and signed enclave */
	ubin->uname       = malloc(sizeof(binary_file) + 4); //4 as in 'host'
       	ubin->tname       = malloc(sizeof(binary_file) + 3); //3 as in 'enc'
       	ubin->signed_enc  = malloc(sizeof(binary_file) + 10); //10 as in 'enc.signed'
	
	/* Remove newline */
	binary_file[strcspn(binary_file, "\n")] = 0;

	sprintf(ubin->uname,"%shost",binary_file);
	sprintf(ubin->tname,"%senc",binary_file);
	sprintf(ubin->signed_enc,"%senc.signed",binary_file);

	/* Send binary and get the signed image name */	
	dsm_send_binary(ssl,ubin);
}
