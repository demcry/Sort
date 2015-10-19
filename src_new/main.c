#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pars_args.h"
#include "cmpfunc.h"

int main(int argc, char* argv[])
{ 
  int cond = COND_DEFAULT;
  char *file = NULL;
  for(int i=1;i<argc;i++)
    {
      analyseTok(argv[i], &cond, &file);
    }

  if(cond & COND_ERR)
    {
      fprintf(stderr, "Wrong keys!\nTry 'sort -h' for help\n");
      exit(1);
    }
  
  if(cond & COND_HELP)
    {
      fprintf(stderr, "Showing help page...\n");
      exit(0);
    }
  
  if(cond & COND_VER)
    {
      fprintf(stderr, "Showing version info...\n");
      //continue execution
    }

  FILE *filein = stdin;
  if(file == NULL)
    {
      fprintf(stdout, "Taking text from stdin...\n");
      //stdout
    }
  else
    {
      fprintf(stderr, "Trying to open file '%s'...\n", file);
      filein = fopen(file, "r");
      if(filein == NULL)
	{
	  fprintf(stderr, "Can`t open file '%s'!\n", file);
	  exit(1);
	}
    }
  
  char *lineBuf[];
  int bufSize = 100, bufLength = 0;
  buf = (char**)malloc( bufSize*sizeof(char*) );
  fprintf(stderr, "Getting lines...\n");
  //call getbuf();
  
  if(cond & COND_IGN_CASE)
    {
      fprintf(stderr, "Ignoring case...\n");
    }

  if(cond & COND_ALPH_ORD)
    {
      fprintf(stderr, "Start sorting in alph order...\n");
      exit(0);
    }
  else if( !(cond & COND_RAND) )
    {
      fprintf(stderr, "Start sorting in reverse order...\n");
      exit(0);
    }
  else
    {
      fprintf(stderr, "Start random sorting...\n");
      exit(0);
    }
  
}
