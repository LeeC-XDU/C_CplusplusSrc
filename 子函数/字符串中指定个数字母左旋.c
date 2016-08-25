/********************************************
函数功能:句中字母左旋
参数1(Output):待左旋字符串句子
参数2:左旋字符个数
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-07-21
**********************************************/
void LeftRotateString(char *s, int k)
{
	if(!s || k <= 0)
        return;

    int length = strlen(s);

    //当左移的位数大于字符串的长度时，移动k位与移动k%length位是等价的
	k = k % length;

	//旋转前半部分
	Reverse(s, 0, k-1);
	//旋转后半部分
	Reverse(s, k, length-1);
	//旋转整个字符串
	Reverse(s, 0, length-1);
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
完成时间:2013-07-21
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