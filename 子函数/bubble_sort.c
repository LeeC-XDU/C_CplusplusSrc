/**********************************
函数功能:冒泡排序法
参数1:待排序数组
参数2:数组个数
返回值:无
说明:change变量表示数组是否是有序的了；
     如果数组本身就是有序的，内存循环全部执行一遍就可测出，change不置为true，排序结束；
     如果数组为 2 1 3 4，内循环交换一次就可以完成排序，则第二次进行内循环时，change不置为true，排序结束。
作者: Lee.C
完成时间:2015-06-06
修改时间:2016-05-28
修改说明:规范变量命名和类型等
**************************************/
void bubble_sort(int array[], size_t num)
{
	assert(array);
	/**********************************************
	 *change : 标记在一次外循环中，该数组中元素位置
	           是否有变化，没有，则说明数组已经有序
	***********************************************/
	Status change = TRUE;
	size_t i,j;
	int temp;
	
	for(i=num-1, change=TRUE; i>=1 && change; i--)
	{
		change = FALSE;
		
		for(j=0; j<i; j++)		//每一次内循环把最大的数升至顶端
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				
				change = TRUE;	//如果整个序列已经有序，则这个数值不会变为真
			}
		}
	}
}