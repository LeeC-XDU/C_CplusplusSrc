/**********************************
函数功能:数组数据全排列
参数1:待排序字符串
返回值:无
说明:递归实现
头文件:无
作者: Lee.C
完成时间:2016-08-18
**************************************/
void AllPermutation(char* Str)
{
	if(!Str)
		return;

	int length = strlen(Str);

	AllPermutation_aux(Str, 0, length-1);
}

/**********************************
函数功能:递归排序主程序
参数1:待排序字符串
参数2:排序起始下标
参数3:排序终止下标
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-08-18
**************************************/
void AllPermutation_aux(char *Str, int begin, int end)
{
	int i=0;

	if(begin == end)
	{
		//do something
		//这里把整个字符串打印了出来，也可以将其保存在一个vector中
		printf("%s\n", Str);
	}
	else
	{
		for(i=begin; i<=end; i++)
		{
			Swap(&Str[begin], &Str[i]);
			AllPermutation_aux(Str, begin+1, end);
			Swap(&Str[begin], &Str[i]);
		}
	}
}


/**********************************
函数功能:交换程序
参数1:待交换数据1
参数2:待交换数据2
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-08-18
**************************************/
void Swap(char *ch1, char *ch2)
{
	char temp;

	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}