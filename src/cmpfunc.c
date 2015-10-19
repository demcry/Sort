#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "cmpfunc.h"

/* function, which compares 2 strings in reverse */
int r_strcmp(const void* a, const void* b)
{
	return -strcmp(*(char**)a, *(char**)b);
}

/* function, which compares 2 strings in alphabet */
int a_strcmp(const void* a, const void* b)
{
	return strcmp(*(char**)a, *(char**)b);
}

/* function, which compares 2 strings without case */
int ai_strcmp(const void* a, const void* b)
{
        return strcasecmp(*(char**)a, *(char**)b);
}

/* function, which compares 2 strings without case and reverse */
int ri_strcmp(const void* a, const void* b)
{
        return -strcasecmp(*(char**)a, *(char**)b);
}

/* function, which generate random number for sorting */
int ran_strcmp(const void* a, const void* b)
{
	return (rand()%3-1);
}
