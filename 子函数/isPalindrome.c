/**********************************
       <assert.h>
**************************************/
Status isPalindromic(const char *str)
{
	assert(str);
	
	size_t len = strlen(str);
	char *begin = str, *end = str+len-1;
	
	while(begin <= end)
	{
		if(*begin != *end)
			break;
		
		begin++;
		end--;
	}
	
	if(begin == end)
		return TRUE;
	else
		return FALSE;
}
