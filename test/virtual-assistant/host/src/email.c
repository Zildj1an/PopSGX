#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>
#include "encode.c"
#include "ssl.c"

#include "../virtualassistant_u.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

int config_email_function(void)
{
  char from[BUFFER_SIZE] = "";
  char pass[BUFFER_SIZE] = "";
  FILE* new_config_email =NULL;

  new_config_email = fopen("config_email","w+");
  //sprintf(tmp_string, "%s \"Please enter your email adress.\" 2>/dev/null", TTS);
  //system(tmp_string);
  sprintf(tmp_string,"popsgx_test@email.com");
  printf("Testing with email %s\n",tmp_string);
  //printf("\nPlease enter your email adress : ");
  //scanf("%s", from);
  sprintf(from,"popsgx_test@email.com");
  fprintf(new_config_email,"%s",from);

  // POPSGX_ENCRYPTION /* Use the server to encrypt the email */

  /* PopSGX request ecall -> Create enclave and execute */

  oe_enclave_t* enclave = NULL;
  oe_result_t result, result_enc;
  char res_str[BUFFER_SIZE] = "";

  result = oe_create_virtualassistant_enclave(
      "virtualenc.signed",OE_ENCLAVE_TYPE_SGX,OE_ENCLAVE_FLAG_DEBUG,NULL,0,&enclave);

  if (result != OE_OK){
      fprintf(stderr,"Creation of the enclave failed\n");
  }

  fprintf(stdout,"Host: Calling execution of encryption request for email\n");

  result = b64_enclave_encode(enclave,&result_enc,from,strlen(from),res_str);

  if (result != OE_OK){
    fprintf(stderr,"Execution of the ecall failed\n");
  }

  fprintf(new_config_email,"%s\n",res_str);

  //sprintf(tmp_string, "%s \"please enter your password.\" 2>/dev/null", TTS);
  //system(tmp_string);
  //
  //printf("Please enter your password: ");
  //scanf("%s", pass);
  sprintf(pass,"password");
  printf("Testing with password %s\n",pass);

  // POPSGX_ENCRYPTION /* Use the server to encrypt the password */

  fprintf(stdout,"Host: Calling execution of encryption request for password\n");

  result = b64_enclave_encode(enclave,&result_enc,pass,strlen(pass),res_str);

  if (result != OE_OK){
    fprintf(stderr,"Execution of the ecall failed\n");
  }

  fprintf(new_config_email,"%s\n",res_str);

  //sprintf(tmp_string, "%s \"Your email account is now saved.\" 2>/dev/null", TTS);
  //system(tmp_string);
  printf("%s : adress saved. \n", from);
  fclose(new_config_email);
  return 0;
}

int email(void)
{
  //searching for config_email, create it if it does not exist
  FILE* config_email = NULL;
  config_email = fopen("config_email", "r+");
 
 //if (!config_email){
    config_email_function();
    return 0; // For PopSGX we only care about this
 // }

  //Asking action to user in a loop

  char action[20]="";

  int exit =0;
  while(exit==0){
    sprintf(tmp_string, "%s \"what do you want to do with your emails ?\" 2>/dev/null", TTS);
    system(tmp_string);
    printf("\n\nWhat do you want to do with your emails ? (send/configure)\n> ");
    scanf("%s", action);
    if(strcmp(action,"send")==0 || strcmp(action,"sned")==0 || strcmp(action,"1")==0 ){
      sprintf(tmp_string, "%s \"You can write your email.\" 2>/dev/null", TTS);
      system(tmp_string);
      ssl_connect("send");
    }else if(strcmp(action,"read")==0 || strcmp(action,"raed")==0 || strcmp(action,"2")==0){
      printf("NOT IMPLEMENTED YET.");
    } else if (strcmp(action,"configure")==0 || strcmp(action,"3")==0){
      config_email_function();
    } else if (strcmp(action,"exit")==0 || strcmp(action,"quit")==0 || strcmp(action,"cancel")==0 || strcmp(action,"close")==0){
      printf("\n\n");
      exit=1;
    } else {
      printf("Sorry I can't do that.\n\n");
    }
  }
}
