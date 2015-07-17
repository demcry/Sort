#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int pars_args(int argc, char* argv[]);
void define_size(FILE * file, int size_of_array[2]);
int file_to_array(FILE* text, char*** strings_p, int num_of_strings, int max_row_length);
int array_to_file(FILE* text, char** strings, int num_of_strings, int max_row_length);

int main(int argc, char* argv[])
{
 FILE *file1, *file2;
 int par;
 int size[2];
 char **strs; 
 par = pars_args(argc, argv);
 if (par > 0)
 {
  file1 = fopen(argv[2], "r");
  define_size(file1, size);
  size[1]++;
 }
 else
 {
  printf("wrong parametres\n");
  return 0;
 }
 file_to_array(file1, &strs, size[0], size[1]);
 if (par == 1)
  printf("sort alphabet"); //sorting alphabet
 else
  if (par == 2)
   printf("sort ignorecase"); //sorting ignorecase
  else
   if (par == 3)
    printf("sort ignorecase + reverse"); //sorting ign + rev
   else
    if (par == 4)
     printf("sort alphabet + ignorcase");// sorting alpha + ign
    else
     if (par == 5)
      printf("sort random"); // sorting random
     else
     {
      printf("wrong parametres");
      return 0;
     }
 //qsort dont work

 if (argv[3] != NULL)
 {
  file2 = fopen(argv[3], "w");
  if (file2 == NULL)
  {
   if ((file1 = fopen(argv[2], "w")) == NULL)
    printf("ERROR of record"); 
   else
   array_to_file(file1, strs, size[0], size[1]);
  }
  else
   array_to_file(file2, strs, size[0], size[1]);
 }
 fclose(file1);
 fclose(file2);
 return 0;
}


int pars_args(int argc, char* argv[])
{
 int flagfile2 = 0;
 if ((argc < 3) || (argc>4)) 
  return -1; // wrong number of arguments
 else
 {
  FILE *file1 = fopen(argv[2], "r");
  if (argc == 4)
  {
   FILE *file2 = fopen(argv[3], "r");
   if (file2 != NULL)
    flagfile2 = 1;
  }     
  if ((argv[1][0] == '-') && (((file1 && flagfile2) != NULL) || (((file1 && flagfile2) != NULL) && (flagfile2 != 0))))
  {
   if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "--alphabet") == 0))
    return 1; // alphabetic order
   else
    if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--ignorecase") == 0))
     return 2; // ignorecase
    else
     if ((strcmp(argv[1], "-i-r") == 0) || (strcmp(argv[1], "-r-i") == 0) || (strcmp(argv[1], "-ir") == 0) || (strcmp(argv[1],"-ri") == 0))
      return 3; // ignorecase + reverse
     else
      if ((strcmp(argv[1], "-a-i") == 0) || (strcmp(argv[1], "-i-a") == 0) || (strcmp(argv[1], "-ia") == 0) || (strcmp(argv[1], "-ai") == 0))
       return 4; // alphabetic + ignorecase
      else
       if ((strcmp(argv[1], "-R") == 0) || (strcmp(argv[1], "--random") == 0))
        return 5; // random
       else
        if (strcmp(argv[1], "--help") == 0)
         return 6; // help
          else
           if (strcmp(argv[1], "--version") == 0)
            return 7; // version
           else
            return -3;
  }
  else
   return -2;
 }// wrong parameter
}

void define_size(FILE* file, int size_of_array[2])
{
 int ch;
 int lines = 1;
 int max_length = 0;
 int counter = 0;
 while ((ch = fgetc(file)) != EOF)
 {
  if (ch == '\n')
  {
   lines++;
   if (max_length < counter)
    max_length = counter;
   counter = 0;
  }
  else
  {
   counter++;
   if (max_length < counter)
    max_length = counter;
  }
 }
 size_of_array[0] = lines;
 size_of_array[1] = max_length + 1;
}

int file_to_array(FILE* text, char*** strings_p, int num_of_strings, int max_row_length)
{
 fseek(text, 0, SEEK_SET);
 char tmp;
 int i, j;
 (*strings_p) = (char**)malloc(num_of_strings * max_row_length * sizeof(char));
 if ((*strings_p) == NULL)
 {
  printf("ERROR 2\n");
  return 1;
 }

 for (i = 0; i < num_of_strings; i++)
 {
  (*strings_p)[i] = (char*)malloc(max_row_length * sizeof(char));
  if ((*strings_p)[i] == NULL)
  {
   printf("ERROR 2_%d\n", i);
   return 1;
  }
 }
 for (i = 0; i < num_of_strings; i++)
 {
  for (j = 0; j < max_row_length; j++)
  {
   if ((tmp = fgetc(text)) != '\n')
   {
    if (tmp != EOF)
    {
     (*strings_p)[i][j] = tmp;
    }
    else
    {
     if (i == (num_of_strings - 1))
     {
      (*strings_p)[i][j] = '\0';
      break;
     }
     else
     {
      printf("ERROR 1\n");
      return 1;
     }
    }
   }
   else
   {
    (*strings_p)[i][j] = '\0';
    break;
   }
  }
  if (j == max_row_length)
  {
   printf("Out of string limit\n");
   return 1;
  }
 }
 return 0;
}

int array_to_file(FILE* text, char** strings, int num_of_strings, int max_row_length)
{
 fseek(text, 0, SEEK_SET);
 int i, j;
 for (i = 0; i < num_of_strings; i++)
 {
  for (j = 0; (strings[i][j] != '\0'); j++)
  {
   if (fputc(strings[i][j], text) == EOF)
   {
    printf("ERROR_3_1\n");
    return 1;
   }
  }
  if (fputc('\n', text) == EOF)
  {
   printf("ERROR_3_2\n");
   return 1;
  }
  if (j >= max_row_length)
  {
   printf("Out of str limit\n");
   return 1;
  }
 }
 return 0;
}

