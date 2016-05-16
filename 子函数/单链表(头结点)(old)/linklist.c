#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

int Flag=0;

/**************************
函数功能:初始化链表,
输入参数:链表指针
输出参数:链表指针
***************************/
int InitList(LinkList *L)
{
	(*L)=(LNode *)malloc(sizeof(LNode));
	if(!*L)
	{
		printf("Call InitList() ERROR !\n");
		exit(0);
	}

	SetHeadNode(&(*L)->data);
	(*L)->next = NULL;
	
	return true;
}

//这个函数也是设计下层细节的函数
void SetHeadNode(Item *e)
{
	e->a = 0;
	e->c = '\0';
}

/***********************************
函数功能:销毁链表,必要的话销毁存储相同位置的指针
输入参数:链表指针,位置指针
输出参数:链表指针,位置指针
******************************************/
int DestoryList(LinkList *L,int **locate)
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

void CreateList(LinkList L,Item e)
{
	LinkList current=L;
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


	while(current->next)
		current=current->next;
	current->next=pnew;
}

int ListIsEmpty(LinkList L)
{
	if(!L->next)
		return true;
	else
		return false;
}

void InsertItem(LinkList L,unsigned int i,Item e)
{
	LinkList current=L->next;
	LNode *pnew;
	unsigned int j=1;	//j记录着哪个节点，从第1个节点算起


	while(current && j<i-1)	//这样在i为链表长度+1时,两个条件同时不满足,若是链表长,后一个条件先不满足
	{
		current=current->next;
		j++;
	}
	
	
	if(!current || j>i-1)
	{
		printf("Call InsertItem() ERROR(3) !\n");
		printf("The List`s length is %u,the insert location %u is overflow\n",ListLength(L),i);
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


void DeleteItem(LinkList L,unsigned int i)
{
	LinkList current=L,temp;
	unsigned int j=0;

	if(ListIsEmpty(L))
	{
		printf("The List is none,call DeleteItem() ERROR !(1)\n");
		exit(0);
	}
	

	while(current->next && j<i-1)
	{
		current=current->next;
		j++;
	}

	if(!current->next || j>i-1)
	{
		printf("Call DeleteItem() ERROR!(2)\n");
		printf("The List`s length is %u,the delete location %u is overflow\n",ListLength(L),i);
		exit(0);
	}
	
	temp=current->next;	
	current->next=temp->next;
	free(temp);

}

void FunList(LinkList L,void (*pfun)(Item))
{
	LinkList current=L->next;
	while(current)
	{
		(*pfun)(current->data);
		current=current->next;
	}
}

unsigned int ListLength(LinkList L)
{
	unsigned int length=0;
	LinkList current=L->next;

	while(current)
	{
		length++;
		current=current->next;
	}

	return length;
}


Item GetItem(LinkList L,unsigned int i)
{
	LinkList current=L->next;
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
unsigned int LocateItem(LinkList L,Item e,unsigned int** locate,int (*compare)(Item,Item))
{
	LinkList current=L->next;
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
		printf("The List`s length is %u,the replace location %u is overflow\n",ListLength(L),i);
		exit(0);
	}

	current->data=e;
}


void LinkSort(LinkList L,int (*compare)(Item,Item))
{
	LinkList current=L->next;
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