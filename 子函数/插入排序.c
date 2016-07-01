/**********************************
函数功能:插入排序
参数1:待排序数组
参数2:数组元素个数
返回值:无
说明:通常，插入排序呈现出二次排序算法中的最佳性能
作者: Lee.C
完成时间:2016-05-28
**************************************/
void InsertSort(int *array, size_t num)
{
	assert(array);
	
	size_t i, j;
	//target : 待插入的元素
	int target;
	
	//假定第一个元素被放到了正确的位置上
	for(i=1; i<num; i++)
	{
		//判断是否array[i]已与前边的数组有序排列，是则无需任何操作了，否则执行下边语句
		if(array[i] < array[i-1])
		{
			j = i;
			target = array[i];
			
			while(j>0 && target<array[j-1])
			{
				array[j] = array[j-1];
				j--;
			}
			
			array[j] = target;
		}
		
	}
}
