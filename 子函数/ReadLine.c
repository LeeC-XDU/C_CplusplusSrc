/**********************************
函数功能:从屏幕上读取一行若干个数字组成的字符串，比如 1 2 4 56
         并将其解析为各个数字，保存在一个数组中
参数1(Output):解析成的各个数组
返回值:数组元素的个数
说明:
头文件:<stdio.h>
       <string.h>
	   <stdlib.h>
作者: Lee.C
完成时间:2016-09-10
修改时间:
修改说明:
**************************************/
int readLine(int outArr[])
{
	char tmpString[SIZE];
	char *endChar = NULL;
	char delims[] = " ";
	char *result = NULL;
	int count = 0;
	memset(tmpString, 0, SIZE);

	fgets(tmpString, SIZE, stdin);
	if((endChar = strchr(tmpString, '\n')) != NULL)
		*endChar = '\0';

	result = strtok(tmpString, delims);

	while(result)
	{
		outArr[count++] = atoi(result);
		result = strtok(NULL, delims);
	}

	return count;
}