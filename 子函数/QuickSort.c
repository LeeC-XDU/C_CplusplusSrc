/**********************************
函数功能:快递排序
参数(Output)1:待排序数组
参数2:待排序数组元素个数
返回值:无
说明:非稳定排序，空间复杂度 O(logn)
作者: Lee.C
完成时间:2016-05-31
**************************************/
void QuickSort(int *array, const size_t num)
{
	assert(array);

	QSort(array, 0, num-1);
}

/**********************************
函数功能:快递排序递归程序
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-31
**************************************/
void QSort(int *array, const size_t low, const size_t high)
{
	size_t pivot;

	if(low < high)
	{
		pivot = AdjustArray(array, low, high);

		QSort(array, low, pivot-1);
		QSort(array, pivot+1, high);
	}
}

/**********************************
函数功能:快递排序尾递归程序
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:无
说明:程序把一个递归换成了迭代
作者: Lee.C
完成时间:2016-05-31
**************************************/
void QSort2(int *array, size_t low, size_t high)
{
	size_t pivot;

	while(low < high)
	{
		pivot = AdjustArray(array, low, high);

		QSort2(array, low, pivot-1);
		low = pivot + 1;
	}
}


/**********************************
函数功能:调整数组并获取枢轴元素下标
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:枢轴元素下标
说明:挖坑填坑法
     取出第一个元素，作为枢轴元素，该位置作为坑；
	 从末尾向前找比枢轴元素小的元素，找到去填坑，挖出本坑；
	 从被填坑的下一个元素开始，找比枢轴元素大的元素，找到去填坑，挖出本坑；
	 从被填坑的前一个元素开始...以此下去，直到 low == high
作者: Lee.C
完成时间:2016-05-31
**************************************/
size_t AdjustArray(int *array, size_t low, size_t high)
{
	int pivotKey = 0;
	/************************************
	//有时直接选取第一个元素作为枢轴元素或
	//许不合理，可以使用三数取中法求出新的
	//枢轴元素下标，与第一个元素交换即可
	size_t mid = low + (high-low)/2;
	int tempValue = 0;
	
	//以下三段简单冒泡，保证左<中<右
	if(array[low] > array[mid])
	{
		tempValue  = array[low];
		array[low] = array[mid];
		array[mid] = tempValue;
	}
	if(array[low] > array[high])
	{
		tempValue   = array[low];
		array[low]  = array[high];
		array[high] = tempValue;
	}
	if(array[mid] > array[high])
	{
		tempValue   = array[mid];
		array[mid]  = array[high];
		array[high] = tempValue;
	}
	************************************/
	pivotKey = array[low];

	while(low < high)
	{
		//从后向前找比之小的
		while(low<high && array[high]>=pivotKey)
			high--;
		if(low < high)
		{
			array[low] = array[high];
			low++;
		}

		//从前向后找比之大的
		while(low<high && array[low]<pivotKey)
			low++;
		if(low<high)
		{
			array[high] = array[low];
			high--;
		}
	}

	array[low] = pivotKey;

	return low;
}
