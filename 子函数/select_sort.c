/**********************************
函数功能:选择排序法
参数1:待排序数组
参数2:数组个数
返回值:无
说明:通过n-i-1次比较，从n-i个元素中记录出最小元素的下标min，
     并和array[i]元素交换，其中i指元素下标，0≤i<n 。
作者: Lee.C
完成时间:2015-06-06
修改时间:2016-05-28
修改说明:规范变量命名和类型等
**************************************/
void select_sort(int *array, const size_t num)
{
	assert(array);
	/*************************
	 *min : 记录最小元素的下标
	************************/
	size_t i, j, min;
	int temp;

	for(i=0; i<num-1; i++)
	{
		min = i;
		for(j=i+1; j<num; j++)	//这个循环找出最小数的下标
			if(a[j] < a[min])
				min = j;		//min来记录最小值的位置
		if(min != i)			//并把最小值的放到第i+1个位置
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
}