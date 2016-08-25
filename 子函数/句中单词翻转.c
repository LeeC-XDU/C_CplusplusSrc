/********************************************
函数功能:句中单词翻转
参数1(Output):待翻转字符串句子
返回值:无
说明:两个while的重叠形式，注意结束条件的判定
头文件:无
作者: Lee.C
完成时间:2016-07-21
**********************************************/
void ReverseString1(char *s)
{
	int start = 0, end = 1;

	while(s[end-1])
	{
		while(s[end] != ' ' && s[end])
			end++;
		
		//循环结束完，指向的是单词结尾的空格
		Reverse(s, start, end-1);
		//指向下一个单词的开头
		end++;
		start = end;
	}
	Reverse(s, 0, strlen(s)-1);
}

/********************************************
函数功能:句中单词翻转
参数1(Output):待翻转字符串句子
返回值:无
说明:while中用if进行判断~
头文件:<stting.h>
作者: Lee.C
完成时间:2016-07-21
**********************************************/
void ReverseString2(char *s)
{
	if(!s)
		return;

	int start = 0;
	int end = strlen(s)-1;

	//翻转整个单词
	Reverse(s, start, end);

	start = end = 0;
	while(s[start])
	{
		if(s[start] == ' ')
		{
			start++;
			end++;
		}
		else if(s[end] == ' ' || s[end] == '\0')
		{
			Reverse(s, start, --end);
			start = ++end;
		}
		else
			end++;
	}
}

/********************************************
函数功能:单词翻转
参数1(Output):待翻转字符串句子
参数2:待翻转单词的起点下标
参数3:待翻转单词的末尾下标
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-07-21
**********************************************/
void Reverse(char *s, int from, int end)
{
	char t;
	
	if(!s || from <0 || end <0)
		return;

	while(from < end)
	{
		t = s[from];
		s[from++] = s[end];
		s[end--] = t;
	}
}