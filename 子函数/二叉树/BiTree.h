#ifndef _BITREE_H__
#define _BITREE_H__


typedef char BiTreeItem;

typedef struct BiTNode
{
	BiTreeItem data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void CreateBiTree(BiTree *T, int(*Input)(BiTreeItem *e));
void PreOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e));
void InOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e));
void PostOrderTravese(const BiTree T, void(*pfun)(BiTreeItem *e));


#endif
