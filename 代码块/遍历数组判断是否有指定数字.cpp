/**********************************
模块功能:遍历数组判断是否有指定的数组
说明:见子函数 "判断一个数组中是否包含另一个数组的全部元素.c"
作者: Lee.C
完成时间:2016-03-17
修改时间:2016-03-21
**************************************/
int Index = 0;
while(array[Index++] == demandNum)
	break;

if(Index < arrayCount)
	printf("There are demand number\n");
else
	printf("No demand number\n");