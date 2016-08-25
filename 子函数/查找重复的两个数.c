/**********************************
函数功能:查找重复的两个数
参数1:数组
参数2:数组元素的个数
参数3(Output):重复的数
返回值:有重复的数，返回真，否则返回假
说明:详见笔记《算法——数组中重复的数》
头文件:无
作者: Lee.C
完成时间:2016-08-20
**************************************/
Status duplicate(const int *numbers, int length, int *duplication)
{
	if(!numbers || length <= 0)
		return FALSE;
	
	for(i=0; i<length; i++)
		if(numbers[i]<0 || numbers[i]>length-1)
			return FALSE;
		
	for(i=0; i<length; i++)
	{
		while(numbers[i] != i)
		{
			if(numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return TRUE;
			}
			
			Swap(numbers[i], numbers[numbers[i]]);
		}
	}
	
	return FALSE;
}

void Swap(int *num1, int *num2)
{
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	num2 = temp;
}