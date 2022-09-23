#ifndef __SSL_H_
#define __SSL_H_
#include <openssl/ssl.h> 
#include <openssl/err.h>
#include <openssl/rsa.h> 
#include <openssl/x509.h>
#include <openssl/evp.h>
#include <openssl/opensslv.h>

#include "types.h"
#include "bus_functions.h"
#include "dsm_statemachine.h"

#include "../log/log.h"

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile);
SSL_CTX* init_ctx_server(void);                      
void show_certs(SSL* ssl);                            

/* Generate the TLS framework used to secure the session. */                                   SSL_CTX* init_ctx_client(void); 

#endif
