#ifndef __SSL_H_
#define __SSL_H_
#include "openssl/ssl.h" 
#include "openssl/err.h"
#include "openssl/rsa.h"
#include "openssl/x509.h"
#include "openssl/evp.h"
#include "openssl/opensslv.h"
#include "openssl/symhacks.h"

#include "types.h"

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile);
void show_certs(SSL* ssl);                            

/* Generate the TLS framework used to secure the session. */                                   SSL_CTX* init_ctx_client(void); 

#endif
