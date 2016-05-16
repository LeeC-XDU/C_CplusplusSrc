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
	LinkListItem data;
	struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList *L);
int DestoryList(LinkList *L, void (*FreeLinkListItem)(LinkListItem *e));

int CreateListHead(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));
int CreateListTail(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));

int ClearList(LinkList *L, void (*FreeLinkListItem)(LinkListItem *e));
int IsEmptyList(const LinkList L);
size_t ListLength(const LinkList L);


void InsertLinkListItem(LinkList *L, const size_t n, const LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));
void DeleteLinkListItem(LinkList *L, const size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));

void GetLinkListItem(const LinkList L, const size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));
size_t LinkListLocateItem(const LinkList L, const LinkListItem *e, int (*Compare)(const LinkListItem *linkListElem, const LinkListItem *elem));
void TraverLinkList(LinkList L, void (*pfun)(LinkListItem *e));


#endif