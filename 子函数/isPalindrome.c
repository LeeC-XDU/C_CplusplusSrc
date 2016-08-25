/**********************************
函数功能:判断是否是回文数
参数1:待判断字符串
返回值:是则返回true，不是返回false
说明:无
头文件:assert.h
作者: Lee.C
完成时间:2016-07-01
**************************************/
Status isPalindromic(const char *str)
{
	assert(str);
	
	int len = strlen(str);
	char *begin = str, *end = str+len-1;
	
	while(begin < end)
	{
		if(*begin != *end)
			return FALSE;
		
		begin++;
		end--;
	}
	
	return TRUE;
}
