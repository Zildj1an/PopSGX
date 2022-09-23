#include "dsm_statemachine.h"

extern struct dsm_page pages[];
extern pthread_mutex_t bus_lock;

int waiting_for_page_reply = 0;
pthread_cond_t page_reply_cond  = PTHREAD_COND_INITIALIZER;
char global_data_buffer[4096];

extern binary ubin;
extern int client_has_untrusted;

/* Parenthood stuff */
extern long unsigned int waiting_func_reply, result_func_reply;
extern long int heap_offset;

void update_ssl(SSL *ssl)
{
	bin_ssl = ssl;
}

void notify_terminate_enclave(void)
{
	pthread_mutex_lock(&bus_lock);
	struct dsm_message msg;
	int write_ret;

	msg.message_type = TERMINATE_ENCLAVE;

	abort_all_bus_messages();

	write_ret = SSL_write(bin_ssl, &msg, sizeof(msg));

	if (write_ret <= 0) {
		errExit("Bad write on invalidate page");
	}	

	pthread_mutex_unlock(&bus_lock);
}

void handle_terminate_enclave(void)
{
	pid_t pid;
	int write_ret, func_result;
	const char *func_name = "oe_terminate_enclave";

	log_info("Client done, time to terminate.");

	/* Call the function and send parameters */
	pid = get_child_pid();

	/* Save func, params and heap offset to the child's file */
	prepare_func_call(func_name,0,0);

	/* Send signal to the client binary running on the server */
	if ((write_ret = kill(pid,SIGUSR2)) < 0){
		errExit("kill in server failed");
	}

	/* Wait for the signal to be handled. */
	func_result = wait_func_call();

	/* Kill the children, we are done here. */
	if ((write_ret = kill(pid,SIGKILL)) < 0){
		errExit("kill in server (to finish) failed");
	}

	exit(EXIT_SUCCESS);
}

void update_dsm_pages_heap(long unsigned int heap_addr, long unsigned int length)
{
	register int i;
	int page_size = sysconf(_SC_PAGE_SIZE);

	for(i = 0; i < DEFAULT_PAGS_MAP; ++i, heap_addr += page_size)
	{
		pages[i].heap_address_other = (void*) heap_addr;
	}	

	if (pages[0].heap_address){
		heap_offset = pages[0].heap_address - pages[0].heap_address_other; 
		//printf("Heap offset: 0x%lx - 0x%lx = %ld\n",
		//	(long unsigned int)pages[0].heap_address,
		//	(long unsigned int)pages[0].heap_address_other,heap_offset);
	}
}

void update_dsm_pages(long unsigned int heap_addr, long unsigned int length)
{
	register int i;
	int page_size = sysconf(_SC_PAGE_SIZE);

	for(i = 0; i < DEFAULT_PAGS_MAP; ++i, heap_addr += page_size)
	{
		pages[i].heap_address = (void*) heap_addr;
	}
	
	if (pages[0].heap_address && pages[0].heap_address_other && !heap_offset){
		heap_offset = pages[0].heap_address - pages[0].heap_address_other; 
		printf("Heap offset: 0x%lx - 0x%lx = %ld\n",
			(long unsigned int)pages[0].heap_address,
			(long unsigned int)pages[0].heap_address_other,heap_offset);
	}
}

/* Invalidate page on the other side */
static void __invalidate_page(struct dsm_page* page)
{
	pthread_mutex_lock(&bus_lock);
	struct dsm_message msg;
	int write_ret;

	msg.message_type = INVALIDATE;
	msg.payload.invalidate_page.address = (uint64_t)page->heap_address_other;
	
	waiting_func_reply = 1;

	write_ret = SSL_write(bin_ssl, &msg, sizeof(msg));

	if (write_ret <= 0) {
		errExit("Bad write on invalidate page");
	}	

	pthread_mutex_unlock(&bus_lock);
}

long unsigned int handle_dsm_fault(long unsigned int faulty_addr)
{
	int write_ret;
	struct dsm_page* page_to_transition = find_dsm_page(faulty_addr);
	
	if (!page_to_transition){
		errExit("Unable to find page on handle dsm fault\n");
	}	

	switch (page_to_transition->tag){
	case VALID:
		/* Make other side invalidate this page */
		__invalidate_page(page_to_transition);
	break;
	case INVALID:
		/* On handling request, other side must invalidate its page 
		   and find the page using heap_address_other.
		*/
		dsm_request_page(bin_ssl,page_to_transition->copy_address,faulty_addr);	
		page_to_transition->in_use = true;
	break;
	default:
		errExit("Page with unknown tag");	
	break;
	}

	return (long unsigned int) page_to_transition->copy_address;
}

void send_heap_info(long unsigned int heap_addr, long unsigned int length)
{
	int write_ret;
	struct dsm_message msg;

	pthread_mutex_lock(&bus_lock);

	msg.message_type                = SEND_HEAP_INFO;
	msg.payload.heap_info.heap_addr = heap_addr;
	msg.payload.heap_info.length    = length;

	if (!bin_ssl){
		errExit("SSL not initialized");
	}

	write_ret = SSL_write(bin_ssl, &msg , sizeof(msg));
	
	if (write_ret <= 0) {
		errExit("Sending heap info failed...");
	}

	pthread_mutex_unlock(&bus_lock);
}

/* Save heap info of the other side and ACK reception */
void handle_heap_info(SSL *ssl, struct dsm_message* in_msg)
{
	int write_ret;
	struct dsm_message msg_out;

	/* Save the other's side child's heap info */
	other_heap_addr   = in_msg->payload.heap_info.heap_addr;
	other_heap_length = in_msg->payload.heap_info.length;

	update_dsm_pages_heap(other_heap_addr, other_heap_length);

	/* ACK the other side of heap info reception */
	pthread_mutex_lock(&bus_lock);
	
	msg_out.message_type = HEAP_INFO_ACK;

	write_ret = SSL_write(ssl, &msg_out , sizeof(msg_out));
	
	if (write_ret <= 0) {
		errExit("Sending heap ack failed...");
	}

	pthread_mutex_unlock(&bus_lock);
}

void handle_heap_ack(struct dsm_message* in_msg)
{
	log_debug("Other side acked heap reception");
	waiting_func_reply = 0;
}

struct dsm_page* find_dsm_page(long unsigned int fault_addr)
{
	struct dsm_page* page = NULL;
	uint64_t addr_val = (uint64_t)fault_addr;
	int iterator = 0;

	for (iterator = 0; iterator < DEFAULT_PAGS_MAP; ++iterator){
		if ((uint64_t)pages[iterator].heap_address + sysconf(_SC_PAGE_SIZE) >= addr_val){
			page = &pages[iterator];
			break;
		}
	}

	return page;
}

struct dsm_page* find_dsm_page_other(long unsigned int fault_addr)
{
	struct dsm_page* page = NULL;
	uint64_t addr_val = (uint64_t)fault_addr;
	int iterator = 0;

	for (iterator = 0; iterator < DEFAULT_PAGS_MAP; ++iterator){
	
		//printf("Testing page %i - %lx\n",iterator,(uint64_t)pages[iterator].heap_address_other);

		if ((uint64_t)pages[iterator].heap_address_other + sysconf(_SC_PAGE_SIZE) >= addr_val){
			page  = &pages[iterator];
			break;
		}
	}

	return page;
}

void dsm_request_page(SSL *ssl, char* copy_page, long unsigned int fault_addr)
{
	int write_ret;
	struct dsm_message msg;
	pthread_mutex_lock(&bus_lock);
	struct dsm_page* page_to_transition = find_dsm_page(fault_addr);
	
	if (!page_to_transition){
		errExit("Unable to find page on dsm_request_page\n");
	}

	pthread_mutex_lock(&page_to_transition->mutex);

	/* If we are invalid, we need to get data from other node */
	/* Populate Message fields before sending */
	msg.message_type = INVALID_STATE_READ;
	msg.payload.request_page.address = (uint64_t)fault_addr;
	msg.payload.request_page.size = sysconf(_SC_PAGE_SIZE);

	waiting_for_page_reply = 1;
	
	write_ret = SSL_write(ssl, &msg , sizeof(msg));

	if (write_ret <= 0) {
		goto out_bad;
	}

	/* Use condition variable to wait for bus thread to
	 * reply with copy_page data
	 */
	memset(&global_data_buffer, 0, 4096);

	/* Wait for reply */
	while (waiting_for_page_reply){
		pthread_cond_wait(&page_reply_cond, &bus_lock);
	}

	memcpy(copy_page, &global_data_buffer, sysconf(_SC_PAGE_SIZE));
	page_to_transition->tag = VALID;
	goto out_good;

out_good:
	pthread_mutex_unlock(&bus_lock);
	pthread_mutex_unlock(&page_to_transition->mutex);
	return;
out_bad:
	pthread_mutex_unlock(&page_to_transition->mutex);
	errExit("request_page_failed");
}

void dsm_handle_page_request(SSL *ssl, struct dsm_message* in_msg)
{
	int write_ret;
	struct dsm_message msg_out;

	/* Find the page we're concerned about */
	struct dsm_page* page_to_transition =
		find_dsm_page_other(in_msg->payload.request_page.address);

	if (!page_to_transition){
		errExit("Unable to find page on handle page request\n");
	}

	msg_out.message_type = PAGE_REPLY;

	/*If I'm invalid too, then I'll give you an empty page */
	if (page_to_transition->tag == INVALID) {
		memset(msg_out.payload.page_data, 0, sysconf(_SC_PAGE_SIZE));
	}
	else {
		if (4096 < sysconf(_SC_PAGE_SIZE)){
			errExit("4096 is not enough for page_data[]");
		}
		/* Else I'll give you my local memory storage, won't trigger
		 * pagefault since it's already been edited anyway 
		*/
		memcpy(msg_out.payload.page_data, 
			   page_to_transition->copy_address,
			   sysconf(_SC_PAGE_SIZE));
	}

	pthread_mutex_lock(&page_to_transition->mutex);
	
	write_ret = SSL_write(ssl, &msg_out, sizeof(msg_out));
	
	if (write_ret <= 0) {
		goto out_bad;
	}
	
	log_debug("Page %p invalidated",page_to_transition->heap_address);	
	page_to_transition->tag = INVALID; // Child needs to madvise heap_address (MADV_DONTNEED)

	goto out_good;

out_bad:
	pthread_mutex_unlock(&page_to_transition->mutex);
	errExit("handle_page_request_error");
out_good:
	pthread_mutex_unlock(&page_to_transition->mutex);
	return;
}

void dsm_handle_page_invalidate(SSL *ssl, struct dsm_message* in_msg)
{
	int write_ret;
	struct dsm_message msg;

	/* Find the page we're concerned about */
	struct dsm_page* page_to_transition =
		find_dsm_page(in_msg->payload.invalidate_page.address);

	if (!page_to_transition){
		errExit("Unable to find page to invalidate\n");
	}

	pthread_mutex_lock(&page_to_transition->mutex);

	page_to_transition->tag = INVALID;

	/* Is this page even mapped yet? */
	if (page_to_transition->in_use){
		if (madvise(page_to_transition->heap_address, sysconf(_SC_PAGE_SIZE), MADV_DONTNEED)) {
			errExit("fail to madvise");
		}
	}

	page_to_transition->in_use = false;
	
	log_debug("Page %p invalidated",page_to_transition->heap_address);
	msg.message_type = INVALIDATE_ACK;

	/* Ignore payload for now until we add error handling */
	write_ret = SSL_write(ssl, &msg, sizeof(msg));

	if (write_ret <= 0) {
		errExit("page_invalidate_failed");
	}

	pthread_mutex_unlock(&page_to_transition->mutex);
}

void dsm_handle_page_reply(SSL *ssl, struct dsm_message* in_msg)
{
	pthread_mutex_lock(&bus_lock);
	memcpy(&global_data_buffer, in_msg->payload.page_data,sysconf(_SC_PAGE_SIZE));

	waiting_for_page_reply = 0;
	/* Signal condition variable that we are ready */
	pthread_cond_signal(&page_reply_cond);
	pthread_mutex_unlock(&bus_lock);
}

void dsm_send_binary(SSL *ssl, binary *the_ubin)
{
	int write_ret,iteration = 0, size,total = 0;
	struct dsm_message msg;
	FILE *bin_file;
	char ch, enclave_image[INPUT_CMD_LEN];

	pthread_mutex_lock(&bus_lock);

	/* Populate Message fields before sending */
	msg.message_type = SEND_UBIN;
	strcpy(msg.payload.ubin_info.ubin_name,the_ubin->uname);
	strcpy(msg.payload.ubin_info.image_name,the_ubin->signed_enc);

	bin_file = fopen(the_ubin->uname,"rb");

	if (!bin_file)
		errExit("error opening bin file");

	/* Get binary size */
	fseek(bin_file, 0L, SEEK_END);
	size = ftell(bin_file);
	fseek(bin_file, 0L, SEEK_SET);

	/* We don't send the entire binary in one packet, we send chunk by chunk */
	for (; iteration * UBIN_MAX < size; iteration++){
		
		msg.payload.ubin_info.ubin_size = 0;

		while (total < size && msg.payload.ubin_info.ubin_size < UBIN_MAX - 1){
      			ch = fgetc(bin_file);
			msg.payload.ubin_info.ubin_contents[msg.payload.ubin_info.ubin_size++] = ch;
			total++;
		}

		write_ret = SSL_write(ssl, &msg , sizeof(msg));

		if (write_ret <= 0) {
			goto out_bad;
		}
	}
	
	msg.payload.ubin_info.ubin_size = 0;

	/* Is there any data left? */
	while (total < size && msg.payload.ubin_info.ubin_size < UBIN_MAX){
      		ch = getc(bin_file);
		msg.payload.ubin_info.ubin_contents[msg.payload.ubin_info.ubin_size++] = ch;
		total++;
	}

	if (msg.payload.ubin_info.ubin_size) {

		write_ret = SSL_write(ssl, &msg , sizeof(msg));

		if (write_ret <= 0) {
			goto out_bad;
		}
	}

	pthread_mutex_unlock(&bus_lock);
	fclose(bin_file);

	return;
out_bad:
	errExit("send ubin failed");
}

void dsm_handle_binary(SSL *ssl, struct dsm_message* in_msg)
{
	static int first = 1;
	int write_ret, retry = 1;
	struct dsm_message msg;
	FILE *bin_file;
	char *command = calloc(100,1);
	int virtual_assistant = 0;

	if (strlen(in_msg->payload.ubin_info.ubin_name) > INPUT_CMD_LEN){
		errExit("File name is too big");
	}

	ubin.uname = malloc(strlen(in_msg->payload.ubin_info.ubin_name) + 3);
	sprintf(ubin.uname, "%sbin",in_msg->payload.ubin_info.ubin_name);
	
	if (first) {
		
		ubin.signed_enc = malloc(strlen(in_msg->payload.ubin_info.image_name));
		sprintf(ubin.signed_enc,"%s",in_msg->payload.ubin_info.image_name);
		printf("\n");
		if (!strcmp(ubin.uname,"virtual-assistanthostbin5")){
			sprintf(ubin.uname,"%s","virtual-assistanthostbin");
			virtual_assistant = 1;
		}
		bin_ssl = ssl;
	}

	/* Remove the file if it was already there */
	if (first) {
		remove(ubin.uname);
	}

	client_has_untrusted = 1;

retry_bin:

	/* We might be iterating */
	bin_file = fopen(ubin.uname,"ab");

	if (!bin_file){
		if (errno == ETXTBSY){
			if (retry){	
				fprintf(stderr,"Binary file busy, retrying...\n");
				retry = 0;
			}
			goto retry_bin;
		}
		errExit("error opening bin file");
	}

	fwrite(in_msg->payload.ubin_info.ubin_contents,1,
	       in_msg->payload.ubin_info.ubin_size,bin_file);
	fclose(bin_file);

	/* Make the binary executable */
	if (first && virtual_assistant){
		sprintf(command, "chmod +x virtual-assistanthostbin  ");
	}
	else if (first){
		sprintf(command,"chmod +x %s  ",ubin.uname);
	}
	
	if ((write_ret = system(command)) == -1){
		errExit("adding execute privilege to binary");
	}	

	// TODO ACK

	first = 0;
}

void send_call_request(char *request,int num_args, long int *args)
{
	int write_ret, i = 0;
	struct dsm_message msg;

	pthread_mutex_lock(&bus_lock);

	/* Populate Message fields before sending */
	msg.message_type = CALL_REQUEST;
	strcpy(msg.payload.call_request.func_name,request);

	/* Arguments of the function */
	msg.payload.call_request.num_args = num_args;

	for (; i < num_args && i < MAX_ARGS; ++i){
		msg.payload.call_request.args[i] = args[i];
	}

	write_ret = SSL_write(bin_ssl, &msg , sizeof(msg));

	if (write_ret <= 0) {		
		errExit("could not send call request");
	}

	pthread_mutex_unlock(&bus_lock);
}

void handle_call_request(SSL *ssl, struct dsm_message* in_msg)
{
	int write_ret, i = 0, num_args,pid;
	struct dsm_message msg;
	unsigned long long *args;
	int func_result;

	/* Retrieve arguments and cast them back */
	num_args = in_msg->payload.call_request.num_args;	
	args = malloc(sizeof(unsigned long int) * num_args);	

	for (; i < num_args; ++i){
		args[i] = in_msg->payload.call_request.args[i];
	}

	/* Call the function and send parameters */
	pid = get_child_pid();

	/* Save func, params and heap offset to the child's file */
	prepare_func_call(in_msg->payload.call_request.func_name,args,num_args);

	/* Send signal to the client binary running on the server */
	if ((write_ret = kill(pid,SIGUSR2)) < 0){
		errExit("kill in server failed");
	}

	/* Wait for the signal to be handled. */
	func_result = wait_func_call();

	/* Return results */
	log_debug("Sending results back...");
	
	pthread_mutex_lock(&bus_lock);

	/* Populate Message fields before sending */
	msg.message_type = CALL_REPLY;

	strcpy(msg.payload.call_request.func_name,
		in_msg->payload.call_request.func_name);

	msg.payload.call_request.result = func_result;

	write_ret = SSL_write(ssl, &msg , sizeof(msg));

	if (write_ret <= 0) {		
		errExit("could not send call reply");
	}

	pthread_mutex_unlock(&bus_lock);
}

void handle_call_reply(struct dsm_message* in_msg)
{
	// TODO get return values
	log_debug("Results %s() received (result %d).",
		 in_msg->payload.call_request.func_name,in_msg->payload.call_request.result);

	waiting_func_reply = 0;
	result_func_reply = in_msg->payload.call_request.result;
} 

void dsm_handle_page_invalidate_ack(void)
{
	//log_debug("Page invalidation ack received");
}
