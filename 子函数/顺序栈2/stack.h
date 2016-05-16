#ifndef __STACK_
#define __STACL_

//��ջ���ܶ�̬�ĵ���ջ�Ĵ�С��ջ����󳤶���ջ�����ʱ���ָ���ˣ�
//��ʹ�ù����У�ѹ��ջ��Ԫ�ز��ܳ��������󳤶ȣ��������̶ȱ���

//ANSI C(C98)����Ҫ���ͷ�ļ���C++�Ȳ���Ҫ
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