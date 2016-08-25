/**********************************
函数功能:朴素字符串匹配算法
参数1:主串
参数2:模式串
返回值:主串中匹配子串的首元素索引,不匹配返回零
说明:
头文件:<string.h>
作者: Lee.C
完成时间:2015-06-07
修改时间:2016-04-30
修改说明:代码重构
**************************************/
int StringMatch(char *S, char *T)
{
	int sLen = strlen(S);
	int tLen = strlen(T);

	int i = 0, j = 0;

	while(i<sLen && j<tLen)
	{
		if(S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if(j == tLen)
		return i - j;
	else
		return -1;
}

/**********************************
函数功能:KMP算法匹配字符串
参数1:主串
参数2:模式串
返回值:主串中匹配子串的首元素索引,不匹配返回零
说明:
头文件:<string.h>
       <stdlib.h>
作者: Lee.C
完成时间:2015-06-07
修改时间:2016-04-30
修改说明:代码重构
**************************************/
int KMPMatch(char *S, char *T)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(S);
	int tLen = strlen(T);
	int *next = (int*)malloc(tLen * sizeof(int));

	GetNextVal(T, next);

	while(i<sLen && j<tLen)
	{
		if(j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	free(next);

	if(j == tLen)
		return i - j;
	else
		return -1;
}

/**********************************
函数功能: next 函数值求值函数
参数1:模式串
参数2:输出参数,输出 next 值
返回值:无
头文件:<string.h>
作者: Lee.C
完成时间:2015-06-07
修改时间:2016-04-30
修改说明:代码重构
**************************************/
void GetNext(char *T, int *next)
{
	int tLen = strlen(T);
	next[0] = -1;
	int i = 0;
	int j = -1;
	while(i < tLen-1)
	{
		if(j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

/**********************************
函数功能:改进的 next 函数值求值函数
参数1:模式串
参数2:输出参数,输出 next 值
返回值:无
说明:
头文件:<string.h>
作者: Lee.C
完成时间:2015-06-07
修改时间:2016-04-30
修改说明:代码重构
**************************************/
void GetNextVal(char *T, int *next)
{
	int tLen = strlen(T);
	next[0] = -1;
	int i = 0;
	int j = -1;

	while(i < tLen-1)
	{
		if(j==-1 || T[i] == T[j])
		{
			i++;
			j++;

			if(T[i] != T[j-1])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
}