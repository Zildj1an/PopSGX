#include "openfabmap_t.h"
#include <stdio.h>

int open_settings_file(void)
{
  FILE *settings;

  fprintf(stderr,"Opening settings file...\n");
 
  /* Assume settings file name is settings.yml for now */ 
  settings = fopen("settings.yml","r");

  return 0;
}

