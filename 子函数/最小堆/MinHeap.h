#ifndef _MINHEAP__
#define _MINHEAP__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define MINHEAP_INCREMENT 10

typedef int MinHeapItem;

typedef struct MinHeap
{
	MinHeapItem *heap;
	size_t length;		/* 堆中元素个数 */
	size_t heapSize;	/* 堆存储空间的大小 */
}MinHeap;

void CreateMinHeap(MinHeap *H, const int *array, size_t num);
void InsertMinHeapItem(MinHeap *H, const MinHeapItem *e);
void DeleteMinHeapItem(MinHeap *H);

void MinHeapSort(int *array, size_t num);


#ifdef __cplusplus
}
#endif


#endif
