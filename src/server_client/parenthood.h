#ifndef __PARENTHOOD_H__
#define __PARENTHOOD_H__

#include <linux/types.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#include "dsm_statemachine.h"
#include "types.h"

#define _GNU_SOURCE

/*
	Both client (untrusted.c) and server (trusted.c) have a child:
	- In the server, the child is a dummy host (wrapper) and the enclave.
	- In the client, the child is the host and the enclave is just a wrapper.
	In both cases childs request stuff to their parents:
		1. They send them their heap information.
		2. They ask them for pages when they page fault (parent syncrhonizes and sends via socket)
		3. They ask them for functions when they cannot execute them. In the case of the server,
		   these will be calls to the host, and in the client these will be calls to the enclave
		   (wrapped by eedgr8r).
*/
void prepare_parenthood(char *the_uname);

void set_child_pid(pid_t the_pid);
pid_t get_child_pid(void);

/* Save the func name and parameters for the untrusted bin on the server to
   read and execute 
*/
void prepare_func_call(char *func_name, unsigned long long *args, int argc);

int wait_func_call(void);

#endif /* __PARENTHOOD_H__ */
