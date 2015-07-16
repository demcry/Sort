int array_to_file(FILE* text, char** strings, int num_of_strings, int max_row_length)
{
    fseek(text, 0, SEEK_SET);
    int i, j;

    for(i = 0; i < num_of_strings; i++)
    {
        for(j = 0; (strings[i][j] != '\0'); j++)
        {
            if(fputc(strings[i][j], text) == EOF)
            {
                printf("ERROR_3_1\n");
                return 1;
            }
        }
        if(fputc('\n', text) == EOF)
        {
            printf("ERROR_3_2\n");
            return 1;
        }

        if(j >= max_row_length)
        {
            printf("Out of str limit\n");
            return 1;
        }
    }
    return 0;
}
