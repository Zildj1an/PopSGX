#pragma once

#ifndef __PARASITE_H__
#define __PARASITE_H__

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

#include <compel/compel.h>
#include <compel/infect.h>

#include "../log/log.h"
#include "dsm_statemachine.h"

/* Returns 1 on success, 0 otherwise */
int parasite_initialize(int pid);

#endif /* __PARASITE_H__ */
