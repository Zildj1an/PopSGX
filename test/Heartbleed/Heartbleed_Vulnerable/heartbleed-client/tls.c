#include "tls.h"

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
    if (SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM)<= 0){
        ERR_print_errors_fp(stderr);
        abort();
    }

    /* Set the private key from KeyFile */
    if (SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM)<=0) {
        ERR_print_errors_fp(stderr);
        abort();
    }

    /* Verify private key */
    if (!SSL_CTX_check_private_key(ctx)){
        printf("Private key does not match the public certificate");
        abort();
    }
}

void show_certs(SSL* ssl)                             
{                                                     
    X509 *cert;                                       
    char *line;        
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */     
                                                      
    if (cert){                                        
        printf("Server certificates:");             
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);                                               
        printf("Subject: %s", line);                
        free(line);                                   
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);                              
        printf("Issuer: %s", line);                             
        free(line);                                   
        X509_free(cert);                          
    }                                               
    else {                                          
        printf("Info: No client certificates configured.");                                              }                                          
}

