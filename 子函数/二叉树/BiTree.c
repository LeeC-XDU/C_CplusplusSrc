#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>


/**********************************
函数功能:前序递归创建二叉树
参数1(Output):二叉树指针
参数2:函数指针，指明输入方式
返回值:无
说明:没有用函数指针来指明赋值的方式
作者: Lee.C
完成时间:2016-05-18
**************************************/
void CreateBiTree(BiTree *T, int(*Input)(BiTreeItem *e))
{
	BiTreeItem elem;
	if(Input(&elem))
	{
		*T = NULL;
		return;
	}
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	if(!*T)
	{
		fputs("Call CreateBiTree() error, memory allocation error\n", stdout);
		exit(EXIT_FAILURE);
	}
	(*T)->data = elem;
	CreateBiTree(&(*T)->lchild, Input);
	CreateBiTree(&(*T)->rchild, Input);
}

/**********************************
函数功能:前序遍历二叉树
参数1:二叉树指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-18
**************************************/
void PreOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e))
{
	if(T == NULL)
		return;
	pfun(&T->data);
	PreOrderTraverse(T->lchild, pfun);
	PreOrderTraverse(T->rchild, pfun);
}

/**********************************
函数功能:中序遍历二叉树
参数1:二叉树指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-18
**************************************/
void InOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e))
{
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild, pfun);
	pfun(&T->data);
	InOrderTraverse(T->rchild, pfun);
}

/**********************************
函数功能:后序遍历二叉树
参数1:二叉树指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-05-18
**************************************/
void PostOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e))
{
	if(T == NULL)
		return;
	PostOrderTraverse(T->lchild, pfun);
	PostOrderTraverse(T->rchild, pfun);
	pfun(&T->data);
}
