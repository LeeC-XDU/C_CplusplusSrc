#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


static BiTree ConstuctCorePre(BiTreeItem *startPreorder, BiTreeItem *endPreorder, BiTreeItem *startInorder, BiTreeItem *endInorder);
static BiTree ConstuctCorePost(BiTreeItem *startPostorder, BiTreeItem *endPostorder, BiTreeItem *startInorder, BiTreeItem *endInorder);
static Status DoesTree1HaveTree2(BiTree treeRoot1, BiTree treeRoot2);


/**********************************
函数功能:前序递归创建二叉树
参数1(Output):二叉树根节点指针
参数2:函数指针，指明输入方式
返回值:无
说明:函数指针读到定界符时返回假
作者: Lee.C
完成时间:2016-05-18
**************************************/
void CreateBiTree(BiTree *T, Status (*Input)(BiTreeItem *e))
{
	BiTreeItem elem;
	//读入结束标记符时返回false，返回
	if(!Input(&elem))
	{
		*T = NULL;
		return;
	}
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	if(!*T)
	{
		fputs("Call CreateBiTree() error, memory allocation error\n", stderr);
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
参数1:二叉树根节点指针
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

/**********************************
函数功能:前序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void PreOrderTraverseStack1(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;

	InitStack(&S);

	while(currentNode || !StackIsEmpty(&S))
	{
		while(currentNode)
		{
			(*pfun)(&currentNode->data);
			Push(&S, &currentNode);
			currentNode = currentNode->lchild;
		}
		//此时的currentNode为NULL，说明左子树遍历完成，该遍历右子树了
		if(!StackIsEmpty(&S))
		{
			//获取栈顶元素，并将其弹出栈
			Pop(&S, &currentNode);
			currentNode = currentNode->rchild;
		}
	}

	DestoryStack(&S);
}

/**********************************
函数功能:前序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void PreOrderTraverseStack2(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;

	InitStack(&S);

	while(currentNode || !StackIsEmpty(&S))
	{
		if(currentNode)
		{
			(*pfun)(&currentNode->data);
			Push(&S, &currentNode);
			currentNode = currentNode->lchild;
		}
		else
		{
			Pop(&S, &currentNode);
			currentNode = currentNode->rchild;
		}
	}

	DestoryStack(&S);
}

/**********************************
函数功能:前序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void PreOrderTraverseStack3(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;

	InitStack(&S);

	Push(&S, &currentNode);

	while(!StackIsEmpty(&S))
	{
		(*pfun)(&currentNode->data);

		//访问节点之前先保存其右子树节点
		if(currentNode->rchild)
			Push(&S, &currentNode->rchild);

		//一直向左走，直到抵达叶子节点，
		//当到达叶子节点时，直接出栈就是右子树节点
		if(currentNode->lchild)
			currentNode = currentNode->lchild;
		else
			Pop(&S, &currentNode);
	}

	DestoryStack(&S);
}


/**********************************
函数功能:中序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void InOrderTraverseStack1(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;

	InitStack(&S);

	while(currentNode || !StackIsEmpty(&S))
	{
		//左子树节点一直压栈
		while(currentNode)
		{
			Push(&S, &currentNode);
			currentNode = currentNode->lchild;
		}
		//此时的currentNode为NULL，说明左子树遍历完成，
		//该操作“根节点”和遍历右子树了
		if(!StackIsEmpty(&S))
		{
			//获取栈顶元素，并将其弹出栈,此元素就是"根节点"
			Pop(&S, &currentNode);
			(*pfun)(&currentNode->data);
			currentNode = currentNode->rchild;
		}
	}

	DestoryStack(&S);
}

/**********************************
函数功能:中序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void InOrderTraverseStack2(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;

	InitStack(&S);

	while(currentNode || !StackIsEmpty(&S))
	{
		if(currentNode)
		{
			Push(&S, &currentNode);
			currentNode = currentNode->lchild;
		}
		else
		{
			Pop(&S, &currentNode);
			(*pfun)(&currentNode->data);
			currentNode = currentNode->rchild;
		}
	}

	DestoryStack(&S);
}

/**********************************
函数功能:后序遍历二叉树（非递归）
参数1:二叉树根节点指针
参数2:函数指针，指明对每个节点元素进行的操作
返回值:无
说明:
作者: Lee.C
完成时间:2016-08-15
**************************************/
void PostOrderTraverseStack(BiTree T, void(*pfun)(BiTreeItem *))
{
	if(T == NULL)
		return;

	SqStack S;
	BiTNode *currentNode = T;
	BiTNode *preNode = NULL;

	InitStack(&S);

	//一直向左走，并压栈，直到抵达叶子节点
	while(currentNode)
	{
		Push(&S, &currentNode);
		currentNode = currentNode->lchild;
	}

	while(!StackIsEmpty(&S))
	{
		//提取当前子树的"根节点"
		Pop(&S, &currentNode);
		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if(currentNode->rchild == NULL || currentNode->rchild == preNode)
		{
			(*pfun)(&currentNode->data);
			preNode = currentNode;
		}

		/********************************************************
		  可改为  else if(currentNode->lchild == preNode)
		  若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		*********************************************************/
		else
		{
			// "根节点"重新入栈。
			Push(&S, &currentNode);
			//转到右孩子
			currentNode = currentNode->rchild;
			while(currentNode)
			{
				Push(&S, &currentNode);
				currentNode = currentNode->lchild;
			}
		}
	}

	DestoryStack(&S);
}

/**********************************
函数功能:求二叉树深度
参数:二叉树根节点指针
返回值:无
说明:二叉树的深度
作者: Lee.C
完成时间:2016-08-15
**************************************/
int BiTreeDepth(BiTree T)
{

	int dleft, dright, depth;

    if(!T)
		depth = 0;
	else
	{
		//一直遍历左子树,遍历完成后,开始遍历右子树
		dleft = BiTreeDepth(T->lchild);	
		dright = BiTreeDepth(T->rchild);
		depth = (dleft>dright ? dleft : dright) + 1;
	}

    return depth;
}

/******************************************************
函数功能:由二叉树的前序遍历和中序遍历序列构建二叉树结构
参数1:前序递归数组
参数2:中序遍历数组
参数3:数组元素个数
返回值:树根节点指针
说明:
作者: Lee.C
完成时间:2016-08-15
**********************************************************/
BiTree BiTreeReConstructPre(BiTreeItem *preOrder, BiTreeItem *inOrder, int length)
{
    if(!preOrder || !inOrder || length < 0)
        return NULL;

    return ConstuctCorePre(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

/**************************************************************
函数功能:由二叉树的前序遍历和中序遍历序列构建二叉树结构主程序
参数1:前序遍历分组指向首元素的指针
参数2:前序遍历分组指向末尾元素的指针
参数3:中序遍历分组指向首元素的指针
参数4:中序遍历分组指向末尾元素的指针
返回值:树根节点指针
说明:
作者: Lee.C
完成时间:2016-08-15
******************************************************************/
static BiTree ConstuctCorePre(BiTreeItem *startPreorder, BiTreeItem *endPreorder, BiTreeItem *startInorder, BiTreeItem *endInorder)
{
    /**************************************************
     * rootValue           : 保存"分组根节点"的值
     * rootInorder         : 指向中序数组中"分组根节点"的指针
     * root                : 根节点指针，用于返回的
     * leftTreeLength      : 左子树中所含节点的个数
     * leftTreePreorderEnd : 指向左子树分组中的末尾节点的指针
    ***************************************************/
    //前序遍历第一个点是节点的值
    BiTreeItem rootValue = *startPreorder;
    BiTreeItem *rootInorder = NULL;
    BiTNode *root = (BiTNode*)malloc(sizeof(BiTNode));
    int leftTreeLength = 0;
    BiTreeItem *leftTreePreorderEnd = NULL;

    root->data = rootValue;
    root->lchild = root->rchild = NULL;

    /*********************************************
     这部分是用于结束递归的，当一个分组中只有一个
     元素了，即startPreorder与endPreorder两个指针重合时，
     便可以返回了，其实一个条件就可以了，但那是在输入
     合法的前提下，若输入不合法，则三个条件不可能同时
     满足，所以这里用了三个检测条件，用于判否的。
    *********************************************/
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
        {
            fputs("Called BiTreeReConstruct() error(1).\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    rootInorder = startInorder;
    //找到中序遍历分组中"根节点"的位置
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        fputs("Called BiTreeReConstruct() error(2).\n", stderr);
        exit(EXIT_FAILURE);
    }

    leftTreeLength = rootInorder - startInorder;
    leftTreePreorderEnd = startPreorder + leftTreeLength;

    //递归构建左子树
    if(leftTreeLength > 0)
        root->lchild = ConstuctCorePre(startPreorder+1, leftTreePreorderEnd, startInorder, rootInorder-1);
    //递归构建右子树
    if(leftTreeLength < endPreorder-startPreorder)
        root->rchild = ConstuctCorePre(leftTreePreorderEnd+1, endPreorder, rootInorder+1, endInorder);

    return root;
}

/******************************************************
函数功能:由二叉树的前序遍历和中序遍历序列构建二叉树结构
参数1:前序递归数组
参数2:中序遍历数组
参数3:数组元素个数
返回值:树根节点指针
说明:
作者: Lee.C
完成时间:2016-08-15
**********************************************************/
BiTree BiTreeReConstructPost(BiTreeItem *postOrder, BiTreeItem *inOrder, int length)
{
    if(!postOrder || !inOrder || length < 0)
        return NULL;

    return ConstuctCorePost(postOrder, postOrder+length-1, inOrder, inOrder+length-1);
}

/**************************************************************
函数功能:由二叉树的后序遍历和中序遍历序列构建二叉树结构主程序
参数1:后序遍历分组指向首元素的指针
参数2:后序遍历分组指向末尾元素的指针
参数3:中序遍历分组指向首元素的指针
参数4:中序遍历分组指向末尾元素的指针
返回值:树根节点指针
说明:是前一个程序的镜像对照
作者: Lee.C
完成时间:2016-08-15
******************************************************************/
static BiTree ConstuctCorePost(BiTreeItem *startPostorder, BiTreeItem *endPostorder, BiTreeItem *startInorder, BiTreeItem *endInorder)
{
    /**********************************************************************
     * rootValue               : 保存"分组根节点"的值
     * rootInorder             : 指向中序数组中"分组根节点"的指针
     * root                    : 根节点指针，用于返回的
     * rightTreeLength         : 右子树中所含节点的个数
     * rightTreePostorderStart : 指向右子树分组中的末尾节点的指针
    ***********************************************************************/
    //前序遍历第一个点是节点的值
    BiTreeItem rootValue = *endPostorder;
    BiTreeItem *rootInorder = NULL;
    BiTNode *root = (BiTNode*)malloc(sizeof(BiTNode));
    int rightTreeLength = 0;
    BiTreeItem *rightTreePostorderStart = NULL;

    root->data = rootValue;
    root->lchild = root->rchild = NULL;

    if(startPostorder == endPostorder)
    {
        if(startInorder == endInorder && *startPostorder == *startInorder)
            return root;
        else
        {
            fputs("Called BiTreeReConstruct() error(1).\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    rootInorder = startInorder;
    //找到中序遍历分组中"根节点"的位置
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        fputs("Called BiTreeReConstruct() error(2).\n", stderr);
        exit(EXIT_FAILURE);
    }

    rightTreeLength = endInorder - rootInorder;
    rightTreePostorderStart = endPostorder - rightTreeLength;

    if(rightTreeLength > 0)
        root->rchild = ConstuctCorePost(rightTreePostorderStart, endPostorder-1, rootInorder+1, endInorder);
    if(rightTreeLength < endPostorder-startPostorder)
        root->lchild = ConstuctCorePost(startPostorder, rightTreePostorderStart-1, startInorder, rootInorder-1);

    return root;
}


/*******************************
函数功能:判断树2是否是树1的子树
参数1:树1
参数2:树2
返回值:是返回真，否则返回假
说明:递归实现，二叉树遍历来匹配根节点
     根节点匹配后，调用函数递归匹配其子结构
作者: Lee.C
完成时间:2016-08-16
********************************/
Status HasSubTree(BiTree treeRoot1, BiTree treeRoot2)
{
	Status result = FALSE;
	
	if(treeRoot1 && treeRoot2)
	{
		if(treeRoot1->data == treeRoot2->data)
			result = DoesTree1HaveTree2(treeRoot1, treeRoot2);
		
		if(!result)
			result = HasSubTree(treeRoot1->lchild, treeRoot2);
		if(!result)
			result = HasSubTree(treeRoot1->rchild, treeRoot2);
	}
	
	return result;
}

/****************************************************
函数功能:递归查看根节点值相同的两个子树结构是否一致
参数1:树1
参数2:树2
返回值:是返回真，否则返回假
说明:递归实现
作者: Lee.C
完成时间:2016-08-16
*****************************************************/
static Status DoesTree1HaveTree2(BiTree treeRoot1, BiTree treeRoot2)
{
	if(!treeRoot2)
		return TRUE;
	
	if(!treeRoot1)
		return FALSE;
	
	if(treeRoot1->data != treeRoot2->data)
		return FALSE;
	
	return DoesTree1HaveTree2(treeRoot1->lchild, treeRoot2->rchild) && DoesTree1HaveTree2(treeRoot1->rchild, treeRoot2->rchild);
}


/**********************************
函数功能:二叉树的递归翻转(递归版)
参数1:树的递归翻转节点
返回值:无
说明:把除 NULL 节点以外的节点的左右子树对调即可以
作者: Lee.C
完成时间:2016-08-17
************************************/
void MirrorRecursively(BiTNode *pNode)
{
	if(pNode == NULL)
		return;
	if(pNode->lchild == NULL && pNode->rchild == NULL)
		return;

	BiTNode *pTemp = pNode->lchild;
	pNode->lchild = pNode->rchild;
	pNode->rchild = pTemp;

	if(pNode->lchild)
		MirrorRecursively(pNode->lchild);

	if(pNode->rchild)
		MirrorRecursively(pNode->rchild);
}