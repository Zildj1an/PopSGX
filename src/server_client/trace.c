#include "trace.h"

/* Binaries (traicees) should call this to enable DSM */
int start_tracing_me(void)
{
	int ret = 0;

	if (ptrace(PTRACE_TRACEME,0,0,0) == 0) {
		ret = 1;
	}
	return ret;	
}

int attach_traicee(int pid)
{
	int ret = 0;

	// PTRACE_ATTACH stops process
	if (ptrace(PTRACE_SEIZE,pid,0,0) == 0){
		ret = 1;
	}

	return ret;
}

int trace_process(int pid)
{
	int ret = 0;

	if (ptrace(PTRACE_SETOPTIONS,pid,0, 
	   	   PTRACE_O_EXITKILL | 
		   PTRACE_O_TRACECLONE | 
		   PTRACE_O_TRACEEXEC | 
		   PTRACE_O_TRACEFORK) == 0)
	{
		ret = 1;
	}

	return ret;
}

int wait_trace(int pid)
{
	int retval = 1, wstatus;

	/* Is the child already stopped? */
	if (status != RUNNING && status != UNKNOWN) goto end_wait_trace;

	if (waitpid(pid, &wstatus, 0) == -1){
		// Would be nice to check for third-parties interrupting or deaths here.
		log_error("waitpid failed");
	}
	else {
		if (WIFEXITED(wstatus)) {
      		status = EXITED;
    	}
    	else if (WIFSIGNALED(wstatus)) {
      		status = SIGNALEXIT;
    	}
    	else if (WIFSTOPPED(wstatus)) {
			status = STOPPED;
      	}
    	else {
      		status = UNKNOWN;
      		retval = 0;
      		log_error("Unknown wait status");
    	}
	}	

end_wait_trace:
	return retval;
}

int traceable(void)
{
	return (status == STOPPED || status == INTERRUPTED);
}

/* Resume child that is in a valid state */
static int __resume(int pid)
{
	int ret = 0;

	if (ptrace(PTRACE_CONT,pid,0,0) == 0) 
		ret = 1;

	return ret;
}

int resume(int pid)
{
	int ret = 1;

	switch (status){
	case RUNNING: /* Invalid state */
		ret = 0;
	break;
	case EXITED:
	case SIGNALEXIT: /* We are not necromancers... */
		ret = 0;
	break;
	default:
		ret = __resume(pid);
	}

	return ret;
}

/* Read memory from tracee's (child) address space. Read addr to data. */
int get_memory(pid_t tracee, u_int64_t *addr, u_int64_t *data)
{
	int ret = 1, errno = 0;
  	data = (u_int64_t *) ptrace(PTRACE_PEEKDATA, tracee, addr, 0);
	if (errno) ret = 0;
	return ret;
}

/* Write memory to tracee's (child) address space. Write data into addr.*/
int set_memory(pid_t tracee, u_int64_t *addr, u_int64_t data)
{
	int ret = 0;

	if (ptrace(PTRACE_POKEDATA, tracee, addr, data) == 0){
		ret = 1;
	}

	return ret;
}