#ifndef _BITREE_H__
#define _BITREE_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STATUS__
#define _STATUS__
typedef enum { FALSE, TRUE } Status;
#endif

typedef char BiTreeItem;

typedef struct BiTNode
{
	BiTreeItem data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void CreateBiTree(BiTree *T, Status (*Input)(BiTreeItem *e));
void PreOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e));
void InOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e));
void PostOrderTraverse(const BiTree T, void(*pfun)(BiTreeItem *e));
int BiTreeDepth(BiTree T);

void PreOrderTraverseStack1(BiTree T, void(*pfun)(BiTreeItem *));
void PreOrderTraverseStack2(BiTree T, void(*pfun)(BiTreeItem *));
void PreOrderTraverseStack3(BiTree T, void(*pfun)(BiTreeItem *));
void InOrderTraverseStack1(BiTree T, void(*pfun)(BiTreeItem *));
void InOrderTraverseStack2(BiTree T, void(*pfun)(BiTreeItem *));
void PostOrderTraverseStack(BiTree T, void(*pfun)(BiTreeItem *));

BiTree BiTreeReConstructPre(BiTreeItem *preOrder, BiTreeItem *inOrder, int length);
BiTree BiTreeReConstructPost(BiTreeItem *postOrder, BiTreeItem *inOrder, int length);

Status HasSubTree(BiTree treeRoot1, BiTree treeRoot2);


#ifdef __cplusplus
}
#endif

#endif
