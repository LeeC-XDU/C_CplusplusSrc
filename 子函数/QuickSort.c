/**********************************
函数功能:快递排序
参数(Output)1:待排序数组
参数2:待排序数组元素个数
返回值:无
说明:非稳定排序，空间复杂度 O(logn)
作者: Lee.C
完成时间:2016-05-31
**************************************/
void QuickSort(int *array, int num)
{
	assert(array);

	QSort1(array, 0, num-1);
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
static void QSort1(int *array, int low, int high)
{
	int pivot;

	if(low < high)
	{
		pivot = GetPivot3(array, low, high);

		QSort1(array, low, pivot-1);
		QSort1(array, pivot+1, high);
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
static void QSort2(int *array, int low, int high)
{
	int pivot;

	while(low < high)
	{
		pivot = GetPivot2(array, low, high);

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
说明:(选定枢轴量，找枢轴点)
	 挖坑填坑法
     取出第一个元素，作为枢轴元素，该位置作为坑；
	 从末尾向前找比枢轴元素小的元素，找到去填坑，挖出本坑；
	 从被填坑的下一个元素开始，找比枢轴元素大的元素，找到去填坑，挖出本坑；
	 从被填坑的前一个元素开始...以此下去，直到 low == high
作者: Lee.C
完成时间:2016-05-31
**************************************/
static int GetPivot1(int *array, int low, int high)
{
	int pivotKey = 0;
	/************************************
	//有时直接选取第一个元素作为枢轴元素或
	//许不合理，可以使用三数取中法求出新的
	//枢轴元素下标，与第一个元素交换即可
	int mid = low + (high-low)/2;
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
		if(low < high)
		{
			array[high] = array[low];
			high--;
		}
	}

	//最终这里low=high，所以用low用high都行
	array[low] = pivotKey;

	return low;
}


/**********************************
函数功能:调整数组并获取枢轴元素下标
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:枢轴元素下标
说明:GetPivot1()程序的另一种实现方式，
     详细见笔记《C基本知识点总结》45
作者: Lee.C
完成时间:2016-07-25
**************************************/
static int GetPivot2(int *array, int low, int high)
{
	int pivotKeyIndex = low;
	int pivotKey = array[pivotKeyIndex];

	while(low < high)
	{
		//这里用>=更好吗？
		if(array[high] > pivotKey)
			high--;
		//这里是一定要有等号的
		else if(array[low] <= pivotKey)
			low++;
		else
		{
			array[pivotKeyIndex] = array[high];
			array[high] = array[low];
			pivotKeyIndex = low;
		}
	}

	/****************************************************************
	 这里一定要把握好，此时low=high，这时或许是由high--导致两者相等，
	 也可能是由low++导致两者相等的，若由high--致两者相等，那么pivotKeyIndex
	 与low和high相等，下面第一条语句的执行无意义，若由low++致两者相等，
	 那么pivotKeyIndex与low不等，low和high相等，下面语句用high作为下标
	 与while循环中的else对应，有助于理解，当然用low也行，因为两者相等。
	***************************************************************/
	array[pivotKeyIndex] = array[high];
	array[high] = pivotKey;

	return high;
}


/**********************************
函数功能:调整数组并获取枢轴元素下标
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:枢轴元素下标
说明:又是一种获取枢轴，调整数组的数组的方式
作者: Lee.C
完成时间:2016-07-25
**************************************/
static int GetPivot3(int *array, int low, int high)
{
	int pivotKeyIndex = low;
	int pivotKey = array[pivotKeyIndex];

	while(low < high)
	{
		if(array[high] > pivotKey)
			high--;
		else if(array[low] <= pivotKey)
			low++;
		else
			swap(&array[low], &array[high]);
	}

	swap(&array[pivotKeyIndex], &array[low]);

	return low;
}

/**********************************
函数功能:调整数组并获取枢轴元素下标
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:枢轴元素下标
说明:又是一种获取枢轴，调整数组的数组的方式
作者: Lee.C
完成时间:2016-07-25
**************************************/
static int GetPivot4(int *array, int low, int high)
{
	int pivotKeyIndex = high;
	int slow = low -1, fast = low;
	int pivotKey = array[pivotKeyIndex];

	for(fast=low; fast<high; fast++)
	{
		if(array[fast] <= pivotKey)
		{
			slow++;
			swap(&array[slow], &array[fast]);
		}
	}

	swap(&array[slow+1], &array[pivotKeyIndex]);

	return slow + 1;
}

/**********************************
函数功能:调整数组并获取枢轴元素下标
参数(Output)1:待排序数组
参数2:排序区间起始下标
参数3:排序区间末尾下标
返回值:枢轴元素下标
说明:又是一种获取枢轴，方法好理解，STL上用的此
     感觉不对呀！！！！
作者: Lee.C
完成时间:2016-09-16
**************************************/
static int GetPivot5(int *array, int low, int high)
{
	int pivotKey = array[low];

	while(TRUE)
	{
		while(array[low] < pivotKey)
			low++;
		while(array[high] > pivotKey)
			high++;
		
		if(low > high)
			return first;
		
		swap(&array[low], &array[high]);
		
		low++;
		high--;
	}
}

static void swap(int *a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}