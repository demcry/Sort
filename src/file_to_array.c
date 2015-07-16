int file_to_array(FILE* text, char*** strings_p, int num_of_strings, int max_row_length)
{
    fseek(text, 0, SEEK_SET);
    char tmp;
    int i, j;

    (*strings_p) = (char**)malloc(num_of_strings * max_row_length * sizeof(char));
    if((*strings_p) == NULL)
    {
        printf("ERROR 2\n");
        return 1;
    }

    for(i = 0; i < num_of_strings; i++)
    {
        (*strings_p)[i] = (char*)malloc(max_row_length * sizeof(char));
        if((*strings_p)[i] == NULL)
        {
            printf("ERROR 2_%d\n", i);
            return 1;
        }
    }

    for(i = 0; i < num_of_strings; i++)
    {
        for(j = 0; j < max_row_length; j++)
        {
            if((tmp = fgetc(text)) != '\n')
            {
                if(tmp != EOF)
                {
                    (*strings_p)[i][j] = tmp;
                }
                else
                {
                    if(i == (num_of_strings - 1))
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

        if(j == max_row_length)
        {
            printf("Out of string limit\n");
            return 1;
        }
    }
    return 0;
}
