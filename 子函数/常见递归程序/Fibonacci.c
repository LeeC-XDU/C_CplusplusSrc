/**********************************
函数功能:递归实现Fibonacci数列
参数1:第n个Fibonacci数
返回值:第n个Fibonacci数的数值
说明:参考《大话数据结构》P103
所需标准库文件:无
作者: Lee.C
完成时间:2016-03-20
修改时间:
**************************************/
long long Fibonacci(unsigned int n)
{
	if(n<2)
		return n == 0 ? 0 : 1;

	return Fibonacci(n-1) + Fibonacci(n-2);
}

/**********************************
函数功能:非递归实现Fibonacci数列
参数1:第n个Fibonacci数
返回值:第n个Fibonacci数的数值
说明:
所需标准库文件:无
作者: Lee.C
完成时间:2016-09-16
修改时间:
**************************************/
long long Fibonacci(unsigned int n)
{
	if(n < 1)
		return 0;
	else if(n < 2)
		return 1;

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;
	int i = 0;
	
	for(i=2; i<=n; i++)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	
	return fibN;
}