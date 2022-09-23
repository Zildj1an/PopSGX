/*
 *	PopSGX trusted binary management.
 *	@author Carlos Bilbao
 *	bilbao [at] vt [dot] edu
 */
#ifndef __TRUST_H__
#define __TRUST_H__

#include <stdint.h>
#include <stdio.h>
#include <linux/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <sys/syscall.h>
#include <errno.h>
#include <fcntl.h>

#include "types.h"
#include "tls.h"

int pid_server_bin;

/* Start running the untrusted binary on the server side, with an extra thread
   that handles SIGUSR2, so that the server can request functions execution. 
 */
void prepare_trusted_side(binary* tbin);

int get_pid_server_binary();

#endif /* __TRUST_H_ */