#pragma once

#ifndef __TRACE_H__
#define __TRACE_H__

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h> 
#include <linux/limits.h>
#include "../log/log.h"
#include "dsm_statemachine.h"
#include "parasite.h"

enum status_binary {
    READY = 0,   /* Child ready to be run */
    RUNNING,     /* Child running */
    EXITED,      /* Child exited */
    SIGNALEXIT,  /* Child terminated with a signal */
    STOPPED,     /* Child is stopped */
    INTERRUPTED, /* Child was interrupted */
    UNKNOWN
};

static int status = UNKNOWN;

/* Binaries (traicees) should call this to enable DSM */
int start_tracing_me(void);

int attach_traicee(int pid);

/* Configuration options:
   - Trace all process control events (includes execve,clone,fork)
   - Kill the child if we exit for any reason
*/
int trace_process(int pid);

/* Read memory from tracee's (child) address space. Read addr to data. */
int get_memory(pid_t tracee, u_int64_t *addr, u_int64_t *data);

/* Write memory to tracee's (child) address space. Write data into addr.*/
int set_memory(pid_t tracee, u_int64_t *addr, u_int64_t data);

/* Wait for traicee state tu change and update status accordingly */
int wait_trace(int pid);

/* Is the process in a traceable state? */
int traceable(void);

/* Make traicee resume execution */
int resume(int pid);

/* Return 0 on success, 1 otherwise */
int initialize_ptrace(int pid);

#endif /* __TRACE_H__ */
