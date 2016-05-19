/**********************************
函数功能:字符串拷贝函数
参数1(Output):目标地址
参数2:原地址
返回值:目标地址
说明:
作者: Lee.C
完成时间:2016-05-19
**************************************/
char *strcpy(char *strDest, const char *strSrc)
{
	assert( strDest && strSrc );

	char *address = strDest;

	while( (*strDest++ = *strSrc++) != '\0' )
		continue;

	return address;
}
