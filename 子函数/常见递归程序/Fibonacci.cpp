/**********************************
函数功能:递归实现Fibonacci数列
参数1:
返回值:
说明:参考《大话数据结构》P103
所需标准库文件:无
作者: Lee.C
完成时间:2016-03-20
修改时间:
**************************************/
long long Fibonacci(unsigned int i)
{
	if(i<2)
		return i == 0 ? 0 : 1;

	return Fibonacci(i-1) + Fibonacci(i-2);
}