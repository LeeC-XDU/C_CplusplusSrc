#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


bool InitStack(SqStack *S)
{
	S->top = -1;
	memset(S->data, 0, MAXSIZE * sizeof(Item));
	return true;
}


bool isEmptyStack(const SqStack *S)
{
	if(S->top == -1)
		return true;
	else
		return false;
}

bool isFullStack(const SqStack *S)
{
	if(S->top == MAXSIZE-1)
		return true;
	else
		return false;
}

void ClearStack(SqStack *S)
{
	S->top = -1;
	memset(S->data, 0, MAXSIZE * sizeof(Item));
}


bool GetTopItem(const SqStack *S, Item *e)
{
	if(S->top == -1)
	{
		puts("The stack is empty!");
		return false;
	}

	(*e) = S->data[S->top];
	return true;
}

bool Push(SqStack *S, const Item *e)
{
	if(S->top == MAXSIZE-1)
	{
		puts("The stack is full!");
		return false;
	}
	
	//由于初试状态是 -1，所以要先加1，再用
	S->data[++S->top] = (*e);
	return true;
}

bool Pop(SqStack *S, Item *e)
{
	if(S->top == -1)
	{
		puts("The stack is empty!");
		return false;
	}
	
	(*e) = S->data[S->top--];

	return true;
}
