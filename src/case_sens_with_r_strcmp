int case_sensitive_strcmp(const void* a1, const void* b1)
{
    char* a = (char*)a1;
    char* b = (char*)b1;
    
    int n=strcmp(a,b);
    return n*(-1);
}

int r_case_sensitive_strcmp(const void* a1, const void* b1)
{
	return ((-1) * case_sensitive_strcmp(a1, b1));
}
