#ifndef _LINKLIST__
#define _LINKLIST__

typedef enum{false,true}bool;

typedef struct Item
{
	char name[20];
	int number;
	char gender;
}Item;

typedef struct LNode
{
	Item data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList *L);
bool DestoryList(LinkList *L,int **locate);

//这个创建链表函数没有统一的形式吧
void CreateList(LinkList *L,bool (*PutData)(Item *));
void CreateList_(LinkList *L,Item e);

bool ListIsEmpty(LinkList L);
void InsertItem(LinkList *L,unsigned int i,Item e); 
void DeleteItem(LinkList *L,unsigned int i);
unsigned int ListLength(LinkList L);
Item GetItem(LinkList L,unsigned int i);
void ReplaceItem(LinkList L,unsigned int i,Item e);
unsigned int LocateItem(LinkList L,Item e,unsigned int **locate,bool (*compare)(Item,Item));
void FunList(LinkList L,void (*pfun)(Item));
void LinkSort(LinkList L,bool (*compare)(Item,Item));


#endif