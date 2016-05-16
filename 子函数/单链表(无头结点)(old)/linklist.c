#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

int Flag=0;

/**************************
函数功能:初始化链表
输入参数:链表指针
输出参数:链表指针
***************************/
bool InitList(LinkList *L)
{
	(*L)=(LNode *)malloc(sizeof(LNode));
	if(!*L)
	{
		printf("Call InitList() ERROR !\n");
		exit(0);
	}
	*L=NULL;
	return true;
}

/***********************************
函数功能:销毁链表,必要的话销毁存储相同位置的指针
输入参数:链表指针,位置指针
输出参数:链表指针,位置指针
说明：这个函数写的不对吧，对有无头结点的情况，若为空链表，(*L)就为NULL，怎能指向next，可以加一句判断是否是空链表哈
******************************************/
bool DestoryList(LinkList *L,int **locate)
{
	LinkList current=*L;
	while((*L)->next)
	{
		current=(*L)->next;
		free(*L);
		*L=current;
	}

	if(Flag==1)
	{
		free(*locate);
		Flag=0;
	}
	return true;
}

void CreateList_(LinkList *L,Item e)
{
	LinkList current=*L;
	LNode *pnew;
	
	pnew=(LNode*)malloc(sizeof(LNode));
	if(!pnew)
	{
		printf("Call CreateList() ERROR !\n");
		exit(0);
	}

	//先把数据整顿好,其实凡是涉及下层数据细节操作的，都应该有一个函数，且函数指针传入的方式进行!
	pnew->data=e;				//但是这个赋值操作支持了结构体等复杂类型，所以在此没有用函数指针。
	pnew->next=NULL;

	//然后再把它放进链表
	if(!current)
		*L=pnew;
	else
	{
		while(current->next)
			current=current->next;
		current->next=pnew;
	}
}

void CreateList(LinkList *L,bool (*PutData)(Item *))
{
	LNode *current,*tmp;
	Item e;
	
	(*PutData)(&e);
	
	*L=(LinkList)malloc(sizeof(LNode));
	(*L)->data=e;
	(*L)->next=NULL;
	
	tmp = *L;
	
	while((*PutData)(&e))
	{
	
		current=(LinkList)malloc(sizeof(LNode));
		current->data=e;
		current->next=NULL;
		
	
		tmp->next=current;

		tmp=current;
	}
}


bool ListIsEmpty(LinkList L)
{
	if(!L)
		return true;
	else
		return false;
}

void InsertItem(LinkList *L,unsigned int i,Item e)
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

void FunList(LinkList L,void (*pfun)(Item))
{
	LinkList current=L;
	while(current)
	{
		(*pfun)(current->data);
		current=current->next;
	}
}

unsigned int ListLength(LinkList L)
{
	unsigned int length=0;
	LinkList current=L;

	while(current)
	{
		length++;
		current=current->next;
	}

	return length;
}


Item GetItem(LinkList L,unsigned int i)
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
unsigned int LocateItem(LinkList L,Item e,unsigned int** locate,bool (*compare)(Item,Item))
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


void ReplaceItem(LinkList L,unsigned int i,Item e)
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


void LinkSort(LinkList L,bool (*compare)(Item,Item))
{
	LinkList current=L;
	Item temp;
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