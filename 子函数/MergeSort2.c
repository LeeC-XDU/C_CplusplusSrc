/**********************************
函数功能:非递归归并排序
参数1(Output):待排序数组
参数2:待排序数组中元素的个数
返回值:无
说明:空间复杂度为O(n)，稳定排序算法
作者: Lee.C
完成时间:2016-05-30
**************************************/
void MergeSort2(int *array, const size_t num)
{
	assert(array);
	
	/************************************
	 *pairwiseNum : 每个分组中元素的个数
	************************************/
	int *tempArray = (int*)malloc(num*sizeof(int));
	size_t pairwiseNum = 1;

	//当分组中元素的个数小于数组中元素个数时，进行归并排序
	while(pairwiseNum < num)
	{
		/****************************************************
		 *开始的时候pairwiseNum为1，即每个分组一个元素，第一
		 *个元素与第二个元素归并，第三个与第四个进行归并...；
		 *然后pairwiseNum变为2，第一个分组的两个元素与第二个
		 *分组的两个元素进行归并，第三个分组的两个元素与第四
		 *个的两个元素进行归并以此类推
		*****************************************************/
		MergePair(array, tempArray, pairwiseNum, num);
		pairwiseNum *= 2;
	}
	
	free(tempArray);
}


/**********************************
函数功能:对每个分组归并排序
参数1(Output):待排序数组
参数2:临时数组，用于MergeArray()函数
参数3:当前分组中元素的个数
参数4:待排序数组中元素的个数
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-30
**************************************/
static void MergePair(int *array, int *tempArray, const size_t pairwiseNum, const size_t num)
{
	assert(array);
	
	/*****************************
	*groupIndex : 每组的首元素下标
	*****************************/
	size_t groupIndex = 0;

	/*****************************************
	 *此处应有等号，当元素个数恰为当前分组整数
	 *倍时，groupIndex+2*pairwiseNum 就为num，
	 *此时最后一个分组理应排序，所以有等号
	******************************************/
	while(groupIndex+2*pairwiseNum <= num)
	{
		MergeArray(array, groupIndex, groupIndex+pairwiseNum-1, groupIndex+2*pairwiseNum-1, tempArray);
		groupIndex += 2*pairwiseNum;
	}
	
	/******************************************************
	 *前边两两归并，若共奇数个分组，则最后就会剩一个分组，
	 *当最后剩下的这个分组中元素的个数比pairwiseNum大时，
	 *对最后剩下的这些元素再进行一次归并；
	 *作者原代码中左侧表达式用 groupIndex+pairwiseNum-1 
	 *本人觉得 -1 没必要
	******************************************************/
	if(groupIndex+pairwiseNum < num)
		MergeArray(array, groupIndex, groupIndex+pairwiseNum-1, num-1, tempArray);
}


/***********************************************************
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
*************************************************************/
static void MergeArray(int *array, const size_t first, const size_t mid, const size_t end, int *tempArray)
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

