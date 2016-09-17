/**********************************
函数功能:字符串转整数
参数1:整数型字符串
返回值:转换后的证整数
说明:遇到非可转换字符停止，第一个即为不可转换字符，返回0
头文件:
作者: Lee.C
完成时间:2016-05-19
**************************************/
int Str2Int(const char str[])
{
	//定义整形的上限和下限
	static const int MAX_INT = (int)( (unsigned)~0 >> 1 );
	static const int MIN_INT = -(int)( (unsigned)~0 >> 1 ) - 1;
	
	int num = 0, sign = 1, sigleNum = 0;
	
	//判断是否是空
	if(str == 0)
		return 0;
	
	//忽略行首空白
	while(isspace(*str++)
		continue;

	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}

	while(isdigit(*str))
	{
		sigleNum = *str - '0';
		if(sign>0 && (num>MAX_INT/10 || (num==MAX_INT/10 && sigleNum>MAX_INT%10)))
		{
			num = MAX_INT;
			break;
		}
		else if(sign<0 && (num>(unsigned)MIN_INT/10 || (num == (unsigned)MIN_INT/10 && sigleNum>(unsigned)MIN_INT%10)))
		{
			num = MIN_INT;
			break;
		}
		
		num = 10*num + (*str-'0');
		str++;
	}

	return sign>0 ? num : -num;;
	
}
