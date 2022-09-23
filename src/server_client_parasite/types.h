#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>

#include <openssl/ssl.h> 
#include <openssl/err.h>
#include <openssl/rsa.h> 
#include <openssl/x509.h>
#include <openssl/evp.h>

#define _GNU_SOURCE

#define INPUT_CMD_LEN (30)
#define MAX_PAGES     (100)
#define WRITE_BUF_LEN (100)
#define READ_BUF_LEN  (100)

#define DEFAULT_PAGS_MAP (40)
#define UBIN_MAX (5000)
#define MAX_ARGS (20)

#define errExit(msg)    do { log_error("errExit:"); perror(msg); exit(EXIT_FAILURE); \
	} while (0)

int dsm_client;

enum dsm_tag
{
	VALID = 0,
	INVALID,
	NUM_TAGS
};

struct dsm_page
{
	enum dsm_tag tag;
	pthread_mutex_t mutex;
	void* heap_address; /* Child's heap address of this page */
	void* copy_address; /* Physical copy where to save the new values (if any) */
	void* heap_address_other; /* Heap of the other side - needed to update pointers */
	bool in_use;
};

struct bus_thread_args
{
	int fd;
	SSL* ssl;
	SSL_CTX* ctx;
	uint64_t memory_address;
	uint64_t len;
};

struct userfaultfd_thread_args
{
	int sk;
	SSL* ssl;
	SSL_CTX* ctx;
	uint64_t physical_address;
	long uffd;
};

typedef struct {

	char *uname;
	char *tname;
	char *signed_enc;
	pid_t pid;

} binary;

#endif
