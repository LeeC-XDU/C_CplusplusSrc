#ifndef _BSTREE_H__
#define _BSTREE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef int BSTreeItem;

typedef struct BSTNode
{

	BSTreeItem data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


int CreateBSTree(BSTree *T, const BSTreeItem *array, const size_t num, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2));
int SearchBST(const BSTree T, const BSTreeItem *key, const BSTree parent, BSTree *ret, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2));
int InsertBSTreeItem(BSTree *T, const BSTreeItem *key, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2));
int DeleteBSTItem(BSTree *T, const BSTreeItem *key, int (*Compare)(const BSTreeItem *e1, const BSTreeItem *e2));

#ifdef __cplusplus
}
#endif

#endif
