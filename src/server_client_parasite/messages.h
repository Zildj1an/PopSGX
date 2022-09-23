#ifndef __MESSAGES_H__
#define __MESSAGES_H__
#include <stdint.h>

#include "types.h"

enum dsm_message_type
{
	CONNECTION_ESTABLISHED = 0,
	DISCONNECT,
	INVALID_STATE_READ,
	PAGE_REPLY,
	INVALIDATE,
	INVALIDATE_ACK,
	SEND_UBIN,
	CALL_REQUEST,
	CALL_REPLY,
	SEND_HEAP_INFO,
	HEAP_INFO_ACK,
	TERMINATE_ENCLAVE,
	TOTAL_MESSAGES
};
/* Different types of payloads defined here*/
struct memory_pair
{
	uint64_t address;
	uint64_t size;
};

struct command_ack
{
	int err;
};

struct request_page
{
	uint64_t address;
	uint64_t size;
};

struct heap_info 
{
	uint64_t heap_addr;
	uint64_t length;
};

struct invalidate_page
{
	uint64_t address;
};

struct ubin_info
{
	/* Binary specific */
	char ubin_name[INPUT_CMD_LEN + 2];
	char image_name[INPUT_CMD_LEN + 2];
	char ubin_contents[UBIN_MAX];
	int ubin_size;	
};

struct call_request
{
	char func_name[40];
	int num_args;
	long int args[MAX_ARGS];
	int result;
};

/* Message payload and its structure */
union message_payload
{
	/* DSM specific */
	struct memory_pair memory_pair;
	struct command_ack command_ack;
	struct request_page request_page;
	struct invalidate_page invalidate_page;

	/* Binary stuff */
	struct ubin_info ubin_info;

	/* Call request */
	struct call_request call_request;

	/* Heap specific info (DSM) */
	struct heap_info heap_info;

	char page_data[4096];
};

struct dsm_message
{	
	enum dsm_message_type message_type;
	union message_payload payload;
};

//struct dsm_page_data_payload
//{
//	enum dsm_message_type message_type;
//	char payload[4096];
//};

#endif
