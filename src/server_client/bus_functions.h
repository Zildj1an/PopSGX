#ifndef __BUS_FUNCTIONS_H__
#define __BUS_FUNCTIONS_H__
#include "messages.h"
#include "types.h"
#include <sys/socket.h>
#include <linux/types.h>
#include <arpa/inet.h>
#include <sys/wait.h>

SSL* setup_server(int port, struct bus_thread_args* arg_output, int *socket_fd, SSL_CTX *ctx);

SSL* try_connect_client(int port, char* ip_string, struct
			      bus_thread_args* arg_output, int *socket_fd, SSL_CTX *ctx);

void* bus_thread_handler(void* arg);

void abort_all_bus_messages(void);

#endif /* __BUS_FUNCTIONS_H__ */
