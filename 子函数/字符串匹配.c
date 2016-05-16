/**********************************
函数功能:朴素字符串匹配算法
参数1:主串
参数2:匹配串
参数3:主串中需要开始匹配的索引
返回值:主串中匹配子串的首元素索引,不匹配返回零
说明: 包含 string.h
作者: Lee.C
完成时间:2015.6.7
修改时间:2016-04-30
修改说明:由口述位置改为索引下标
**************************************/
int Index(char *S, char *T, int pos)
{
	//i表示主串S的索引，j表示子串T的索引
	int i = pos, j = 0;
	while(i<strlen(S) && j<strlen(T))
	{
		if(S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			//失匹配时，i指向下一个位置，j退回到T的开头
			i = i-j+1;
			j = 0;
		}
	}
	
	if(j>=strlen(T))
		return i-strlen(T);
	else
		return 0;
}

/**********************************
函数功能:KMP算法匹配字符串
参数1:主串
参数2:匹配串
参数3:主串中需要开始匹配的索引
返回值:主串中匹配子串的首元素索引,不匹配返回零
说明: 包含 string.h stdlib.h
作者: Lee.C
完成时间:2015.6.7
修改时间:2015-04-30
修改说明:由口述位置改为索引下标
         next长度一次性分配
**************************************/
int Index_KMP(char *S, char *T, int pos)
{
	int i = pos, j = 1;
	int *next  = (int*)malloc(strlen(T) * sizeof(int));

	get_next(T, next);
	
	while(i<strlen(S) && j<=strlen(T))
	{
		if(j == 0 || S[i] == T[j-1])
		{
			++i;
			++j;
		}
		else
			j = next[j-1];
	}
	
	free(next);
	
	if(j>strlen(T))
		return i-strlen(T);
	else
		return 0;
}

/**********************************
函数功能: next 函数值求值函数
参数1:模式串
参数2:输出参数,输出 next 值
返回值:无
说明: 包含 string.h stdlib.h
作者: Lee.C
完成时间:2015.6.7
修改时间:2015-04-30
修改说明:
**************************************/
void get_next(char *T, int *next)
{
	int i = 0, j = 0;

	next[i] = 0;
	
	while(i<strlen(T)-1)
	{
		if(j==0 || T[i] == T[j-1] )
		{
			++i;
			++j;

			next[i] = j;
		}
		else
			j = next[j-1];
	}
}

/**********************************
函数功能: 改进的 next 函数值求值函数
参数1:模式串
参数2:输出参数,输出 next 值
返回值:无
说明: 包含 string.h stdlib.h
作者: Lee.C
完成时间:2015.6.8
修改时间:2015-04-30
修改说明:
**************************************/
void get_nextval(char *T, int *nextval)
{
	int i = 0, j = 0;

	nextval[i] = 0;
	
	while(i<strlen(T)-1)
	{
		if(j==0 || T[i] == T[j-1] )
		{
			++i;
			++j;

			if(T[i] != T[j-1])
				nextval[i] = j;
			else
				nextval[i] = nextval[j-1];
		}
		else
			j = nextval[j-1];
	}
}