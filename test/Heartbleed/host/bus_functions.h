#ifndef __BUS_FUNCTIONS_H__
#define __BUS_FUNCTIONS_H__
#include "messages.h"
#include "types.h"
#include "tls.h"
#include <sys/socket.h>
#include <linux/types.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int prepare_server(int port, int *socket_fd);

#endif /* __BUS_FUNCTIONS_H__ */
