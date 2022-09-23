#include <sys/socket.h>
#include <linux/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <curses.h>

#include "bus_functions.h"
#include "types.h"

#include "log.h"

extern int client_not_connected;

/* Generate the TLS framework used to secure this session. */                                                      
SSL_CTX* init_ctx_client(void){              
                                                      
    SSL_METHOD *method;                           
    SSL_CTX *ctx;                                 
                                                  
    OpenSSL_add_all_algorithms();            
    SSL_load_error_strings();                     
                                         
    /* Create new client method instance */       
    method = TLSv1_client_method();             
    ctx = SSL_CTX_new(method);                 
                                  
    if (!ctx){                                   
            log_error("TLS context couldn't be created. Aborting...");                                  
            abort();                              
    }                                             
                                                  
    return ctx;                                  
}

int create_server(int port){

	int sk, ret;
	struct sockaddr_in addr;

	sk = socket(PF_INET, SOCK_STREAM , IPPROTO_TCP);
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	setsockopt(sk, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

	ret = bind(sk, (struct sockaddr *)&addr, sizeof(addr));

	if (ret < 0) {
		errExit("Server bind failed");
		abort();
	}

	ret = listen(sk,16);

	if (ret < 0){
		errExit("Server listen failed");
		abort();
	}

	return sk;
}

int
prepare_server(int port, int *socket_fd)
{
	/* Socket related variables */
	int sk,ask;

	/* Create TCP server (listener) */
	sk = create_server(port); 
	
	log_info("Waiting for connections");

	ask = accept(sk, NULL, NULL);
	
	*socket_fd = ask;

	log_info("Connection established with client");

	client_not_connected = 0;

	return 1;
}
