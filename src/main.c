#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../inc/pars_args.h"
#include "../inc/cmpfunc.h"
#include "../inc/getbuf.h"
#include "../inc/rndsort.h"

#define VERSION "sorting version 2.3a \n"

void showhelp()
{
  printf("Usage: sorting [options] [file]...\n\
Options:\n\
  -h, --help		Display this infomation\n\
  -a, --alphabet	Sort lines in alphabetical order\n\
  -r, --reverse		Sort lines in reverse order\n\
  -i, --ignore-case	Ignore case\n\
  -R, --random		Random permutation\n\
  -v, --version		Display version information\n\
\n\
Default options are: --alphbet\n\
If file is not specified, input will be taken from stdin, so you can also combine sorting with other processes.\n\
To complete input use <Enter>+<Ctrl+D> or <Ctrl+D> 3 times.\n\
");
}

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
      fprintf(stderr, "Wrong keys!\nTry 'sorting -h' for help\n");
      exit(1);
    }

  if(cond & COND_HELP)
    {
      showhelp();
      exit(0);
    }

  if(cond & COND_VER)
    {
      printf(VERSION);
      exit(0);
    }

  FILE *filein = stdin;
  if(file != NULL)
    {
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
  getBuf(filein, &lineBuf, &bufSize, &bufLength);

  if(filein != stdin)
    {
      fclose(filein);
    }

  if(cond & COND_ALPH_ORD)
    {
      if(cond & COND_IGN_CASE)
	{
	  qsort(lineBuf, bufLength, sizeof(char*), ai_strcmp);
	}
      else
	{
	  qsort(lineBuf, bufLength, sizeof(char*), a_strcmp);
	}
    }
  else if( !(cond & COND_RAND) )
    {
      if(cond & COND_IGN_CASE)
	{
	  qsort(lineBuf, bufLength, sizeof(char*), ri_strcmp);
	}
      else
	{
	  qsort(lineBuf, bufLength, sizeof(char*), r_strcmp);
	}
    }
  else
    {
      rndsort(lineBuf, bufLength);
      //qsort(lineBuf, bufLength, sizeof(char**), ran_strcmp);
    }

  for(int i=0; i<bufLength; i++)
    {
      fprintf(stdout, "%s", lineBuf[i]);
    }

  deleteBuf(lineBuf);
}
