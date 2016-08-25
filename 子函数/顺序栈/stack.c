#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************************
函数功能:初始化栈，分配初始空间，建立一个空栈
参数1(Output):栈指针
返回值:初始化成功返回1，失败返回0
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
Status InitStack(SqStack *S)
{
	S->base = (StackItem *)malloc(STACK_INIT_SIZE * sizeof(StackItem));
	if(!S->base)
	{
		fputs("Call InitStack() error, memory allocation error\n", stderr);
		exit(EXIT_FAILURE);
	}
	memset(S->base, 0, STACK_INIT_SIZE * sizeof(StackItem));
	S->top = S->base;
	S->stackSize = STACK_INIT_SIZE;

	return TRUE;
}

/**************************************************
函数功能:销毁栈，释放栈空间
参数1(Output):栈指针
返回值:销毁成功返回1，失败返回0
说明:S->top是相对于S->base的栈偏移量，
     不是一个新的分配空间，无需释放
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
Status DestoryStack(SqStack *S)
{
	//此三条判断是否有有效的空间可用
	assert(S);
	assert(S->base);
	assert(S->top);
	
	
	//无需释放栈顶指针，它与栈底指针本质是一个
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	
	S->stackSize = 0;

	return TRUE;
}


/**************************************************
函数功能:清空栈
参数1(Output):栈指针
返回值:无
说明:只清空栈中数据，不销毁栈空间，top指针归‘零’
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
void ClearStack(SqStack *S)
{
	//此三条判断是否有有效的空间可用
	assert(S);
	assert(S->base);
	assert(S->top);
	
	memset(S->base, 0, S->stackSize * sizeof(StackItem));
	S->top = S->base;

}

/**************************************************
函数功能:判断栈是否为空
参数1:栈指针
返回值:为空返回1，不为空返回0
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
Status StackIsEmpty(const SqStack *S)
{
	assert(S);
	
	if(S->base == S->top)
		return TRUE;
	else
		return FALSE;
}


/**************************************************
函数功能:求栈中元素个数
参数1:栈指针
返回值:栈中元素个数
说明:
作者: Lee.C
完成时间:2016-05-16
**************************************************/
size_t StackLength(const SqStack *S)
{
	//此三条判断是否指针指向有效的空间
	assert(S);
	assert(S->base);
	assert(S->top);
	
	return (size_t)(S->top-S->base);
}


/**************************************************
函数功能:获得栈顶元素
参数1:栈指针
参数2(Output):返回元素
返回值:无
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
void GetTop(const SqStack *S, StackItem *e)
{
	//此三条判断是否指针指向有效的空间
	assert(S);
	assert(S->base);
	assert(S->top);
	//不能是空栈
	assert(S->base != S->top);

	(*e) = *(S->top-1);
}


/**************************************************
函数功能:压栈
参数1(Output):栈指针
参数2:待压栈元素
返回值:无
说明:
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
**************************************************/
void Push(SqStack *S, const StackItem *e)
{
	//此三条判断是否指针指向有效的空间
	assert(S);
	assert(S->base);
	assert(S->top);
	
	if(S->top-S->base >= S->stackSize)
	{
		S->base = (StackItem*)realloc(S->base, (S->stackSize+STACK_INCREMENT) * sizeof(StackItem));
		if(!S->base)
		{
			fputs("Call Push() error, memory allocation error\n", stdout);
			exit(EXIT_FAILURE);
		}
		S->top = S->base + S->stackSize;
		S->stackSize += STACK_INCREMENT;
	}

	*S->top++ = *e;

}


/**************************************************
函数功能:出栈，并返回出栈元素
参数1(Output):栈指针
参数2(Output):出栈元素
返回值:无
说明:e可以接受NULL
作者: Lee.C
完成时间:2015-05-10
修改时间:2016-05-16
修改说明:代码重构
修改时间:2016-07-17
修改说明:不想传出元素时，使e可以赋值为空
**************************************************/
void Pop(SqStack *S, StackItem *e)
{
	//此三条判断是否指针指向有效的空间
	assert(S);
	assert(S->base);
	assert(S->top);
	//不能是空栈
	assert(S->base != S->top);
	
	S->top--;
	
	if(e)
		(*e) = *S->top;
}
