// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <openenclave/enclave.h>
#include <iostream>

#include "encryptor.h"
#include "fileencryptor_t.h"
#include "shared.h"

// Declare a static dispatcher object for enabling for better organization
// of enclave-wise global variables
static ecall_dispatcher dispatcher;

int initialize_encryptor(
    bool encrypt,
    const char* password,
    size_t password_len,
    encryption_header_t* header)
{
    return dispatcher.initialize(encrypt, password, password_len, header);
}

int encrypt_block(
    bool encrypt,
    unsigned char* input_buf,
    unsigned char* output_buf,
    size_t size)
{
    unsigned char output[100];
    int ret;

    ret =  dispatcher.encrypt_block(encrypt, input_buf, output_buf,100);
    strncpy((char*)output_buf,(const char*)output,size);
    
    return ret;
}

void close_encryptor()
{
    return dispatcher.close();
}
