#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/getbuf.h"

void getBuf(FILE *stream, char ***buf, int *size, int *length)
{
  int tmpsize = 80;
  char *tmp = (char*)malloc( tmpsize*sizeof(char) );
  while( fgets(tmp, tmpsize, stream) != NULL )
    {
      // Expand array buf
      if( *size == *length)
      {
        *size *= 2;
        char **newBuf = (char**)realloc( *buf, (*size)*sizeof(char*) );
        if(newBuf == NULL)
          {
            fprintf(stderr, "Error: Cannot allocate memory");
	    deleteBuf(*buf);
	    free(tmp);
            exit(1);
          }
	*buf = newBuf;
      }

      int tmplen = 0;
      for(; tmp[tmplen] != '\0'; tmplen++);//find length of line
      //Expand array tmp
      while(tmplen == tmpsize-1)
	{
	  tmpsize *= 2;
	  char *newTmp = (char*)realloc( tmp, tmpsize*sizeof(char) );
	  if(newTmp == NULL)
	    {
	      fprintf(stderr, "Error: Cannot allocate memory");
	      deleteBuf(*buf);
	      free(tmp);
	      exit(1);
	    }
	  tmp = newTmp;
	  fgets( &(tmp[tmplen]), tmpsize-tmplen, stream);
	  for(; tmp[tmplen] != '\0'; tmplen++);//find length of line
	}

      if(tmp[tmplen-1] != '\n')
	{
	  tmp[tmplen] = '\n';
	  tmp[tmplen+1] = '\0';
	  tmplen++;
	}

      (*buf)[*length] = (char*)malloc( (tmplen+1)*sizeof(char) );
      if( (*buf)[*length] == NULL )
	{
	  fprintf(stderr, "Error: Cannot allocate memory");
	  deleteBuf(*buf);
	  free(tmp);
	  exit(1);
	}
      memcpy( (*buf)[*length], tmp, tmplen+1);
      (*length)++;
    }

  free(tmp);
}

void deleteBuf(char **buf)
{
  for(int i=0; buf[i] != NULL; i++)
    {
      free(buf[i]);
    }
  free(buf);
}
