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
        log_error("Private key does not match the public certificate");
        abort();
    }
}

SSL_CTX* init_ctx_server(void)                      
{                                                     
        SSL_METHOD *method;  
        SSL_CTX *ctx;
                                                      
        OpenSSL_add_all_algorithms();                
        SSL_load_error_strings();                     
        method = TLSv1_server_method();             
        ctx = SSL_CTX_new(method);                    
                                                     
        if (!ctx){                                 
                ERR_print_errors_fp(stderr);        
                abort();                             
        }                                             
        return ctx;                                  
}

void show_certs(SSL* ssl)                             
{                                                     
    X509 *cert;                                       
    char *line;        
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */     
                                                      
    if (cert){                                        
        log_info("Server certificates:");             
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);                                               
        log_info("Subject: %s", line);                
        free(line);                                   
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);                              
        log_info("Issuer: %s", line);                             
        free(line);                                   
        X509_free(cert);                          
    }                                               
    else {                                          
        log_error("Info: No client certificates configured.");                                                     
    }                                                   
}

