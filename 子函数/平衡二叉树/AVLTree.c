#include "AVLTree.h"
#include <stdlib.h>
#include <assert.h>

static void RRotate(AVLTree *T);
static void LRotate(AVLTree *T);

/**********************************
函数功能:两点简单右旋
参数1(Output):指向旋转点的指针
返回值:无
说明:补充节点，分析好步骤，
     详细参见平衡二叉树笔记
作者: Lee.C
完成时间:2016-05-25
**************************************/
static void RRotate(AVLTree *T)
{
	assert(*T);

	AVLTNode *LeftNode = (*T)->lchild;
	(*T)->lchild = LeftNode->rchild;
	LeftNode->rchild = *T;
	*T = LeftNode;
}

/**********************************
函数功能:两点简单左旋
参数1(Output):指向旋转点的指针
返回值:无
说明:补充节点，分析好步骤，
     详细参见平衡二叉树笔记
作者: Lee.C
完成时间:2016-05-25
**************************************/
static void LRotate(AVLTree *T)
{
	assert(*T);

	AVLTNode *RightNode = (*T)->rchild;
	(*T)->rchild = RightNode->lchild;
	RightNode->lchild = *T;
	*T = RightNode;
}

/************************************************
函数功能:左平衡调整，结构右旋
参数1(Output):指向最小非平衡子树根节点的指针
返回值:无
说明:最小非平衡子树各节点的平衡因子也已经为不平衡状态；
     (*T)的bf已经是LH了
作者: Lee.C
完成时间:2016-05-25
****************************************************/
void LeftBalance(AVLTree *T)
{
	assert(*T);

	/*************************************************************
	 *LeftNode      : 指向最小非平衡子树根节点的左子树
	 *LeftRightNode : 指向最小非平衡子树根节点的左子树下的右子树
	**************************************************************/
	AVLTNode *LeftNode = NULL, *LeftRightNode = NULL;
	LeftNode = (*T)->lchild;

	switch(LeftNode->bf)
	{
		case LH:  /* LL型 */
			(*T)->bf = LeftNode->bf = EH;
			RRotate(T);
			break;
		case EH:
			break;
		case RH:  /* LR型 */
			LeftRightNode = LeftNode->rchild;
			switch(LeftRightNode->bf)
			{
				case LH:
					(*T)->bf = RH;
					LeftNode ->bf = EH;
					break;
				case EH:
					(*T)->bf = EH;
					LeftNode->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					LeftNode->bf = LH;
					break;
			}
			LeftRightNode->bf = EH;
			LRotate(&(*T)->lchild);
			RRotate(T);
			break;
	}
}

/************************************************
函数功能:右平衡调整，结构左旋
参数1(Output):指向最小非平衡子树根节点的指针
返回值:无
说明:最小非平衡子树各节点的平衡因子也已经为不平衡状态
     (*T)的bf已经是RH了
作者: Lee.C
完成时间:2016-05-25
****************************************************/
void RightBalance(AVLTree *T)
{
	assert(*T);
	
	/*************************************************************
	 *RightNode     : 指向最小非平衡子树根节点的右子树
	 *RightLeftNode : 指向最小非平衡子树根节点的右子树下的左子树
	**************************************************************/
	AVLTNode *RightNode = NULL, *RightLeftNode = NULL;
	RightNode = (*T)->rchild;

	switch(RightNode->bf)
	{
		case RH:  /* RR型 */
			(*T)->bf = RightNode->bf = EH;
			LRotate(T);
			break;
		case EH:
			break;
		case LH:  /* RL型 */
			RightLeftNode = RightNode->lchild;
			switch(RightLeftNode->bf)
			{
				case LH:
					(*T)->bf = EH;
					RightNode->bf  = RH;
					break;
				case EH:
					(*T)->bf = EH;
					RightNode->bf = EH;
					break;
				case RH:
					(*T)->bf = LH;
					RightNode->bf = EH;
					break;
			}
			RightLeftNode->bf = EH;
			RRotate(&(*T)->rchild);
			LRotate(T);
			break;
	}
}


/************************************************
函数功能:平衡二叉树节点元素插入
参数1(Output):指向平衡二叉树根节点的指针
参数2待插入元素
参数3:指示当前树是否长高
参数4:函数指针，指明树中两元素比较的方式
返回值:树中无此元素，插入新元素成功，返回TRUE；
       树中已有此元素，不进行插入操作，返回FALSE
说明:程序分析见平衡二叉树笔记
作者: Lee.C
完成时间:2016-05-26
****************************************************/
Status InsertAVLItem(AVLTree *T, const AVLTreeItem *e, Status *taller, int (*Compare)(const AVLTreeItem *e1, const AVLTreeItem *e2))
{
	//记录Compare()比较元素大小的结果
	int sign = 0;

	if(!*T)
	{
		*T = (AVLTNode*)malloc(sizeof(AVLTNode));
		(*T)->data = *e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
		return TRUE;
	}
	
	sign = Compare(e, &(*T)->data);
	if(sign == 0)
	{
		*taller = FALSE;
		return FALSE;
	}
	else if(sign < 0)
	{
		if(!InsertAVLItem(&(*T)->lchild, e, taller, Compare)) /* 未插入 */
			return FALSE;
		//已插入到左子树且左子树长高了
		if(*taller)
		{
			switch((*T)->bf)
			{
				case LH:
					LeftBalance(T);
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = TRUE;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
			}
		}
		return TRUE;
	}
	else
	{
		if(!InsertAVLItem(&(*T)->rchild, e, taller, Compare)) /* 未插入 */
			return FALSE;
		//已插入到右子树且右子树长高了
		if(*taller)
		{
			switch((*T)->bf)
			{
				//原本左子树高，现因右子树插入节点，左右子树平衡了
				case LH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				//原本左右子树等高，现因右子树增高而树增高了，但树仍平衡
				case EH:
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				//原本右子树高，现因右子树插入节点，破坏了平衡，需右平衡调整，调整后树的高度就不增加了
				case RH:
					RightBalance(T);
					*taller = FALSE;
					break;
			}
		}
		return TRUE;
	}
}
