#ifndef _LINKLIST__
#define _LINKLIST__

#include <stddef.h>

typedef struct LinkListItem
{
	char name[20];
	int number;
	char gender;
}LinkListItem;

typedef struct LNode
{
	Item data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList *L);
int DestoryList(LinkList *L);

int CreateListHead(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));
int CreateListTail(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));

int IsEmptyList(const LinkList L);
size_t ListLength(const LinkList L);
int ClearList(LinkList *L);



void InsertLinkListItem(LinkList *L, size_t n, Item e); 
void DeleteItem(LinkList *L, size_t i, Item e); 

Item GetItem(LinkList L,unsigned int i);
void ReplaceItem(LinkList L,unsigned int i,Item e);
unsigned int LocateItem(LinkList L,Item e,unsigned int **locate,bool (*compare)(Item,Item));
void FunList(LinkList L,void (*pfun)(Item));
void LinkSort(LinkList L,bool (*compare)(Item,Item));


#endif