int define_length(const char* filename) 
{
  
  FILE* in = fopen( filename, "r" );
  
  int ch= EOF;
  int max_length=0;
  int counter=0;
  
  while ( ( ch = fgetc( in ) ) != EOF )
  {
  
    if ( ch == '\n' )
    {
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
	
	return max_length;
}
