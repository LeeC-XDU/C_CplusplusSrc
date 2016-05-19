/**********************************
函数功能:字符串转整数
参数1:整数型字符串
返回值:转换后的证整数
说明:遇到非可转换字符停止，第一个即为不可转换字符，返回0
作者: Lee.C
完成时间:2016-05-19
**************************************/
int Str2Int(const char *str)
{
	assert(str);

	int num = 0, negativeFlag = 0;

	if(*str == '-')
	{
		negativeFlag = 1;
		str++;
	}

	while(*str && *str>='0' && *str <= '9')
	{
		num = 10*num + (*str-'0');
		str++;
	}

	if(negativeFlag)
		num *= -1;

	return num;
	
}
