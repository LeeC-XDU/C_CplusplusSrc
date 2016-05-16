#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int InitStack(SqStack *S)
{
	S->top=NULL;	//ֱ������д�Ϳ��ԣ���malloc(0),�������������ֲ��
	S->base=NULL;
	S->stacksize=0;

	return true;
}

int DestoryStack(SqStack *S)
{
	free(S->base);		//�����ͷ�ջ��ָ�룬����ջ��ָ�뱾����һ��

	return true;
}

int StackIsEmpty(SqStack S)
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

void ClearStack(SqStack *S)	//���겢���³�ʼ����ջ
{
	free(S->base);

	S->top=NULL;
	S->base=NULL;
	S->stacksize=0;
}

Item GetTop(SqStack S)
{
	if(StackIsEmpty(S))
	{
		printf("The stack is empty!\n");
		exit(0);
	}

	return *(S.top-1);
}

void Push(SqStack *S,Item e)
{
	if(! S->base)
	{
		S->base=(Item*)malloc(2*sizeof(Item));		//������������ռ�,һ����ջ������,һ����ջ��
		S->top=S->base;								//����,��Ϊһ��������Ҳ�������Ч���ݵĿռ�
	}
	else
	{
		S->base=(Item*)realloc(S->base,(S->stacksize+2)*sizeof(Item));
		S->top=S->base+S->stacksize;
	}
	
	*S->top++=e;
	S->stacksize++;
}

Item Pop(SqStack *S)
{
	if(StackIsEmpty(*S))
	{
		printf("The stack is empty!\n");
		exit(0);
	}
	S->stacksize--;

	return *--S->top;
}

void FunStack(SqStack S,void (*pfun)(Item))
{
	while(S.base!=S.top)
		(*pfun)(*S.base++);
}
