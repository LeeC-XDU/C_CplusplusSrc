#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**************************************************
函数功能:初始化链表，包括初始化头指针和头结点
参数1(Output):链表头指针
返回值:初始化成功返回1，失败返回0
说明:为头指针分配存储空间就是为整个链表创建头节点了
     头节点的数据域没存任何东西。
头文件: <stdlib.h>
        <stdio.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
Status InitList(LinkList *L)
{
	(*L) = (LNode *)malloc(sizeof(LNode));
	if(!*L)
	{
		fputs("Call InitList() ERROR !\n", stdout);
		exit(EXIT_FAILURE);
	}

	(*L)->next = NULL;
	
	return TRUE;
}


/**************************************************
函数功能:销毁链表
参数1(Output):链表头指针
参数2:函数指针，当LinkListItem中有需要动态分配内存的指针时调用，否则传入NULL
返回值:销毁成功返回1，失败返回0
说明:与清空链表不同，本函数把头结点的空间也释放了
头文件: <stdlib.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
Status DestoryList(LinkList *L, void (*FreeLinkListItem)(LinkListItem *e))
{
	LNode *current = NULL;
	while( *L )
	{
		current =(*L)->next;
		FreeLinkListItem(&(*L)->data);
		free(*L);
		*L = current;
	}

	return TRUE;
}

/**************************************************
函数功能:头插法创建链表
参数1:链表头指针
参数2:链表大小
参数3:函数指针，指出为链表数据赋值的方式
返回值:创建成功返回1，失败返回0
说明:
头文件: <assert.h>
        <stdlib.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
Status CreateListHead(LinkList L, size_t num, void (*InPut)(LinkListItem *e))
{
	//头插法必须要求头指针指向头节点且头节点的next为NULL
	assert( L );
	assert( !L->next );

	LNode *current = NULL;
	size_t i = 0;
	
	for(i=0; i<num; i++)
	{
		current = (LNode *)malloc(sizeof(LNode));
		InPut(&current->data);
		current->next = L->next;
		L->next = current;
	}
	
	return TRUE;
}

/**************************************************
函数功能:尾插法创建链表
参数1:链表头指针
参数2:链表大小
参数3:函数指针，指出为链表数据赋值的方式
返回值:创建成功返回1，失败返回0
说明:
头文件: <assert.h>
        <stdlib.h>
作者: Lee.C
完成时间:2016-05-04
**************************************************/
Status CreateListTail(LinkList L, size_t num, void (*InPut)(LinkListItem *e))
{
	//尾插法必须要求头指针指向头节点且头节点的next为NULL
	assert( L );
	assert( !L->next );

	/*******************************************
	 * current : 指向链表当前要操作节点的指针，
	 * prior : 指向current所指向的上一个节点的指针
	           初始值为链表头节点
	*******************************************/
	LNode *current = NULL;
	LNode *prior = L;
	size_t i = 0;
	
	for(i=0; i<num; i++)
	{
		current = (LNode *)malloc(sizeof(LNode));
		InPut(&current->data);
		prior->next = current;
		prior = current;
	}
	
	current->next = NULL;

	return TRUE;
}

/**************************************************
函数功能:清空链表
参数1:链表头指针
参数2:函数指针，当LinkListItem中有需要动态分配内存的指针时调用，否则传入NULL
返回值:清空成功返回1，失败返回0
说明:与销毁链表不同，本函数保留头节点
头文件: <assert.h>
        <stdlib.h>
作者: Lee.C
完成时间:2016-05-04
**************************************************/
Status ClearList(LinkList L, void (*FreeLinkListItem)(LinkListItem *e))
{
	assert( L );

	/*******************************************
	 * current : 指向链表当前要操作节点的指针，
	             初始值为链表第一个节点的指针
	 * posterior : 指向current所指向的下一个节点的指针
	*******************************************/
	LNode *current = L->next;
	LNode *posterrior = NULL;
	
	while( current )
	{
		posterrior = current->next;
		FreeLinkListItem(&current->data);
		free(current);
		current = posterrior;
	}
	
	//头节点的指针域设为空
	L->next = NULL;

	return TRUE;
}

/**************************************************
函数功能:判断链表是否是空
参数1:链表头指针
返回值:空返回1，非空返回0
说明:
头文件: <assert.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
Status IsEmptyList(const LinkList L)
{
	assert( L );

	if(!L->next)
		return TRUE;
	else
		return FALSE;
}

/**************************************************
函数功能:求链表长度
参数1:链表头指针
返回值:链表长度
说明:
头文件: <assert.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
size_t ListLength(const LinkList L)
{
	assert( L );

	size_t length = 0;
	
	//指向头节点的指针
	LNode *current = L->next;

	while(current)
	{
		length++;
		current = current->next;
	}

	return length;
}


/**************************************************
函数功能:插入元素
参数1:链表头指针
参数2:插入位置
参数3:插入元素
参数4:函数指针，指出为链表数据赋值的方式
返回值:
说明:插入位置从1开始，为第n个位置；
     在第n个位置插入，原第n个元素变为第n+1个。
     当链表为空链表时，也可以在第一个位置插入；
	 不能在第 ListLength(L)+1 处插入。
头文件: <assert.h>
        <stdlib.h>
		<stdio.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
void InsertLinkListItem(LinkList L, size_t n, const LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src))
{
	//不断言 L->next ，当只有头结点时，也可以在第一个位置插入元素
	assert(L);
	assert(n >= 1 && n <= ListLength(L));

	/*******************************************
	 * prior : 指向链表当前要插入节点位置的前一个节点，
	           初始值为指向链表头节点的指针
	 * current : 新分配的待插入的节点
	 * priorPos : 记录着哪个节点，从第1个节点算起
	*******************************************/
	LNode *prior = L;
	LNode *current = NULL;
	size_t priorPos = 1;


	//由于prior指向的是头节点，所以priorPos<n找到的是第n-1个节点
	//前一个条件保证可以最多只能指向链表最后一个节点
	while(prior && priorPos < n)
	{
		prior = prior->next;
		priorPos++;
	}
	
	
	if(!prior || priorPos > n)
	{
		fputs("Call InsertItem() ERROR(1) !\n",stdout);
		fprintf(stdout, "The List`s length is %lu,the insert location %lu is overflow\n", ListLength(L), n);
		exit(EXIT_FAILURE);
	}
		 
	current=(LNode *)malloc(sizeof(LNode));
	if(current == NULL)
	{
		fputs("Call InsertItem() ERROR(2) !\n", stdout);
		exit(EXIT_FAILURE);
	}

	Assgin(&current->data, e);
	current->next = prior->next;
	prior->next = current;

}


/**************************************************
函数功能:删除元素并返回删除元素的值
参数1:链表头指针
参数2:删除位置
参数3(Output):返回元素
参数4:函数指针，指出为数据赋值的方式
返回值:无
说明:删除位置从1开始，为第n个位置。
     当链表为空链表时，不能删除元素，所以在断言处比插入函数多了一句 assert(!L->next)；
头文件: <assert.h>
        <stdlib.h>
		<stdio.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
void DeleteLinkListItem(LinkList L, size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src))
{
	assert(L);
	assert(L->next);
	assert(n >= 1 && n <= ListLength(L));
	
	/*******************************************
	 * prior : 指向链表当前要插入节点位置的前一个节点，
	           初始值为指向链表头节点的指针
	 * current : 要删除的节点
	 * priorPos : 记录着哪个节点，从第1个节点算起
	*******************************************/
	LNode *prior = L, *current = NULL;
	size_t priorPos = 1;


	//前一个条件保证 prior 最多只能指向最后一个节点的前一个节点
	while(prior->next && priorPos < n)
	{
		prior = prior->next;
		priorPos++;
	}

	if(!prior->next || priorPos > n)
	{
		fputs("Call DeleteItem() ERROR!\n", stdout);
		fprintf(stdout, "The List`s length is %lu, the delete location %lu is overflow\n", ListLength(L), n);
		exit(EXIT_FAILURE);
	}
	
	current = prior->next;
	prior->next = current->next;
	Assgin(e, &current->data);
	free(current);

}


/**************************************************
函数功能:获取链表某一位置处的值
参数1:链表头指针
参数2:待获取元素的位置
参数3(Output):返回元素
参数4:函数指针，指出为数据赋值的方式
返回值:无
说明:
头文件: <assert.h>
        <stdlib.h>
		<stdio.h>
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
void GetLinkListItem(const LinkList L, size_t n, LinkListItem *e, void (*Assgin)(LinkListItem *dst, const LinkListItem *src))
{
	assert(L);
	assert(L->next);
	assert(n >= 1 && n <= ListLength(L));
	
	/*******************************************
	 * current : 指向链表待获取处的节点，
	             初始值为指向链表第一个元素的指针
	 * currentPos : 待获取处的节点位置，从第1个节点算起
	*******************************************/
	LNode *current = L->next;
	size_t currentPos = 1;

	while(current && currentPos < n)
	{
		current = current->next;
		currentPos++;
	}

	if(!current || currentPos > n)
	{
		fputs("Call GetItem() ERROR !\n", stdout);
		fprintf(stdout, "The List`s length is %lu,the get location %lu is overflow\n", ListLength(L), n);
		exit(EXIT_FAILURE);
	}

	Assgin(e, &current->data);
}


/**************************************************
函数功能:定位链表中第一个与指定元素匹配的位置
参数1:链表头指针
参数2:待匹配元素
参数3:函数指针，指出元素相等的方式
返回值:匹配成功返回第一个匹配的位置，失败返回0
说明:空链表直接返回0，所以未断言 L->next
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
size_t LinkListLocateItem(const LinkList L, const LinkListItem *e, int (*Compare)(const LinkListItem *linkListElem, const LinkListItem *elem))
{
	assert(L);
	assert(e);

	/*******************************************
	 * current : 指向链表待获取处的节点，
	             初始值为指向链表第一个元素的指针
	 * index : 匹配处的索引
	*******************************************/
	LNode *current = L->next;
	size_t index = 0;


	while(current)
	{
		index++;
		if(Compare(&current->data, e))
			return index;
		current = current->next;
	}

	return index;
}


/**************************************************
函数功能:链表遍历
参数1:链表头指针
参数2:函数指针，指出对每个链表元素进行的操作
返回值:无
说明:只要链表头指针不为空即可，所以只断言了L
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
void TraverLinkList(LinkList L, void (*pfun)(LinkListItem *e))
{
	assert(L);
	
	/*******************************************
	 * current : 指向链表待获取处的节点，
	             初始值为指向链表第一个元素的指针
	*******************************************/
	LNode *current = L->next;
	while(current)
	{
		(*pfun)(&current->data);
		current = current->next;
	}
}



/*
void ReplaceItem(LinkList L,unsigned int i,LinkListItem e)
{
	LinkList current=L->next;
	unsigned int j=1;

	while(current && j<i)
	{
		current=current->next;
		j++;
	}

	if(!current || j>i)
	{
		printf("Call ReplcarItem() ERROR !\n");
		printf("The List`s length is %lu,the replace location %lu is overflow\n",ListLength(L),i);
		exit(0);
	}

	current->data=e;
}


void LinkSort(LinkList L,int (*compare)(LinkListItem,LinkListItem))
{
	LinkList current=L->next;
	LinkListItem temp;
	unsigned int count=ListLength(L);
	unsigned int i,j;

	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if((*compare)(current->data,current->next->data))
			{
				temp=current->data;
				current->data=current->next->data;
				current->next->data=temp;
			}
			current=current->next;
		}
		current=L;
	}
}
*/