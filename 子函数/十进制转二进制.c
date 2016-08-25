/**********************************
函数功能:十进制数转二进制数（栈版）
参数1(Output):保存目标二进制数的数组
参数2:待转换的十进制数
返回值:转换成的二进制的个数
说明:动态分配内存保存转换后的二进制数，
     需要在外部调用free()函数
作者: Lee.C
头文件:<stdlib.h>
       "stack.h"
完成时间:2015-06-06
修改时间:2016-07-19
修改说明:内存动态分配
**************************************/
int toBinaryStack(int **dstArr, int decimalNum)
{
	SqStack S;
	int remainder = 0;
	int arrayNum = 0;
	int index = 0;

	InitStack(&S);

	//全部压栈完后再全部统一出栈
	while(decimalNum)
	{
		remainder = decimalNum % 2;
		Push(&S, &remainder);
		decimalNum /= 2;
	}
	
	arrayNum = StackLength(&S);
	*dstArr = (int*)malloc(arrayNum * sizeof(int));
	
	//全部元素统一出栈
	while(!StackIsEmpty(&S))
		Pop(&S, &(*dstArr)[index++]);
	
	DestoryStack(&S);
	
	return arrayNum;
}

/**********************************
函数功能:十进制转二进制（递归版）
参数1(Output):保存目标二进制数的数组
参数2:待转换的十进制数
参数3:dstArr的起始坐标，作为唯一副本
返回值:无
说明:由于递归，不能在内部为数组分配大小，
     所以该程序不如栈版灵活
作者: Lee.C
完成时间:2015-06-06
修改时间:2016-07-19
修改说明:引入保存唯一副本的指针变量
**************************************/
void toBinary(int *dstArr, int decimalNum, int *index)
{
	int remainder;
	
	remainder = decimalNum % 2;
	//用不为0作为结束条件，会多求一次余数
	if(decimalNum >= 2)
		toBinary(dstArr, decimalNum/2, index);
	
	dstArr[(*index)++] = remainder;
}