#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

int Flag=0;

/**************************
��������:��ʼ������,
�������:����ָ��
�������:����ָ��
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

//�������Ҳ������²�ϸ�ڵĺ���
void SetHeadNode(Item *e)
{
	e->a = 0;
	e->c = '\0';
}

/***********************************
��������:��������,��Ҫ�Ļ����ٴ洢��ͬλ�õ�ָ��
�������:����ָ��,λ��ָ��
�������:����ָ��,λ��ָ��
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

	//�Ȱ��������ٺ�,��ʵ�����漰�²�����ϸ�ڲ����ģ���Ӧ����һ���������Һ���ָ�봫��ķ�ʽ����!
	pnew->data=e;				//���������ֵ����֧���˽ṹ��ȸ������ͣ������ڴ�û���ú���ָ�롣
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
	unsigned int j=1;	//j��¼���ĸ��ڵ㣬�ӵ�1���ڵ�����


	while(current && j<i-1)	//������iΪ������+1ʱ,��������ͬʱ������,��������,��һ�������Ȳ�����
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

	while(current && j<i)	//������һ��3��Ԫ�أ���i=4ʱ������ͬʱ�����㣬����i>4ʱ������current����������ˡ�
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
��������:��λ������ƥ��Ԫ�صĲ���������ƥ���Ԫ�ص�λ������һ���������
�������:����ָ��
�������:ƥ���Ԫ�ص�λ������
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