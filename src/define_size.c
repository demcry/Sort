void define_size(FILE* file,int size_of_array[2]) 
{
	int ch;
	int lines = 1;
	int max_length=0;
	int counter=0;
	while ((ch = fgetc(file)) != EOF ) 
	{ 
        if (ch == '\n')
		{
            lines++;
		if (max_length<counter)
				max_length=counter;
			counter=0;
		}
		else
		{
			counter++;
			if (max_length<counter)
				max_length=counter;
		}
	}
	size_of_array[0]=lines;
	size_of_array[1]=max_length;
}
