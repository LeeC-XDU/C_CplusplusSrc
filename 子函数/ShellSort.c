/**********************************
函数功能:希尔排序
参数1:待排序数组
参数2:数组元素个数
返回值:无
说明:该排序为非稳定排序
作者: Lee.C
完成时间:2016-05-28
**************************************/
void ShellSort(int *array, const size_t num)
{
	assert(array);
	
	size_t i, j, gap;

	for(gap=n/2; gap>0; gap /= 2)
	{
		//组内数据快速排序
		for(i=gap; i<num; i++)
		{
			if(array[gap] < array[i-gap])
			{
				j = i;
				target = array[i];
				
				while(j>0 && target<array[j-gap])
				{
					array[j] = array[j-gap];
					j -= gap;
				}
				
				array[j] = target;
			}
		}
	}
}