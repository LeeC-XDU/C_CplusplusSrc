#ifndef _LINKLIST__
#define _LINKLIST__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifndef _STATUS__
#define _STATUS__
typedef enum { FALSE, TRUE } Status;
#endif

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

Status InitList(LinkList *L);
Status DestoryList(LinkList *L, void (*FreeLinkListItem)(LinkListItem *e));

Status CreateListHead(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));
Status CreateListTail(LinkList *L, size_t num, void (*InPut)(LinkListItem *e));

Status ClearList(LinkList *L, void (*FreeLinkListItem)(LinkListItem *e));
Status IsEmptyList(const LinkList L);
size_t ListLength(const LinkList L);


void InsertLinkListItem(LinkList *L, size_t n, const LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));
void DeleteLinkListItem(LinkList *L, size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));

void GetLinkListItem(const LinkList L, size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src));
size_t LinkListLocateItem(const LinkList L, const LinkListItem *e, int (*Compare)(const LinkListItem *linkListElem, const LinkListItem *elem));
void TraverLinkList(LinkList L, void (*pfun)(LinkListItem *e));

void ReverseLinkListRecursion(LNode *p, LinkList *L);
void ReverseLinkList(LinkList *L);

#ifdef __cplusplus
}
#endif

#endif