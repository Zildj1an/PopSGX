#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <linux/userfaultfd.h>
#include <sys/syscall.h>
#include <linux/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <poll.h>
#include "messages.h"
#include "types.h"
#include "bus_functions.h"
#include "untrusted.h"
#include "trusted.h"

#include "../log/log.h"

#define MAX_NUM_ARGS		(3)

const char *DEFAULT_PORT_SERVER = "2000";
char* DEFAULT_IP_STRING = "localhost";
//char* DEFAULT_IP_STRING = "10.0.2.15";
char* dsm_strings[NUM_TAGS] = {"VALID", "INVALID"};

/* Global page array */
struct dsm_page pages[DEFAULT_PAGS_MAP];

/* Global PopSGX params */
int client_has_untrusted, client_not_connected;
binary ubin;

static void initialize_dsm_pages(uint64_t phy_addr)
{
	int i, page_size = sysconf(_SC_PAGE_SIZE);

	for(i = 0; i < DEFAULT_PAGS_MAP; ++i, phy_addr += page_size)
	{
		pages[i].tag           = VALID;
		pages[i].in_use        = false;
		pages[i].heap_address  = NULL;
		pages[i].copy_address  = (void*)phy_addr;
		pthread_mutex_init(&pages[i].mutex, NULL);
	}
}

static void handle_dsm_status_command(void)
{
	char cmd_buffer[INPUT_CMD_LEN] = {0};
	unsigned long page_num;
	unsigned long iterator;

	printf("\nWhat page would you like to view status of? (0 to N-1 or i): ");
	if (!fgets(cmd_buffer, INPUT_CMD_LEN, stdin))
		errExit("fgets error");

	page_num = strtoul(cmd_buffer, NULL, 0);
	if (!strncmp(cmd_buffer, "i", 1)){
		for (iterator = 0; iterator < DEFAULT_PAGS_MAP; ++iterator) {
			log_info("[*]Page %lu: %s ", iterator,
			       dsm_strings[pages[iterator].tag]);
		}
	}
	else if (page_num < DEFAULT_PAGS_MAP) {
		log_info("[*]Page %lu: %s ", page_num,
			       dsm_strings[pages[page_num].tag]);
	}
}

int
main(int argc, char *argv[])
{
	SSL* ssl;
	SSL_CTX* ctx;
	int socket_fd,opt;
	char fgets_buffer[100], binary[2] = "-b";

	/* Bus thread related */
	struct bus_thread_args bus_args;
	pthread_t bus_thread;
	int bus_thread_ret,prepared_server = 0;
	/* Message */
	struct dsm_message msg;

	int exit_write_ret;
	char bin_name[40];
	int bin_name_recv = 0;

	/* DSM */
	void* physical_address;

	while ((opt = getopt(argc,argv, "hrb")) != -1){
		switch(opt){
			case 'h':
help_msg:
				log_info("Usage for client or server: ./popsgx");
				log_info("Server can also do: ./popsgx -b <bin name>");
				log_info("Do ./popsgx -h to see this help message.");
				exit(EXIT_SUCCESS);
				break;
			case 'b':
				strcpy(bin_name,argv[2]);
				bin_name_recv = 1;
				break;
			default:
				log_error("Unknown option!");
				goto help_msg;
		}
	}

	SSL_library_init();

	/* Create client first and try to connect. If other server doesn't
	 * exist, then we are the first node. Else, we are the second node. 
	*/
	ssl = try_connect_client(atoi(DEFAULT_PORT_SERVER), 
				 DEFAULT_IP_STRING, &bus_args,&socket_fd, ctx);

	/*
	  Create a new mapping in the virtual address space, giving physical_region
	  the starting address. Our pages might be read, write or executed.
	*/
	physical_address = mmap(NULL, DEFAULT_PAGS_MAP * sysconf(_SC_PAGE_SIZE), 
		PROT_READ | PROT_WRITE | PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (physical_address == MAP_FAILED)
		errExit("mmap");
	
        memset(physical_address, 0, DEFAULT_PAGS_MAP * sysconf(_SC_PAGE_SIZE));
	initialize_dsm_pages((uint64_t)physical_address);

	if (ssl){
		dsm_client = 1;
		client_has_untrusted = 0;

	} else {
		dsm_client = 0;
		client_not_connected = 1;
		/* There is no server to connect to so we set up ourselves as the server*/
		ssl = setup_server(atoi(DEFAULT_PORT_SERVER), &bus_args,&socket_fd,ctx);
		update_ssl(ssl);
	}

	bus_thread_ret = pthread_create(&bus_thread, NULL,
                                        bus_thread_handler,
                                        (void *) &bus_args);
       if (bus_thread_ret != 0) {
               errno = bus_thread_ret;
               errExit("pthread_create");
       }

       if (!dsm_client){
		while (client_not_connected){
			sleep(0.35);
		}
		log_info("Sending ubinary %s...",bin_name);
		send_untrusted(ssl,&ubin,bin_name,bin_name_recv);
		prepare_trusted_side(&ubin);
		prepared_server = 1;
	}	

	/* Prompt User for Command */
	for(;;) {
		
		printf("\nWhat would you like to do? Manage (s)gx/E(x)it?: ");
	
read_command:	if (!fgets(fgets_buffer, INPUT_CMD_LEN, stdin))
			errExit("fgets error");

		if (!strncmp(fgets_buffer, "x", 1)){
			pthread_cancel(bus_thread);
			msg.message_type = DISCONNECT;
			exit_write_ret = SSL_write(ssl, &msg, sizeof(msg));
			if (exit_write_ret <= 0) {
				errExit("Exit Write Error");
			}
			goto exit_success;
		}
		else if (!strncmp(fgets_buffer, "v", 1)){
			handle_dsm_status_command();
		}
		else if (!strncmp(fgets_buffer, "s",1)){
			if (dsm_client){
				if (!client_has_untrusted){
					log_error("Client does not have the untrusted code.");
				}
				else {
					run_untrusted(&ubin);
					exit(EXIT_SUCCESS);
				}
			}
			else {
				log_info("Server is just waiting for the client...\n");
			}
		}
		else if (!strncmp(fgets_buffer, "\n",1)){
			goto read_command;
		}
	}

exit_success:
	log_info("EXITING");
	exit(EXIT_SUCCESS);
}
