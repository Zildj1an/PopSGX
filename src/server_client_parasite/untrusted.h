/*
 * Handle of the untrusted binary.
 * author Carlos Bilbao bilbao {at} vt.edu
*/
#pragma once
#ifndef __UNTRUST_H__
#define __UNTRUST_H__

#include <stdint.h>
#include <stdio.h>
#include <linux/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <sys/syscall.h>
#include <errno.h>
#include <string.h>
#include "../log/log.h"
#include "types.h"
#include "tls.h"
#include "dsm_statemachine.h"
#include "ptrace.h"

/* Generate trusted and untrusted code */
void send_untrusted(SSL *ssl,binary* ubin,char *name_bin, int got_name);

/* Run host code from the client */
void run_untrusted(binary* ubin);

#endif /* __UNTRUST_H_ */
