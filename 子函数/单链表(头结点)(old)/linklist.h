#ifndef _LINKLIST__
#define _LINKLIST__

typedef struct Item
{
	int a;
	char c;
}Item;

typedef struct LNode
{
	Item data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList *L);
void SetHeadNode(Item *e);
int DestoryList(LinkList *L,int **locate);

//这个创建链表函数没有统一的形式吧
void CreateList(LinkList L,Item e);

int ListIsEmpty(LinkList L);
void InsertItem(LinkList L,unsigned int i,Item e); 
void DeleteItem(LinkList L,unsigned int i);
unsigned int ListLength(LinkList L);
Item GetItem(LinkList L,unsigned int i);
void ReplaceItem(LinkList L,unsigned int i,Item e);
unsigned int LocateItem(LinkList L,Item e,unsigned int **locate,int (*compare)(Item,Item));
void FunList(LinkList L,void (*pfun)(Item));
void LinkSort(LinkList L,int (*compare)(Item,Item));


#endif
