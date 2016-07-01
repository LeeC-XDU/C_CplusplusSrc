/**********************************
函数功能:判断指定数字是否是质数
参数:待判断数字
返回值:是否是质数
说明:
头文件:<math.h>
作者: Lee.C
完成时间:2014-7-24
修改时间:2016-06-23
修改说明:代码重构
**************************************/
Status isPrime(int num)
{
	if(num < 2)
		return FALSE;
	
	int i = 0;
	int sqrtNum = (int)sqrt(num);
	
	for(i=2; i<=sqrtNum; i++)
		if(num%i == 0)
			return FALSE;		//2.break;
	
	if(i == sqrtNum+1)
		return TRUE;		//2.function();
	else
		return FALSE;		//2.function();
}

//不用数学库的方法
Status isPrime2(int num)
{
	if(num < 2)
		return FALSE;
	
	int i = 0;
	
	for(i=2; i*i<=num; i++)
		if(num%i == 0)
			return FALSE;
	
	if(i*i > num)
		return TRUE;
	else
		return FALSE;
}