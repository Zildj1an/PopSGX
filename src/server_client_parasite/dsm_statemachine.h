#ifndef __MSI_STATEMACHINE_H__
#define __MSI_STATEMACHINE_H__

#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "messages.h"
#include "tls.h"
#include "types.h"
#include "trusted.h"
#include "parenthood.h"
#include "bus_functions.h"

#include "../log/log.h"

static SSL *bin_ssl;

long unsigned int other_heap_addr,other_heap_length;
long unsigned int handle_dsm_fault(long unsigned int faulty_addr);

void update_ssl(SSL *ssl);

void notify_terminate_enclave(void);
void handle_terminate_enclave(void);

void update_dsm_pages(long unsigned int heap_addr, long unsigned int length);
void send_heap_info(long unsigned int heap_addr, long unsigned int length);
void handle_heap_info(SSL *ssl, struct dsm_message* in_msg);
void handle_heap_ack(struct dsm_message* in_msg);

void dsm_request_page(SSL *ssl, char* copy_page, long unsigned int fault_addr);
void dsm_handle_page_request(SSL *ssl, struct dsm_message* in_msg);
void dsm_handle_page_invalidate (SSL *ssl, struct dsm_message* in_msg);
struct dsm_page* find_dsm_page(long unsigned int fault_addr);
void dsm_handle_page_reply(SSL *ssl, struct dsm_message* in_msg);

void dsm_send_binary(SSL *ssl, binary *the_ubin);
void dsm_handle_binary(SSL *ssl, struct dsm_message* in_msg);

void send_call_request(char *request,int num_args, long int *args);

void handle_call_request(SSL *ssl, struct dsm_message* in_msg);
void handle_call_reply(struct dsm_message* in_msg);
void dsm_handle_page_invalidate_ack(void);

#endif
