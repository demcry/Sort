#include "rndsort.h"
#include <stdlib.h>
#include <stdio.h>

void rndsort(char **buf, int len)
{
  for(int i=0; i<len-1; i++)
    {
      int r = rand()%(len-i-1) + (i+1);
      //swap(buf[i], buf[r]);
      char *tmp = buf[i];
      buf[i] = buf[r];
      buf[r] = tmp;
    }
}
