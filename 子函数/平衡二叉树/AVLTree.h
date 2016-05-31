#ifndef __AVLTREE_
#define __AVLTREE_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STATUS__
#define _STATUS__
typedef enum { FALSE, TRUE } Status;
#endif

typedef int AVLTreeItem;

typedef enum BFStatus
{
	RH = -1, EH, LH
}BFStatus;

typedef struct AVLTNode
{
	AVLTreeItem data;
	BFStatus bf;
	struct AVLTNode *lchild, *rchild;
}AVLTNode, *AVLTree;



void LeftBalance(AVLTree *T);
void RightBalance(AVLTree *T);


#ifdef __cplusplus
}
#endif


#endif
