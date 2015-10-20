#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getbuf.h"

void getBuf(FILE *stream, char ***buf, int *size, int *length)
{
  char tmp[256], __byte;
  while( fgets(tmp, sizeof(tmp), stream) != NULL )
    {
      //[DBG]
      //printf("Get line '%s'\n", tmp);
      //[EndDBG]
      if( *size == *length)
      {
        *size *= 2;
        char **newBuf = (char**)realloc( *buf, (*size)*sizeof(char*) );
        if( (newBuf) == NULL )
          {
            fprintf(stderr, "Error: Cannot allocate memory");
	    deleteBuf(*buf);
            exit(1);
          }
	*buf = newBuf;
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
	  deleteBuf(*buf);
	  exit(1);
	}
      memcpy( (*buf)[*length], tmp, tmplen+1);
      (*length)++;
    }
}

void deleteBuf(char **buf)
{
  for(int i=0; buf[i] != NULL; i++)
    {
      free(buf[i]);
      //fprintf(stderr, "Deleted memory %p\n", buf[i]);
    }
  free(buf);
}
