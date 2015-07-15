#include "stdlib.h"
#include <stdio.h>


int main(int argc, char* argv[])
{ 
	int flag2, flag1=0;
	if (argv[1] == NULL)
    {
			printf("Parametrs not found\n");
			return 0;
		}
	if (strcmp(argv[1], "HELP") == NULL)
		{
			printf("This is HELP");
			return 0;
		}
	if (strcmp(argv[1], "VERSION") == NULL)
		{
			printf("This is VERSION");
			return 0;
		}
	if (argv[2] != NULL)
	{
		FILE *file1 = fopen(argv[2], "r");
		if (file1 != NULL)
			flag1 = 1;
	}
	switch (argv[1][0])
		{
			case '-':
				switch (argv[1][1])
					{
						case 'o':
							printf("This is reverse\n");
							if (flag1 == 1)
								goto OB;
							else
								return 0;
							
						case 'a':
							printf("This is ABC\n");
							if (flag1 == 1)
								goto ABC;
							else
								return 0;
						case 'z':
							printf("This is ZYX\n");
							if (flag1 == 1)
								goto ZYX;
							else
								return 0;
						case 's':
							printf("This is sensitive\n");
							if (flag1 == 1)
								goto SEN;
							else
								return 0;
						
						case 'u':
							printf("This is unsensitive\n");
							if (flag1 == 1)
								goto EN;
							else
								return 0;
							
						case 'r':
							printf("This is random\n");
							if (flag1 == 1)
								goto RAN;
							else
								return 0;
							
						default:
							printf("wrong parametr\n");
							return 0;
					}
			break;
			default:
					FILE *file = fopen(argv[1], "r");
					if (file == NULL)
						{
							printf("Error: file not found or not exist\n");
							return 0;
						}
					goto ABC;
		}

ABC:
	printf("ABC");
	//call sort ABC with file 1
	// record in new or source
	return 0;
ZYX:
	printf("ZYX");
	//call sort ABC with file 1
	// record in new or source
	return 0;
RAN:
	printf("RAN");
	//call sort ABC with file 1
	// record in new or source
	return 0;
OB:
	printf("reverse");
	//call sort ABC with file 1
	// record in new or source
	return 0;
EN:
	printf("ensen");
	//call sort ABC with file 1
	// record in new or source
	return 0;
SEN:
	printf("sen");
	//call sort ABC with file 1
	// record in new or source
	return 0;
}
