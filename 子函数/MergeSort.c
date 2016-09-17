/**********************************
函数功能:归并排序
参数1(Output):待排序数组
参数2:待排序数组中元素的个数
返回值:无
说明:空间复杂度为O(n+logn)，稳定排序算法
作者: Lee.C
完成时间:2016-05-30
**************************************/
void MergeSort(int *array, const size_t num)
{
	assert(array);
	
	int *tempArray = (int*)malloc(num * sizeof(int));
	if(!tempArray)
	{
		fputs("Call MergeSort error!\n", stderr);
		exit(EXIT_FAILURE);
	}

	MSort(array, 0, num-1, tempArray);

	free(tempArray);
}

/**********************************
函数功能:递归归并排序
参数1(Output):待排序数组
参数2:排序区间的起始下标
参数3:排序区间的末尾下标
参数4(Output):临时数组
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-30
**************************************/
static void MSort(int *array, size_t first, size_t end, int *tempArray)
{
	assert(array);
	
	size_t mid;
	if(first < end)
	{
		mid = (first + end) / 2;
		MSort(array, first, mid, tempArray);
		MSort(array, mid+1, end, tempArray);
		MergeArray(array, first, mid, end, tempArray);
	}
}


/********************************************
函数功能:有序合并数组中两个指定区间的数据
参数1(Output):待排序数组
参数2:前半部分数组的起始下标
参数3:前半部分数组的末尾下标
参数4:后半部分数组的末尾下标
参数5(Output):临时数组
返回值:无
说明:本函数或许只有序合并数组中某指定的子区间，把该区
     间均分两半，对两边数据整合排序，放回原数组空间中；
	 虽然只有本函数使用 tempArray 数组，但由于本函数在
	 递归操作中会反复调用，为防止tempArray在本函数被反复
	 申请和释放，所以把它的申请和释放放到了上层函数中，
	 由形参传入。
作者: Lee.C
完成时间:2016-05-30
**********************************************/
static void MergeArray(int *array, size_t first, size_t mid, size_t end, int *tempArray)
{
	assert(array);
	
	/*****************************************************
	 *forePart       : 指向待排序区间前半部分的起始下标
	 *postPart       : 指向待排序区间后半部分的起始下标
	 *tempArrayCount : 计数临时数组元素个数
	******************************************************/
	size_t forePart = first;
	size_t postPart = mid + 1;
	size_t tempArrayCount = 0;

	while(forePart<=mid && postPart<=end)
	{
		if(array[forePart] <= array[postPart])
			tempArray[tempArrayCount++] = array[forePart++];
		else
			tempArray[tempArrayCount++] = array[postPart++];
	}

	while(forePart <= mid)
		tempArray[tempArrayCount++] = array[forePart++];

	while(postPart <= end)
		tempArray[tempArrayCount++] = array[postPart++];

	//整合排序后的数据放回原数组的原区间中
	memcpy(array+first, tempArray, tempArrayCount*sizeof(int));
}
