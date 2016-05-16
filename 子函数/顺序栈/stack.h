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
	size_t stacksize;		//ע������Ǽ�¼��ջ�ĳ����ػ���ջ�Ĵ�С����
}SqStack;


int InitStack(SqStack *S);
int DestoryStack(SqStack *S);

int StackIsEmpty(SqStack S);
void ClearStack(SqStack *S);
size_t StackLength(SqStack);	//���˰�ջ�Ĵ�С��ͬ��ջ�ĳ����ˣ������������û����

Item GetTop(SqStack S);	//����ǵõ�ջ��Ԫ�أ�ջ�����䣬��ջ��ջ��ָ��ᷢ���仯

void Push(SqStack *S,Item e);
Item Pop(SqStack *S);

void FunStack(SqStack S,void (*pfun)(Item));


#endif