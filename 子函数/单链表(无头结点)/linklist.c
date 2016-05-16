#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**************************************************
��������:��ʼ������
����1(Output):����ͷָ��
����ֵ:��ʼ���ɹ�����1��ʧ�ܷ���0
˵��:
����: Lee.C
���ʱ��:2015-05-10
�޸�ʱ��:2016-05-04
�޸�˵��:�����ع�
**************************************************/
int InitList(LinkList *L)
{
	(*L) = NULL;
	
	return 1;
}

/**************************************************
��������:��������
����1(Output):����ͷָ��
����ֵ:���ٳɹ�����1��ʧ�ܷ���0
˵��:
����: Lee.C
���ʱ��:2015-05-10
�޸�ʱ��:2016-05-04
�޸�˵��:�����ع�
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
��������:ͷ�巨��������
����1(Output):����ͷָ��
����2:�����С
����3:����ָ�룬ָ��Ϊ�������ݸ�ֵ�ķ�ʽ
����ֵ:�����ɹ�����1��ʧ�ܷ���0
˵��:
����: Lee.C
���ʱ��:2015-05-10
�޸�ʱ��:2016-05-04
�޸�˵��:�����ع�
**************************************************/
int CreateListHead(LinkList *L, size_t num, void (*InPut)(LinkListItem *e))
{
	//ͷ�巨����Ҫ��ͷָ��ΪNULL
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
��������:β�巨��������
����1(Output):����ͷָ��
����2:�����С
����3:����ָ�룬ָ��Ϊ�������ݸ�ֵ�ķ�ʽ
����ֵ:�����ɹ�����1��ʧ�ܷ���0
˵��:
����: Lee.C
���ʱ��:2016-05-04
�޸�ʱ��:
�޸�˵��:
**************************************************/
int CreateListTail(LinkList *L, size_t num, void (*InPut)(LinkListItem *e))
{
	//β�巨����Ҫ��ͷָ��ΪNULL
	assert(*L);

	/*******************************************
	 * current : ָ������ǰҪ�����ڵ��ָ�룬
	 * prior : ָ��current��ָ�����һ���ڵ��ָ��
	           ��ʼֵΪ����ͷָ��
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
��������:�ж������Ƿ��ǿ�
����1:����ͷָ��
����ֵ:��ճɹ�����1��ʧ�ܷ���0
˵��:����������ͬ������������ͷָ��Ĵ洢�ռ�
����: Lee.C
���ʱ��:2016-05-04
�޸�ʱ��:
�޸�˵��:
**************************************************/
int IsEmptyList(const LinkList L)
{
	if(!L)
		return 1;
	else
		return 0;
}

/**************************************************
��������:��������
����1:����ͷָ��
����ֵ:������
˵��:
����: Lee.C
���ʱ��:2015-05-10
�޸�ʱ��:2016-05-04
�޸�˵��:�����ع�
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
��������:�������
����1:����ͷָ��
����ֵ:��ճɹ�����1��ʧ�ܷ���0
˵��:
����: Lee.C
���ʱ��:2016-05-04
�޸�ʱ��:
�޸�˵��:
**************************************************/
int ClearList(LinkList *L)
{
	/*******************************************
	 * current : ָ������ǰҪ�����ڵ��ָ�룬
	             ��ʼֵΪ�����һ���ڵ��ָ��
	 * posterior : ָ��current��ָ�����һ���ڵ��ָ��
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
	unsigned int j=1;	//j��¼���ĸ��ڵ㣬�ӵ�1���ڵ�����

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
		while(current && j<i-1)		//ѭ��ִ��i-2��,current���ָ�����Σ�ָ�������λ��,j��ָʾcurrentָ��ڼ���
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