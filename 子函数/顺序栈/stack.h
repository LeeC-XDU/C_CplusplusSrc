#ifndef __STACK_
#define __STACK_

#include <stddef.h>

/*
typedef struct item
{
	int a;
}Item;
*/
typedef char Item;

typedef struct stack
{
	Item *base;
	Item *top;
	size_t stacksize;		//注意这个是记录的栈的长度呢还是栈的大小啊？
}SqStack;


int InitStack(SqStack *S);
int DestoryStack(SqStack *S);

int StackIsEmpty(SqStack S);
void ClearStack(SqStack *S);
size_t StackLength(SqStack);	//本人把栈的大小等同于栈的长度了，所以这个函数没用了

Item GetTop(SqStack S);	//这仅是得到栈顶元素，栈本身不变，出栈则栈的指针会发生变化

void Push(SqStack *S,Item e);
Item Pop(SqStack *S);

void FunStack(SqStack S,void (*pfun)(Item));


#endif