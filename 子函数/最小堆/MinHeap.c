#include "MinHeap.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void MinHeapFixup(MinHeap *H, const size_t index);
static void MinHeapFixdown(MinHeap *H, const size_t index);

/**********************************
函数功能:用任意序数组创建最小堆
参数1(Output):最小堆
参数2:用于创建堆的数组
参数3:数组元素个数
返回值:无
说明:这里是用int型数组初始化堆的，可以换其他类型，
     应与头文件中的MinHeapItem类型对应
头文件:<assert.h>
作者: Lee.C
完成时间:2015-05-29
**************************************/
void CreateMinHeap(MinHeap *H, const int *array, size_t num)
{
	assert(array);
	
	/**************************************
	 *index : 代表当前操作的节点的索引下边，
	          初始值为最后一个节点双亲节点的下标。
	***************************************/
	int index = (num-2) / 2;

	H->heapSize = num;
	H->length = num;

	H->heap = (MinHeapItem*)malloc(H->heapSize * sizeof(MinHeapItem));
	memcpy(H->heap, array, H->heapSize*sizeof(MinHeapItem));
	
	while(index >= 0)
	{
		MinHeapFixdown(H, index);
		index--;
	}
}


/**********************************
函数功能:最小堆节点插入
参数1(Output):最小堆
参数2:待插入元素
返回值:无
说明:只能插入到堆的最末尾，然后再调整;
     堆内数组空间不够时要进行扩容。
作者: Lee.C
完成时间:2016-05-29
**************************************/
void InsertMinHeapItem(MinHeap *H, const MinHeapItem *e)
{
	assert(H);
	assert(e);

	if(H->length == H->heapSize)
		H->heap = (MinHeapItem*)realloc(H->heap, (H->heapSize+MINHEAP_INCREMENT) * sizeof(MinHeapItem));

	//在堆的最后一个位置插入元素，并向上调整
	H->heap[H->length] = (*e);
	MinHeapFixup(H, H->length);

	H->length++;
}


/**********************************
函数功能:最小堆节点删除
参数1(Output):最小堆
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-29
**************************************/
void DeleteMinHeapItem(MinHeap *H)
{
	assert(H);
	
	//删除第一个位置的元素，把最后一个元素拿上来，并向下调整
	H->heap[0] = H->heap[--H->length];
	MinHeapFixdown(H, 0);
}


/**********************************
函数功能:最小堆排序
参数1(Output):待排序数组
参数2:待排序数组元素个数
返回值:无
说明:这里是对int型数组进行排序的，可以换其他类型，
     应与头文件中的MinHeapItem类型对应；
	 最小堆实现的是数组递减排序，递增排序请使用最大堆。
作者: Lee.C
完成时间:2016-05-29
**************************************/
void MinHeapSort(int *array, const size_t num)
{
	assert(array);
	
	MinHeap H;
	MinHeapItem temp;
	size_t index = num - 1;
	CreateMinHeap(&H, array, num);
	
	while(index >= 1)
	{
		temp = H.heap[0];
		H.heap[0] = H.heap[index];
		H.heap[index] = temp;
		
		H.length = index;
		MinHeapFixdown(&H, 0);
		
		index--;
	}
	
	memcpy(array, H.heap, H.heapSize * sizeof(MinHeapItem));
}

/**********************************
函数功能:最小堆节点向上调整
参数1(Output):最小堆
参数2:待调整节点的下标索引
返回值:无
说明:从index节点向上调整；
     由于有递减的循环，且判断条件为 >= 0，
     所以此处的索引用的是int类型而非size_t类型。
作者: Lee.C
完成时间:2015-05-29
**************************************/
static void MinHeapFixup(MinHeap *H, size_t index)
{
	assert(H);

	/*************************************
	 *currentIndex : 当前节点索引
	 *parentIndex  : 当前节点双亲节点索引
	 *fixupValue   : 待调整节点值
	**************************************/
	int currentIndex = index;
	int parentIndex = (currentIndex-1) / 2;
	MinHeapItem fixupValue = H->heap[currentIndex];

	//插入排序基本思想
	while(parentIndex>=0 && fixupValue < H->heap[parentIndex])
	{
		if(H->heap[parentIndex] <= fixupValue)
			break;

		//双亲节点的值较大，不断把上边的大值拿下来替换当前节点值
		H->heap[currentIndex] = H->heap[parentIndex];
		currentIndex = parentIndex;
		parentIndex = (currentIndex - 1) / 2;
	}

	H->heap[currentIndex] = fixupValue;
}


/**********************************
函数功能:最小堆节点向下调整
参数1(Output):最小堆
参数2:待调整节点的下标索引
返回值:无
说明:从index节点向下调整；
作者: Lee.C
完成时间:2015-05-29
**************************************/
static void MinHeapFixdown(MinHeap *H, size_t index)
{
	assert(H);
	
	/*************************************
	 *currentIndex : 当前节点索引
	 *childIndex   : 当前节点左孩子节点的索引
	 *fixupValue   : 待调整节点值
	**************************************/
	size_t currentIndex = index;
	size_t childIndex = 2*currentIndex + 1;
	MinHeapItem fixdownValue = H->heap[currentIndex];

	while(childIndex < H->length)
	{
		//找左右孩子中最小的
		if(childIndex+1<H->length && H->heap[childIndex+1] < H->heap[childIndex])
			childIndex++;

		if(H->heap[childIndex] >= fixdownValue)
			break;

		//孩子节点的值较小，不断把下边的小值拿上来替换当前节点值
		H->heap[currentIndex] = H->heap[childIndex];
		currentIndex = childIndex;
		childIndex = 2*currentIndex + 1;
	}
	H->heap[currentIndex] = fixdownValue;
}
