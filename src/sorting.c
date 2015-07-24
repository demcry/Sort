#include "pthread.h"
#include "errno.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "strings.h"

int pars_args(int argc, char* argv[], int *flagfile2);
void define_size(FILE * file, int size_of_array[2]);
int file_to_array(FILE* text, char*** strings_p, int num_of_strings, int max_row_length);
int array_to_file(FILE* text, char** strings, int num_of_strings, int max_row_length);
int r_strcmp(const void* a, const void*	b);
int a_strcmp(const void* a, const void*	b);
int ai_strcmp(const void* a, const void* b);
int ri_strcmp(const void* a, const void* b);
int ran_strcmp(const void* a,	const void* b);
int param(int argc, char * argv[], int i);

int main(int argc, char* argv[])
{
	FILE *file1, *file2, *tmp;
	int par;
	char a[255];
	char b;
	int size[2];
	int flagfile2 = 1;
	char **strs;
	int stime;
        long ltime;
        ltime = time(NULL);
	stime = (unsigned) ltime/2;
        srand(stime);
	
	if(argc >1)
	{
	if((strcmp(argv[1],"-h")== 0) || (strcmp(argv[1],"--help")== 0))
	{
		file2 = fopen("help.txt","r+");
		if (file2 != NULL)
		{
			while(fgets(a,255,file2) != NULL)
                	{
                        	fputs(a, stdout);
                	}
		return 0;
		}	
		else 
		{
			printf("Sorry, file with help was lost");
			exit(-1);
		}	
	}	 
	if((strcmp(argv[1],"-v")== 0) || (strcmp(argv[1],"--version")== 0))
	{
		printf("This is sort which created students of HSE, 14 PE\n");
		printf("Version 1.6.0\n");
		return 0;
	}
	}
	tmp = fopen( "tme",  "w+");
if (argc <= 2)
{	
	par = param(argc, argv, 1);
	if((par < 0) && (argc == 2))
	{	
		printf( "Error");
		exit(-1);
	}
		while(fgets(a,255,stdin) != NULL)
        	{
			fputs(a, tmp);
        	}
		fseek(tmp, 0, SEEK_SET);
        	define_size(tmp, size);
		file_to_array(tmp, &strs, size[0], size[1]);
	if (par < 0)
		qsort(strs, size[0], sizeof(char *), a_strcmp);
	else	
	if (par == 1)
                {
                qsort(strs, size[0], sizeof(char *), a_strcmp);
                }
                else
                	if (par == 2)
                	{
                	qsort(strs, size[0], sizeof(char *), r_strcmp); //sorting reverse
                	}
                	else
                    		if (par == 3)
                        	{
                                	qsort(strs, size[0], sizeof(char *), ri_strcmp); //sorting ign + rev
                        	}
                        	else
                            		if (par == 4)
                                	{
                                        	qsort(strs, size[0], sizeof(char *), ai_strcmp);
                                	}
                                	else
                                        	if (par == 5)
                                        	{
                                                	qsort(strs, size[0], sizeof(char *),ran_strcmp);
                                        	}

		array_to_file(stdout, strs, size[0], size[1]);
}
	 
else
	if (argc == 3)
	{

		if(((strcmp(argv[1],"-a")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--alphabet")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--alphabet")==0)) || ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--alphabet")==0)))	
		{
			flagfile2 = 4;
                }
		else
			if(((strcmp(argv[1],"-r")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--reverse")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--reverse")==0))|| ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--reverse")==0)))
			{
				flagfile2 = 3;
			}
	else
	{	
		par = pars_args(argc, argv, &flagfile2);
		if (par>0)
			file1 = fopen(argv[2],"r+");
		else 
		{
			printf("wrong params\n");
			exit(-1);
		}
		flagfile2 = -1;
		define_size(file1, size);
                file_to_array(file1, &strs, size[0], size[1]);	
		if (par == 1) 
		{
                	qsort(strs, size[0], sizeof(char *), a_strcmp);
        	}
		else
            		if (par == 2)
                	{
        	        	qsort(strs, size[0], sizeof(char *), r_strcmp); //sorting reverse
                	}
                	else
                    		if (par == 3)
                        	{
                                	qsort(strs, size[0], sizeof(char *), ri_strcmp); //sorting ign + rev
                        	}
                        	else
                            		if (par == 4)
                                	{
                                        	qsort(strs, size[0], sizeof(char *), ai_strcmp);
                                	}
                                	else
                                    		if (par == 5)
                                        	{
                                                	qsort(strs, size[0], sizeof(char *),ran_strcmp);
						}
	}
	if (flagfile2 != -1)
	{
		 while(fgets(a,255,stdin) != NULL)
                {
                        fputs(a, tmp);
                }
                fseek(tmp, 0, SEEK_SET);
                define_size(tmp, size);
                file_to_array(tmp, &strs, size[0], size[1]);
		if(flagfile2 == 3)
			qsort(strs, size[0], sizeof(char *),ri_strcmp);
		else
			if(flagfile2 == 4)
				qsort(strs, size[0], sizeof(char *),ai_strcmp);
			else
				exit(-1);
	}
		array_to_file(stdout, strs, size[0], size[1]);
	}
else 
{
	par = pars_args(argc, argv, &flagfile2);
	if (par > 0)
	{
		if(argc == 5)
			file1 = fopen(argv[3], "r+");
		else
			if(argc == 4)
				if(flagfile2 != 1)
					file1 = fopen(argv[2],"r+");
				else
					file1 = fopen(argv[3],"r+");
			else
				file1 = fopen(argv[2],"r+");
		define_size(file1, size);
		size[1]++;
	}
	else
	{
		printf("wrong parametres\n");
		exit(-1);
	}
	file_to_array(file1, &strs, size[0], size[1]);
	if (par == 1)
	{
		qsort(strs, size[0], sizeof(char *), a_strcmp);
	}
	else
		if (par == 2)
		{
		qsort(strs, size[0], sizeof(char *), r_strcmp); //sorting reverse
		}
		else
			if (par == 3)
			{
				qsort(strs, size[0], sizeof(char *), ri_strcmp); //sorting ign + rev
			}
			else
				if (par == 4)
				{
					qsort(strs, size[0], sizeof(char *), ai_strcmp);
				}
				else
					if (par == 5)
					{
						qsort(strs, size[0], sizeof(char *),ran_strcmp);
					}
					else
					{
						printf("wrong parametres\n");
						exit(-1);
					}


	if ((flagfile2 == 1) || (flagfile2 == 2))
		array_to_file(stdout, strs, size[0], size[1]);
	else
		{
			printf("Access fail: %s", strerror(errno));
			exit(errno);
		}
	if (flagfile2 == 3)
	{
		file2 = fopen(argv[2], "w+");
                if(file2 != NULL)
                {
        	        array_to_file(file2, strs, size[0], size[1]);
                	fclose(file2);
                }
                else
                {
                	printf("Access fail: %s", strerror(errno));
                	exit(errno);
                }
	}
	if (flagfile2 == 4)
	{
		file2 = fopen(argv[4], "w+");
                if(file2 != NULL)
                {
                	array_to_file(file2, strs, size[0], size[1]);
                	fclose(file2);
                }
                else
                {
        	        printf("Access fail: %s", strerror(errno));
                	exit(errno);
                }
	}
	else
		exit(-1);
	fclose(tmp);
	fclose(file1); 
}
	printf("\n");
	return 0;
}

/* function, which parsers for 1 param */
int param(int argc, char * argv[], int i)
{
if (argc > i)
if ((strcmp(argv[i], "-a") == 0) || (strcmp(argv[i], "--alphabet") == 0))
	return 1;
else
	if ((strcmp(argv[i], "-r") == 0) || (strcmp(argv[i], "--reverse") == 0))
	return 2;
else
	if ((strcmp(argv[i], "-i-r") == 0) || (strcmp(argv[i], "-r-i") == 0) || (strcmp(argv[i], "-ir") == 0) || (strcmp(argv[i], "-ri") == 0))
	return 3;
else
	if ((strcmp(argv[1], "-a-i") == 0) || (strcmp(argv[1], "-i-a") == 0) || (strcmp(argv[1], "-ia") == 0) || (strcmp(argv[1], "-ai") == 0))
	return 4;
else
	if ((strcmp(argv[1], "-R") == 0) || (strcmp(argv[1], "--random") == 0))
        return 5; 
else
	return -1;
else
	return -1;
}

/* function, which parsers for params */
int pars_args(int argc, char* argv[], int *flagfile2)
{
	if ((argc < 3) || (argc>5))
		return -1; // wrong number of arguments
	else
	{
		if (argc == 5)
		{
			FILE *file1 = fopen(argv[3], "r+");
			if (file1 != NULL)
			{
				fclose(file1);
				FILE *file2 = fopen(argv[4], "r+");
				if (file2 != NULL)
				{
					fclose(file2);
					*flagfile2 = 4; //est' file2
				}
				else 
				{
					printf("Check file2: %s", strerror(errno));
					exit(errno);
				}  //problem with file2
			}
			else 
			{
				printf("Check file1: %s", strerror(errno));
				exit(errno);
			} //problem with file1
			if(((strcmp(argv[1],"-a")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--alphabet")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--alphabet")==0)) || ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--alphabet")==0)))
				return 4;// alp + ig
			else
			if(((strcmp(argv[1],"-r")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--reverse")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--reverse")==0)) || ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--reverse")==0)))
				return 3;// rev + ig
			else
			{
				return -1;//wrong param
			}
		}
		else
		if(argc == 4)
		{
			FILE *file1 = fopen(argv[2], "r+");
                        if (file1 != NULL)
                        {// 2 files
                                fclose(file1);
                                FILE *file2 = fopen(argv[3], "r+");
                                if (file2 != NULL)
                                {
                                        fclose(file2);
                                        *flagfile2 = 3; //est' file2
                                }
				else
				{
                                       	printf("Check 2file: %s", strerror(errno));
                                       	exit(errno);
                               	} 
			}
			else
			{
			FILE *file1 = fopen(argv[3], "r+");
                                if (file1 != NULL)
                                {
                                        fclose(file1);
                                        *flagfile2 = 1; //not file2
                                }
                                else
                                {
                                        printf("Check 1file: %s", strerror(errno));
                                        exit(errno);
                                }   
			if(((strcmp(argv[1],"-a")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--alphabet")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--alphabet")==0)) || ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--alphabet")==0)))
				return 4;
			else
			if(((strcmp(argv[1],"-r")==0) && (strcmp(argv[2], "--ignore_case")==0)) || ((strcmp(argv[1],"--reverse")==0) && (strcmp(argv[2],"--ignore_case")==0)) || ((strcmp(argv[1],"-i")==0) && (strcmp(argv[2],"--reverse")==0))  || ((strcmp(argv[1],"--ignore_case")==0) && (strcmp(argv[2],"--reverse")==0)))
				return 3;
			else
                        {
                                return -1;//wrong param
                        }
		}
	}
	else
	{
		FILE *file1 = fopen(argv[2], "r+");
		if (file1 == NULL) 
		{
	                printf("Check 1file: %s", strerror(errno));
        	        exit(errno);
                } //problem with file
		else *flagfile2 = 2; //net file2
	}
		if ((argv[1][0] == '-'))
		{
			if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "--alphabet") == 0))
				return 1; // alphabetic order
			else
				if ((strcmp(argv[1], "-r") == 0) || (strcmp(argv[1], "--reverse") == 0))
					return 2; // reverse
				else
					if ((strcmp(argv[1], "-i-r") == 0) || (strcmp(argv[1], "-r-i") == 0) || (strcmp(argv[1], "-ir") == 0) || (strcmp(argv[1], "-ri") == 0))
						return 3; // ignorecase + reverse
					else
						if ((strcmp(argv[1], "-a-i") == 0) || (strcmp(argv[1], "-i-a") == 0) || (strcmp(argv[1], "-ia") == 0) || (strcmp(argv[1], "-ai") == 0))
							return 4; // alphabetic + reverse
						else
							if ((strcmp(argv[1], "-R") == 0) || (strcmp(argv[1], "--random") == 0))
								return 5; // random
							else
								if (strcmp(argv[1], "--help") == 0)
									return 6; // help
								else
									if (strcmp(argv[1], "--version") == 0)
										return 7; // version
									else
										return -3; // wrong parameter
		}
		else
			return -3; // wrong parameter 
	}
}

/* function, which defines size of textfile */
void define_size(FILE* file, int size_of_array[2])
{
	int ch;
	int lines = 1;
	int max_length = 0;
	int counter = 0;
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
		{
			lines++;
			if (max_length < counter)
				max_length = counter;
			counter = 0;
		}
		else
		{
			counter++;
			if (max_length < counter)
				max_length = counter;
		}
	}
	size_of_array[0] = lines;
	size_of_array[1] = max_length + 1;
}

/* function, which reads filetext to array */
int file_to_array(FILE* text, char*** strings_p, int num_of_strings, int max_row_length)
{
	fseek(text, 0, SEEK_SET);
	char tmp;
	int i, j;
	(*strings_p) = (char**)malloc(num_of_strings * max_row_length * sizeof(char));
	if ((*strings_p) == NULL)
	{
		printf("ERROR 2\n");
		return 1;
	}

	for (i = 0; i < num_of_strings; i++)
	{
		(*strings_p)[i] = (char*)malloc(max_row_length * sizeof(char));
		if ((*strings_p)[i] == NULL)
		{
			printf("ERROR 2_%d\n", i);
			return 1;
		}
	}
	for (i = 0; i < num_of_strings; i++)
	{
		for (j = 0; j < max_row_length; j++)
		{
			if ((tmp = fgetc(text)) != '\n')
			{
				if (tmp != EOF)
				{
					(*strings_p)[i][j] = tmp;
				}
				else
				{
					if (i == (num_of_strings - 1))
					{
						(*strings_p)[i][j] = '\0';
						break;
					}
					else
					{
						printf("ERROR 1\n");
						return 1;
					}
				}
			}
			else
			{
				(*strings_p)[i][j] = '\0';
				break;
			}
		}
		if (j == max_row_length)
		{
			printf("Out of string limit\n");
			return 1;
		}
	}
	return 0;
}

/* function, which writes array to textfile */
int array_to_file(FILE* text, char** strings, int num_of_strings, int max_row_length)
{
	fseek(text, 0, SEEK_SET);
	int i, j;
	for (i = 0; i < num_of_strings; i++)
	{
		for (j = 0; (strings[i][j] != '\0'); j++)
		{
			if (fputc(strings[i][j], text) == EOF)
			{
				printf("ERROR_3_1\n");
				return 1;
			}
		}
		if (i < (num_of_strings - 1))
		{
			if (fputc('\n', text) == EOF)
			{
				printf("ERROR_3_2\n");
				return 1;
			}
		}
		if (j >= max_row_length)
		{
			printf("Out of str limit\n");
			return 1;
		}
	}
	return 0;
}

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

