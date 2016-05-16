#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int InitStack(SqStack *S)
{
	S->top=NULL;	//直接这样写就可以，用malloc(0),或许更有利于移植。
	S->base=NULL;
	S->stacksize=0;

	return true;
}

int DestoryStack(SqStack *S)
{
	free(S->base);		//无需释放栈顶指针，它与栈底指针本质是一个

	return true;
}

int StackIsEmpty(SqStack S)
{
	if(S.base==S.top)
		return true;
	else
		return false;
}

void ClearStack(SqStack *S)	//销魂并重新初始化了栈
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
		S->base=(Item*)malloc(2*sizeof(Item));		//这里分配两个空间,一个给栈底数据,一个给栈顶
		S->top=S->base;								//数据,作为一个合理的且不分配有效数据的空间
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
