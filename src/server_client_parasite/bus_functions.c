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
#include "dsm_statemachine.h"
#include "types.h"
#include "tls.h"

#include "../log/log.h"

extern struct dsm_page pages[];
pthread_mutex_t bus_lock = PTHREAD_MUTEX_INITIALIZER;

extern int client_not_connected;
static int abort_bus;

void bus_thread_cleanup_handler(void* arg)
{
	/* Close out the SSL sockets so we don't have loose ends */
	struct bus_thread_args* bus_args = (struct bus_thread_args*)arg;
	int sk = bus_args->fd;
	SSL_CTX *ctx = bus_args->ctx;
	SSL *ssl = bus_args->ssl;

	/* Ensure it's not stdin/out/err */
	log_info("Cleanup handler called: %d", sk);

	if (sk >= 2){
		close(sk);
		SSL_free(ssl);
		SSL_CTX_free(ctx);
	}
}

void abort_all_bus_messages(void)
{
	abort_bus = 1;
}

void* bus_thread_handler(void* arg)
{
	int rd;
	struct dsm_message msg;
	struct bus_thread_args* bus_args = arg;

	if (!bus_args)
		errExit("Null Pointer");

	/* In case of thread cancellation, execute this handler */
	pthread_cleanup_push(bus_thread_cleanup_handler, &bus_args);

	/* Main Event Loop for the bus*/
	for(;;) {
		if (abort_bus) break;
		rd = SSL_read(bus_args->ssl, &msg, sizeof(msg));
		
		if (rd < 0)
			errExit("Read Error");
		
		switch(msg.message_type){
			case DISCONNECT:
				SSL_free(bus_args->ssl);
				SSL_CTX_free(bus_args->ctx);
				close(bus_args->fd);
				if (dsm_client){
					log_warn("\n The server closed the connection.");
					abort();
				}
				return NULL;
			case INVALID_STATE_READ:
				dsm_handle_page_request(bus_args->ssl, &msg);
			break;
			case INVALIDATE:
				dsm_handle_page_invalidate(bus_args->ssl, &msg);
			break;
			case PAGE_REPLY:
				dsm_handle_page_reply(bus_args->ssl, &msg);
			break;
			case INVALIDATE_ACK:
				dsm_handle_page_invalidate_ack();
			break;
			case SEND_UBIN:
				dsm_handle_binary(bus_args->ssl,&msg);
			break;
			case CALL_REQUEST:
				handle_call_request(bus_args->ssl,&msg);
			break;
			case CALL_REPLY:
				handle_call_reply(&msg);
			break;
			case SEND_HEAP_INFO:
				handle_heap_info(bus_args->ssl,&msg);
			break;
			case HEAP_INFO_ACK:
				handle_heap_ack(&msg);
			break;
			case TERMINATE_ENCLAVE:
				handle_terminate_enclave();
			break;
			default:
				log_error("Unhandled bus request, %d",msg.message_type);
				errExit("");
			break;
		}
	}

	/* Cleanup pop 0 argument means we don't execute the handler in normal
	 * exit, which is true since we will never exit here anyway*/
	pthread_cleanup_pop(0);
	return NULL;
}

int create_server(int port){

	int sk, ret;
	struct sockaddr_in addr;

	abort_bus = 0;

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

SSL* setup_server(int port, struct bus_thread_args* arg_output, int *socket_fd, SSL_CTX *ctx)
{
	/* Socket related variables */
	int sk,ask,len;
	/* mmap related */
	char command[INPUT_CMD_LEN];
	int page_size, write_ret;
	void* mmap_ptr;
	unsigned long num_pages = DEFAULT_PAGS_MAP;
	struct dsm_message msg;
	SSL *ssl;

	ctx = init_ctx_server();

	/* Load certificates */
	LoadCertificates(ctx,"mycert.pem","mycert.pem");

	/* Create TCP server (listener) */
	sk = create_server(port); 
	
	log_info("Waiting for connections");

	ask = accept(sk, NULL, NULL);
	ssl = SSL_new(ctx);
        SSL_set_fd(ssl,ask);

	if (ask < 0) {
		log_error("Server accept failed");
	}
	
	*socket_fd = ask;

	/* Accept TLS connection */
	if (SSL_accept(ssl) < 0){
		errExit("Server SSL/TLS accept failed");
	}

	log_info("Connection established with client");

	client_not_connected = 0;

	/* Populate Message fields before sending */
	msg.message_type = CONNECTION_ESTABLISHED;
	msg.payload.memory_pair.address = (uint64_t)mmap_ptr;
	msg.payload.memory_pair.size = len;

	write_ret = SSL_write(ssl, &msg , sizeof(msg));

	if (write_ret <= 0) {
		errExit("Server initial write error");
	}

	/* Populate argument fields for worker thread */
	arg_output->fd = ask;
	arg_output->ssl = ssl;
	arg_output->ctx = ctx;
	arg_output->memory_address = (uint64_t)mmap_ptr;
	arg_output->len = len;

	/* We've paired, no longer any need for sk */
	close(sk);

	return ssl;
}

int connect_to_server(int port, char *ip_string)
{
	int sk = 0, err = 0;
	struct sockaddr_in addr;

	sk = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	log_info("Connecting to %s:%d", ip_string, port);
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	err = inet_aton(ip_string, &addr.sin_addr);

	if (err < 0) goto out_close_socket;

	addr.sin_port = htons(port);
	err = connect(sk, (struct sockaddr *)&addr, sizeof(addr));

	if (err < 0) goto out_close_socket;

	return sk;

out_close_socket:
	close(sk);
	return -1;
}

SSL* try_connect_client(int port, char* ip_string, struct
			      bus_thread_args* arg_output, int *socket_fd, SSL_CTX* ctx)
{
	int sk = 0,rd;
	SSL *ssl;

	struct dsm_message msg, reply_msg;

	sk = connect_to_server(port,ip_string);

	if (sk < 0) {
		goto out_socket_err;
	}

	*socket_fd = sk;

	ctx = init_ctx_client();
	ssl = SSL_new(ctx);
	SSL_set_fd(ssl,sk); /* Attach the socket descriptor */

	if (SSL_connect(ssl) == -1){
		log_error("SSL connection failed.");
		goto out_and_close_socket;
	}

	show_certs(ssl);

	/* Initial pairing read to establish memory region */
	log_info("Awaiting pairing request...");

	/* Read and decrypt */
	rd = SSL_read(ssl, &msg, sizeof(msg));

	if (rd < 0)
		errExit("Read Error");
	
	//if (msg.message_type == CONNECTION_ESTABLISHED) {
		//log_info("Pairing Request : Addr: 0x%lx, Length: %lu"
		  //     ,msg.payload.memory_pair.address,
		    //   msg.payload.memory_pair.size);
	//}

	/* Output the socket fd */
	arg_output->fd = sk;

	/* Output the SSL connection and context*/
	arg_output->ssl = ssl;
	arg_output->ctx = ctx;

	/* Return the SSL connection if we successfully connect to it*/
	return ssl;

out_and_close_socket:
	close(sk);
out_socket_err:
	return NULL;
}
