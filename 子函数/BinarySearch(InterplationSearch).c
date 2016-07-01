/**********************************
函数功能:二分(插值)查找
参数1:待被查找数组
参数2:数组元素个数
参数3:待查找元素
返回值:key在数组array中的地址索引，没有返回NULL
说明:本函数并没有改变array数组的值，但为了与返回值匹配，就没有用 const 修饰
头文件: <assert.h>
作者: Lee.C
完成时间:2016-05-22
**************************************/
int *BinarySearch(int *array, size_t num, int key)
{
	assert(array);

	size_t low = 0, high = num - 1, mid = 0;

	while(low <= high)
	{
		mid = (low+high)/2;
		
		//改为以下语句成为 插值查找
		//mid = low + (high-low) * (key-array[low]) / (array[high]-array[low]);
		
		if(key < array[mid])
			high = mid - 1;
		else if(key > array[mid])
			low = mid + 1;
		else
			return array + mid;
	}

	return NULL;
}