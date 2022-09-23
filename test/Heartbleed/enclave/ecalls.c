#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#include "Heartbleed_t.h"

static int data_size;
uint8_t buf2[500];

/* Restore data (w/o Heartbleed memory overwrite with sensitive stuff) */
oe_result_t enclave_restore_protected_data(uint8_t *data)
{
    strcpy(data,buf2);

    return OE_OK;
}

/* Backup  data */
oe_result_t enclave_protect_data(uint8_t *data)
{
    //*buf2 = malloc(sizeof(data));
    strcpy(buf2,data);

    return OE_OK;
}
