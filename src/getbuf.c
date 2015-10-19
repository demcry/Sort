#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getbuf.h"

int getBuf(FILE *stream, char ***buf, int *size, int *length)
{
  char tmp[256];
  while( fgets(tmp, sizeof(tmp), stream) != NULL )
    {
      //[DBG]
      //printf("Get line '%s'\n", tmp);
      //[EndDBG]
      if( *size == *length)
      {
        *size *= 2;
        *buf = (char**)realloc( *buf, (*size)*sizeof(char*) );
        if( (*buf) == NULL )
          {
            fprintf(stderr, "Error: Cannot allocate memory");
            exit(1);
          }
	//[DBG]
	//printf("Expanded to %d\n", *size);
	//[EndDBG]
      }
      
      int tmplen = 0;
      for(; tmp[tmplen] != '\0'; tmplen++);//find length of line
      if(tmp[tmplen-1] != '\n')
	{
	  tmp[tmplen] = '\n';
	  tmp[tmplen+1] = '\0';
	  tmplen++;
	} 
      //[DBG]
      //printf("Legth = %d\n", tmplen);
      //[EndDBG]
      (*buf)[*length] = (char*)malloc( (tmplen+1)*sizeof(char) );
      if( (*buf)[*length] == NULL )
	{
	  fprintf(stderr, "Error: Cannot allocate memory");
	  exit(1);
	}
      memcpy( (*buf)[*length], tmp, tmplen+1);
      (*length)++;
    }
}

