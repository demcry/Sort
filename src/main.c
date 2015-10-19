#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pars_args.h"
#include "cmpfunc.h"
#include "getbuf.h"

int main(int argc, char* argv[])
{ 
  srand(time(NULL));
  
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
      fprintf(stderr, "Taking text from stdin...\n");
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
  
  char **lineBuf;
  int bufSize = 100, bufLength = 0;
  lineBuf = (char**)malloc( bufSize*sizeof(char*) );
  fprintf(stderr, "Getting lines...\n");
  getBuf(filein, &lineBuf, &bufSize, &bufLength);
  
  //[DBG]
  //for(int i=0; i<bufLength; i++)
  //{
  // fprintf(stdout, "%d\t:%p\t:%s", i, lineBuf[i], lineBuf[i]);
  //}
  //[EndDBG]
  
  if(filein != stdin)
    {
      fclose(filein);
    }

  if(cond & COND_IGN_CASE)
    {
      fprintf(stderr, "Ignoring case...\n");
    }

  if(cond & COND_ALPH_ORD)
    {
      if(cond & COND_IGN_CASE)
	{
	  fprintf(stderr, "Ignoring case...\n");
	  fprintf(stderr, "Start sorting in alph order...\n");
	  qsort(lineBuf, bufLength, sizeof(char*), ai_strcmp);
	}
      else
	{
	  fprintf(stderr, "Start sorting in alph order...\n");
	  qsort(lineBuf, bufLength, sizeof(char*), a_strcmp);
	}
    }
  else if( !(cond & COND_RAND) )
    {
      if(cond & COND_IGN_CASE)
	{
	  fprintf(stderr, "Ignoring case...\n");
	  fprintf(stderr, "Start sorting in reverse order...\n");
	  qsort(lineBuf, bufLength, sizeof(char*), ri_strcmp);
	}
      else
	{
	  fprintf(stderr, "Start sorting in reverse order...\n");
	  qsort(lineBuf, bufLength, sizeof(char*), r_strcmp);
	}
    }
  else
    {
      fprintf(stderr, "Start random sorting...\n");
      qsort(lineBuf, bufLength, sizeof(char**), ran_strcmp);
    }
  
  for(int i=0; i<bufLength; i++)
    {
      fprintf(stdout, "%s", lineBuf[i]);
    }
}