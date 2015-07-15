int count_lines(const char* filename) 
{

   FILE* in = fopen( filename, "r" );
   
   int counter = 1;
   int ch = EOF;
   
   while ( ( ch = fgetc( in ) ) != EOF ) 
	{ 
        if ( ch == '\n' )
            counter++;
	}
	
   return counter;
}
