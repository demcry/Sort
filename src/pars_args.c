#include "pars_args.h"
#include <stdio.h>
#include <string.h>

void analyseTok(char *tok, int *cond, char **file)
{
  if(tok == NULL)
    {
      fprintf(stderr, "[DBG] Error: NULL token\n");
      return;
    }
  if(!strcmp(tok, "-h") || !strcmp(tok, "--help"))
    {
      *cond |= COND_HELP;
      return;
    }
  if(!strcmp(tok, "-v") || !strcmp(tok, "--version"))
    {
      *cond |= COND_VER;
      return;
    }
  if(!strcmp(tok, "-a") || !strcmp(tok, "--alphabet"))
    {
      *cond |= COND_ALPH_ORD;
      *cond &= ~COND_RAND;
      return;
    }
  if(!strcmp(tok, "-r") || !strcmp(tok, "--reverse"))
    {
      *cond &= ~COND_ALPH_ORD;
      *cond &= ~COND_RAND;
      return;
    }
  if(!strcmp(tok, "-R") || !strcmp(tok, "--random"))
    {
      *cond |= COND_RAND;
      *cond &= ~COND_ALPH_ORD;
      return;
    }
  if(!strcmp(tok, "-i") || !strcmp(tok, "--ignore-case"))
    {
      *cond |= COND_IGN_CASE;
      return;
    }
  //short keys -ri -vR etc...
  if(tok[0] == '-')
    {
      for(char *i = tok+1; *i != '\0'; i++)
	{
	  switch(*i)
	    {
	    case 'h':
	      *cond |= COND_HELP;
	      break;
	    case 'v':
	      *cond |= COND_VER;
	      break;
	    case 'a':
	      *cond |= COND_ALPH_ORD;
	      *cond &= ~COND_RAND;
	      break;
	    case 'r':
	      *cond &= ~COND_ALPH_ORD;
	      *cond &= ~COND_RAND;
	      break;
	    case 'R':
	      *cond |= COND_RAND;
	      *cond &= ~COND_ALPH_ORD;
	      break;
	    case 'i':
	      *cond |= COND_IGN_CASE;
	      break;
	    default:
	      *cond |= COND_ERR;
	      return;
	    };
	}
    }
  else if( !(*cond & COND_FILE) )    //2nd and later files ignored
    {
      *cond |= COND_FILE;
      *file = tok;
    }
}
