/**********************************
函数功能:判断指定数字是否是质数
参数:待判断数字
返回值:是否是质数
说明:下取整，有等号，加1
     上取整，无等号，不加1
所需标准库文件:math.h
作者: Lee.C
完成时间:2014-7-24
修改时间:2015-12-23
**************************************/
bool isPrime(long num)
{
	long i = 0;
	long sqrt_num = (long)sqrt(num);
	
	if(num>1)
	{
		for(i=2;i<=sqrt_num;i++)
		{
			if(num%i == 0)
				return false;		//2.break;
		}

		if(i == sqrt_num+1)
			return true;		//2.function();
		else
			return false;		//2.function();
	}
	else
		return false;
}

//下取整
bool isPrime(const unsigned int num)
{
	unsigned int i = 0;
	unsigned int sqrt_num = 0;

	if( num < 2)
	{
		printf("Call 'isPrime' error\n");
		printf("The num is incorrect(<=1)\n");
		return false;
	}

	sqrt_num = (unsigned int)sqrt(num);

	for(i=2; i<=sqrt_num; i++)
	{
		if(num%i == 0)
			return false;		//2.break;
	}
	
	if(i == sqrt_num+1)
		return true;		//2.function();
	else
		return false;		//2.function();
}

//上取整
bool isPrime(const unsigned int num)
{
	unsigned int  i = 0;
	unsigned int sqrt_num = 0;
	
	if( num < 2 )
	{
		printf("Call 'isPrime' error\n");
		printf("The num is incorrect(<=1)\n");
		return false;
	}
	
	sqrt_num = (unsigned int)ceil(sqrt(num));

	for(i=2; i<sqrt_num; i++)
	{
		if(num%i == 0)
			return false;		//2.break;
	}
	
	if(i == sqrt_num)
		return true;		//2.function();
	else
		return false;		//2.function();
}