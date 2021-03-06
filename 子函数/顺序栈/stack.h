#ifndef __STACK_
#define __STACK_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifndef _STATUS__
#define _STATUS__
typedef enum { FALSE, TRUE } Status;
#endif

//存储空间的初始分配量
#define STACK_INIT_SIZE 100
//存储空间分配增量
#define STACK_INCREMENT 10

/*
typedef struct item
{
	int a;
}Item;
*/
typedef char StackItem;

typedef struct stack
{
	StackItem *base;
	StackItem *top;
	
	//记录栈中所占内存空间的大小
	size_t stackSize;
}SqStack;


Status InitStack(SqStack *S);
Status DestoryStack(SqStack *S);

void ClearStack(SqStack *S);
Status StackIsEmpty(const SqStack *S);
size_t StackLength(const SqStack *S);

void GetTop(const SqStack *S, StackItem *e);
void Push(SqStack *S, const StackItem *e);
void Pop(SqStack *S, StackItem *e);


#ifdef __cplusplus
}
#endif

#endif