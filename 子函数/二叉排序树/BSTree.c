#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int DeleteNode(BSTNode **Node);

/*******************************************************
函数功能:以单个元素插入的方式创建二叉排序树
参数1(Output):二叉排序树
参数2:二叉排序树的元素数组
参数3:元素数组中元素的个数
参数4:函数指针，指明二叉排序树中两个元素的比较方式，
      用于传入内部函数
返回值:创建成功，返回1
说明:
作者: Lee.C
完成时间:2016-05-24
***********************************************************/
int CreateBSTree(BSTree *T, const BSTreeItem *array, const size_t num, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2))
{
	assert(array);
	
	size_t index = 0;

	for(index=0; index<num; index++)
		InsertBSTreeItem(T, &array[index], Compare);

	return 1;
}


/*******************************************************
函数功能:递归查找二叉排序树中是否存在元素key
参数1:二叉排序树
参数2:待查找元素
参数3:二叉排序树元素的双亲，初始传入NULL
参数4(Output):查找到key，ret为指向key的指针，
              没查找到，ret为最后访问的叶子节点的双亲
参数5:函数指针，指明二叉排序树中两个元素的比较方式
返回值:查找到，返回1
       未查找到，返回0
说明:
作者: Lee.C
完成时间:2016-05-24
***********************************************************/
int SearchBST(const BSTree T, const BSTreeItem *key, const BSTree parent, BSTree *ret, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2))
{
	assert(key);
	
	
	if(!T)
	{
		//未查找到，此时T为NULL，
		//*ret指向最后访问的叶子节点
		*ret = parent;
		return 0;
	}
	else if(Compare(key, &T->data))
	{
		*ret = T;
		return 1;
	}
	else if(Compare(key, &T->data))
		return SearchBST(T->lchild, key, parent, ret, Compare);
	else
		return SearchBST(T->rchild, key, parent, ret, Compare);
}


/*******************************************************
函数功能:向二叉排序树中插入一个元素
参数1(Output):二叉排序树
参数2:待插入元素
参数3:函数指针，指明二叉排序树中两个元素的比较方式
返回值:插入成功，返回1
       插入失败，返回0
说明:当二叉排序树中没有此元素时才插入，返回1；
     二叉排序树中存在此元素时，返回0
作者: Lee.C
完成时间:2016-05-24
***********************************************************/
int InsertBSTreeItem(BSTree *T, const BSTreeItem *key, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2))
{
	assert(key);
	
	/******************************************
	 *insertLocation : 指明待被插入的位置
	                   指向某个叶子节点的指针
	 *insertNode : 待插入的节点
	******************************************/
	BSTree insertLocation = NULL;
	BSTNode *insertNode = NULL;

	if(!SearchBST(*T, key, NULL, &insertLocation, Compare))
	{
		insertNode = (BSTNode*)malloc(sizeof(BSTNode));
		if(!insertNode)
		{
			fputs("Call InsertBSTreeItem() error, memory allocation error\n", stdout);
			exit(EXIT_FAILURE);
		}
		insertNode->data = (*key);
		insertNode->lchild = insertNode->rchild = NULL;
		if(!insertLocation)
			*T = insertNode;
		else if(Compare(key, &insertLocation->data))
			insertLocation->lchild = insertNode;
		else
			insertLocation->rchild = insertNode;

		return 1;
	}

	return 0;
}


/*******************************************************
函数功能:删除二叉排序树中的指定节点
参数1(Output):二叉排序树
参数2:待删除元素
参数3:函数指针，指明二叉排序树中两个元素的比较方式
返回值:删除指定元素，返回1;
	   无指定元素，删除失败，返回0
说明:此函数结构与 SearchBST() 函数完全一致，
     只把指定元素与树中元素相等时的操作变了
作者: Lee.C
完成时间:2016-05-24
***********************************************************/
int DeleteBSTItem(BSTree *T, const BSTreeItem *key, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2))
{
	assert(key);
	
	
	if(!*T)
		return 0;
	else if(Compare(key, &(*T)->data))
		return DeleteNode(T);

	if(Compare(key, &(*T)->data))
		return DeleteBSTItem(&(*T)->lchild, key, Compare);
	else
		return DeleteBSTItem(&(*T)->rchild, key, Compare);
}


/*******************************************************
函数功能:删除二叉排序树中节点，重接左右子树
参数1(Output):指向二叉排序树待删除的节点的指针
返回值:删除调整成功，返回1;
说明:传入的形参并不是指针副本，而是双亲节点指针域的指针自身，
     完全等价于传入了要操作节点双亲节点的指针。
     本函数是用待被删除节点的前驱来替换删除节点的
作者: Lee.C
完成时间:2016-05-24
***********************************************************/
static int DeleteNode(BSTNode **Node)
{
	assert(*Node);

	BSTNode *parentNode = *Node; 
	BSTNode *priorNode = NULL; 

	//右子树为空直接重接左子树
	if(!(*Node)->rchild)
	{
		*Node = (*Node)->lchild;
		free(parentNode);
	}
	//左子树为空，直接重接右子树
	else if((*Node)->lchild)
	{
		*Node = (*Node)->rchild;
		free(parentNode);
	}
	else
	{
		//以下操作是用待被删除节点的前驱节点来替换本节点的
		//先左转再一直向右找
		priorNode = (*Node)->lchild;
		while(priorNode->rchild)
		{
			parentNode = priorNode;
			priorNode = priorNode->rchild;
		}
		(*Node)->data = priorNode->data;

		if(parentNode!= *Node)
			//重接右子树
			parentNode->rchild = priorNode->lchild;
		else
			//重接左子树
			parentNode->lchild = priorNode->lchild;

		free(priorNode);
	}
	
	return 1;
}
