/**********************************
函数功能:三分类一个数组
参数1(Output):待分类数组
参数2:数组长度
返回值:无
说明:三指针分类法
头文件:无
作者: Lee.C
完成时间:2016-07-25
**************************************/
void TripleClassification(int *array, int length)
{
	if(!array || length<=0)
		return;
	
	int begin = 0, current = 0, end = length-1;
	
	while(current <= end)
	{
		if(array[current] == 0)
		{
			swap(array[current], array[begin]);
			current++;
			begin++;
		}
		else if(array[current] == 1)
			current++;
		else
		{
			swap(array[current], array[end]);
			end--;
		}
	}
}

static void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}