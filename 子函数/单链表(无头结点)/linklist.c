#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**************************************************
函数功能:初始化链表
参数1(Output):链表头指针
返回值:初始化成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
int InitList(LinkList *L)
{
	(*L) = NULL;
	
	return 1;
}

/**************************************************
函数功能:销毁链表
参数1(Output):链表头指针
返回值:销毁成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
int DestoryList(LinkList *L)
{
	LinkList current = NULL;
	while((*L))
	{
		current =(*L)->next;
		free(*L);
		*L = current;
	}

	return 1;
}


/**************************************************
函数功能:头插法创建链表
参数1(Output):链表头指针
参数2:链表大小
参数3:函数指针，指出为链表数据赋值的方式
返回值:创建成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
int CreateListHead(LinkList *L, size_t num, void (*InPut)(LinkListItem *e))
{
	//头插法必须要求头指针为NULL
	assert(*L);
	
	LNode * current = NULL;
	size_t i = 0;
	
	(*L) = (LNode *)malloc(sizeof(LNode));
	InPut(&(*L)->data);
	(*L)->next = NULL;
	
	for(i=0; i<num-1; i++)
	{
		current = (LNode *)malloc(sizeof(LNode));
		InPut(&current->data);
		current->next = *L;
		*L = current;
	}
	
	return 1;
}

/**************************************************
函数功能:尾插法创建链表
参数1(Output):链表头指针
参数2:链表大小
参数3:函数指针，指出为链表数据赋值的方式
返回值:创建成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2016-05-04
修改时间:
修改说明:
**************************************************/
int CreateListTail(LinkList *L, size_t num, void (*InPut)(LinkListItem *e))
{
	//尾插法必须要求头指针为NULL
	assert(*L);

	/*******************************************
	 * current : 指向链表当前要操作节点的指针，
	 * prior : 指向current所指向的上一个节点的指针
	           初始值为链表头指针
	*******************************************/
	LNode * current = NULL;
	LNode * prior = NULL;
	size_t i = 0;
	
	(*L) = (LNode *)malloc(sizeof(LNode));
	InPut(&(*L)->data);
	(*L)->next = NULL;
	
	prior = *L;
	
	for(i=0; i<num-1; i++)
	{
		current = (LNode *)malloc(sizeof(LNode));
		InPut(&current->data);
		proir->next = current;
		prior = current;
	}
	
	current->next = NULL;

	return 1;
}


/**************************************************
函数功能:判断链表是否是空
参数1:链表头指针
返回值:清空成功返回1，失败返回0
说明:与销毁链表不同，本函数保留头指针的存储空间
作者: Lee.C
完成时间:2016-05-04
修改时间:
修改说明:
**************************************************/
int IsEmptyList(const LinkList L)
{
	if(!L)
		return 1;
	else
		return 0;
}

/**************************************************
函数功能:求链表长度
参数1:链表头指针
返回值:链表长度
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-04
修改说明:代码重构
**************************************************/
size_t ListLength(const LinkList L)
{
	size_t length = 0;
	
	LinkList current=L;

	while(current)
	{
		length++;
		current = current->next;
	}

	return length;
}


/**************************************************
函数功能:清空链表
参数1:链表头指针
返回值:清空成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2016-05-04
修改时间:
修改说明:
**************************************************/
int ClearList(LinkList *L)
{
	/*******************************************
	 * current : 指向链表当前要操作节点的指针，
	             初始值为链表第一个节点的指针
	 * posterior : 指向current所指向的下一个节点的指针
	*******************************************/
	LinkList current = *L;
	LinkList posterrior = NULL;
	
	while( current )
	{
		posterrior = current->next;
		free(current);
		current = posterrior;
	}
	
	*L = NULL;

	return 1;
}








void InsertLinkListItem(LinkList *L,unsigned int i,LinkListItem e)
{
	LinkList current=*L;
	LNode *pnew;
	unsigned int j=1;	//j记录着哪个节点，从第1个节点算起

	if(i == 1)
	{
		pnew=(LNode*)malloc(sizeof(LNode));
		if(pnew==NULL)
		{
			printf("Call InsertItem() ERROR(1) !\n");
			exit(0);
		}

		pnew->data=e;
		pnew->next=current;
		*L=pnew;
	}
	else
	{
		while(current && j<i-1)		//循环执行i-2次,current向后指向两次，指向第三个位置,j就指示current指向第几个
		{
			current=current->next;
			j++;
		}
		
		
		if(!current || j>i-1)
		{
			printf("Call InsertItem() ERROR(3) !\n");
			printf("The List`s length is %u,the insert location %u is overflow\n",ListLength(*L),i);
			exit(0);
		}
		 
		pnew=(LNode *)malloc(sizeof(LNode));
		if(pnew==NULL)
		{
			printf("Call InsertItem() ERROR(4) !\n");
			exit(0);
		}

		pnew->data=e;
		pnew->next=current->next;
		current->next=pnew;
	}
}

void DeleteItem(LinkList *L,unsigned int i)
{
	LinkList current=*L,temp;
	unsigned int j=1;

	if(ListIsEmpty(*L))
	{
		printf("The List is none,call DeleteItem() ERROR !(1)\n");
		exit(0);
	}
	
	if(i==1)
	{
		if(!current->next)
		{
			free(*L);
			*L=NULL;
		}
		else
		{
			*L=current->next;
			free(current);
		}
	}
	else
	{
		while(current && j<i-1)
		{
			current=current->next;
			j++;
		}

		if(!current->next || j>i-1)
		{
			printf("Call DeleteItem() ERROR!(2)\n");
			printf("The List`s length is %u,the delete location %u is overflow\n",ListLength(*L),i);
			exit(0);
		}
		
		temp=current->next;	
		current->next=temp->next;
		free(temp);
	}
}

void FunList(LinkList L,void (*pfun)(LinkListItem))
{
	LinkList current=L;
	while(current)
	{
		(*pfun)(current->data);
		current=current->next;
	}
}



LinkListItem GetItem(LinkList L,unsigned int i)
{
	LinkList current=L;
	unsigned int j=1;

	while(current && j<i)	//若链表一共3个元素，当i=4时，两者同时不满足，但当i>4时，就是current起决定作用了。
	{
		current=current->next;
		j++;
	}

	if(!current || j>i)
	{
		printf("Call GetItem() ERROR !\n");
		printf("The List`s length is %u,the get location %u is overflow\n",ListLength(L),i);
		exit(0);
	}

	return current->data;
}

/************************************************
函数功能:定位链表中匹配元素的操作，并将匹配的元素的位置生成一个数组输出
输入参数:链表指针
输出参数:匹配的元素的位置数组
***************************/
unsigned int LocateItem(LinkList L,LinkListItem e,unsigned int** locate,bool (*compare)(LinkListItem,LinkListItem))
{
	LinkList current=L;
	unsigned int count=0,j=1;

	*locate=(unsigned int*)malloc(count*sizeof(unsigned int));

	while(current)
	{
		if((*compare)(current->data,e))
		{
			*locate=(unsigned int*)realloc(*locate,++count*sizeof(unsigned int));
			(*locate)[count-1]=j;
		}
		current=current->next;
		j++;
	}

	Flag=1;

	return count;
}


void ReplaceItem(LinkList L,unsigned int i,LinkListItem e)
{
	LinkList current=L;
	unsigned int j=1;

	while(current && j<i)
	{
		current=current->next;
		j++;
	}

	if(!current || j>i)
	{
		printf("Call ReplcarItem() ERROR !\n");
		printf("The List`s length is %u,the replace location %u is overflow\n",ListLength(L),i);
		exit(0);
	}

	current->data=e;
}


void LinkSort(LinkList L,bool (*compare)(LinkListItem,LinkListItem))
{
	LinkList current=L;
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