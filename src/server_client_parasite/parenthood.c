#include "parenthood.h"

char *uname;
pid_t child_pid;
int is_address, sockets[2];
long unsigned int waiting_func_reply, result_func_reply;
long int heap_offset;

void prepare_func_call(char *func_name, 
		       unsigned long long *args, 
		       int argc)
{
	FILE *bin_aux;
	int i = 0;
	static int first_time = 1;

	if (!(bin_aux = fopen("aux_server_popsgx","w+"))){
		errExit("error opening aux server file");
	}

	/*
	  What the child reads:
	  +--------------+
	  | func         | Function name to execute
	  +--------------+
	  | argc         | Number of arguments
	  +--------------+ 
	  | args         | Arguments
	  +--------------+
	  | *offset heap | Offset to apply to pointers
	  +--------------+             

	  *Only the first time
	*/

	fprintf(bin_aux,"%s\n",func_name);
	fprintf(bin_aux,"%d\n",argc);

	for (; i < argc; ++i){
		fprintf(bin_aux,"%llu\n",args[i]);
	}

	if (first_time){
		fprintf(bin_aux,"%ld\n",heap_offset);	
		first_time = 0;
	}

	fclose(bin_aux);
}

int wait_func_call(void)
{
	FILE *bin_aux;
	char s[20];
	int ret = -1;

	while (true){

		if (!(bin_aux = fopen("aux_server_popsgx","r"))){
			errExit("error opening aux server file");
		}

		ret = fscanf(bin_aux, "%s",s);

		if (!strcmp(s,"OK")){
			if (fscanf(bin_aux, "%d",&ret) == EOF){
				errExit("Couldn't read return value at wait_func_call()");
			}
			fclose(bin_aux);
			break;
		}

		sleep(0.25);
		fclose(bin_aux);
 	}

 	return ret;
}

void open_tmp_file(FILE **file, char *name)
{
	*file = fopen(name, "r");

	if (0) {
open_file:	*file = fopen(name, "r");
	}

	if (!*file){
		if (errno == ENOENT){
			/* Let's give some time to the executable... */
			sleep (0.5);
			goto open_file;
		}
		errExit("opening the tmp file");
	}
}

int request_page(char *request, FILE *file)
{
	int ret = 0, read;
	long unsigned int faulty_addr;

	if (!strncmp(request,"page_fault",4))
	{
		ret = 1;
		is_address = 1;

		/* Retrieve the address that triggered the page fault */
		if ((read = fscanf(file, "%lx",&faulty_addr)) == EOF){
		 	errExit("error reading faulty address of the child");
		}

		result_func_reply = handle_dsm_fault(faulty_addr);

		/* Copy page data to socket */
		if (send(sockets[0],&result_func_reply,sysconf(_SC_PAGE_SIZE),0) != 
			sysconf(_SC_PAGE_SIZE)){
				errExit("could not copy page data...\n");
		}
	}

	return ret;
}

int request_uffd(char *request, FILE *file)
{
	int ret = 0, read;
	long unsigned int heap_start_region, heap_length;

	if (!strncmp(request,"uffd",4))
	{
		ret = 1;

		/* Retrieve the heap starting region of the child */
		if ((read = fscanf(file, "%lx",&heap_start_region)) == EOF){
		 	errExit("error reading heap start address of the child");
		}

		/* Retrieve the heap length of the child */
		if ((read = fscanf(file, "%ld",&heap_length)) == EOF){
		 	errExit("error reading heap_length of the child");
		}

		update_dsm_pages(heap_start_region, heap_length);

		/* Send the other side our child's heap info */
		send_heap_info(heap_start_region, heap_length);
		
		waiting_func_reply = 1;

		/* Wait for a reply */
		while (waiting_func_reply) {
		 	sleep((unsigned int)0.25);	
		}
	}

	return ret;
}

void set_child_pid(pid_t the_pid)
{
	child_pid = the_pid;
}

pid_t get_child_pid(void)
{
	return child_pid;
}

/* Handler for SIGUSR1, sent by the thread in execution. */ 
void __handle_signal(int sig, siginfo_t *siginfo, void *context) 
{ 
	FILE *tmp_binary = NULL;
	static char *file_name = "child_request";
	char request[100], *socket="socket";
	int read, num_args, i=0;
	long int *args;

	/* Ignore this if it was not our child that signaled... */
	while (!child_pid){
		sleep(0.1);
	}

	if (child_pid != siginfo->si_pid){
		printf("Received signal from pid=%d",siginfo->si_pid);
		return;
	}

	is_address = 0;

	/* Let's check what does the child binary want */
	open_tmp_file(&tmp_binary,file_name);

test_request:

	if ((read = fscanf(tmp_binary, "%s",request)) == EOF){
	 	errExit("error reading tmp args file");
	}

	/* Remove newline */
	request[strcspn(request,"\r\n")] = '\0'; 

	/* The child could not open the usual child_request, check emergency_child_req */
	if (!strcmp(request, "OK")){
		open_tmp_file(&tmp_binary,"emergency_child_req");
		goto test_request;
	}

	if (!strncmp(request,socket,4)){
		result_func_reply = sockets[1];
	}
	/* Are we getting a uffd update request? */
	else if (!request_uffd(request,tmp_binary)) 
	{
		/* Are we getting a page fault handling request? */
		if (!request_page(request,tmp_binary)){
	
			/* It must be a function request */
			args = malloc(sizeof(unsigned long long) *MAX_ARGS);
			result_func_reply = -1;
			waiting_func_reply = 1;		

			/* Retrieve the number of arguments for the call */
			if ((read = fscanf(tmp_binary, "%d",&num_args)) == EOF){
			 	errExit("error reading num args from file");
			}

			/* Read arguments */
			for (; i < num_args && i < MAX_ARGS; ++i){
			    if ((read = fscanf(tmp_binary, "%ld",&args[i])) == EOF){
			 		errExit("error reading arg from file");
			    }
			 }

			 send_call_request(request,num_args,args);

			 /* Wait for a reply */
			 while (waiting_func_reply) {
			 	sleep((unsigned int)0.25);	
			 }
		}
	}

	/* Notify that the signal has been handled */
	tmp_binary = freopen(file_name,"w",tmp_binary);
	
	if (!is_address){
		fprintf(tmp_binary,"OK\n%ld\n",result_func_reply);
	}
	else {
		fprintf(tmp_binary,"OK\n%lx\n",result_func_reply);	
	}

	fclose(tmp_binary);
} 

void prepare_parenthood(char *the_uname)
{
	struct sigaction sigact;

	uname       = the_uname;
	child_pid   = 0;
	heap_offset = 0;

	/* Register sockets to share pages faster... */
	if (socketpair(AF_LOCAL, SOCK_STREAM, 0, sockets) == -1){
    		errExit("socket pairing failed");
    }

	/* Register custom signal handler */

	memset(&sigact,'\0',sizeof(sigact));
	sigact.sa_sigaction = &__handle_signal;
	sigact.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sigact, NULL) < 0) {
		errExit("sigaction");
	}
}
