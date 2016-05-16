#ifndef __STACK_
#define __STACL_

//本栈不能动态的调整栈的大小，栈的最大长度在栈定义的时候就指定了，
//在使用过程中，压入栈的元素不能超过这个最大长度，超过最大程度报错

//ANSI C(C98)才需要这个头文件，C++等不需要
#include "stdbool.h"


#define MAXSIZE 100

/*
typedef struct item
{
	int a;
}Item;
*/
typedef char Item;

typedef struct stack
{
	Item data[MAXSIZE];
	int top;
}SqStack;


bool InitStack(SqStack *S);

bool isEmptyStack(const SqStack *S);
bool isFullStack(const SqStack *S);
void ClearStack(SqStack *S);

bool GetTopItem(const SqStack *S, Item *e);

bool Push(SqStack *S, const Item *e);
bool Pop(SqStack *S, Item *e);



#endif