/*************************************************
函数功能:计数一个字符串中单词的个数
参数1:指向字符串指针
返回值:字符串中单词的个数
说明:只有即不是空白，且是从空白中出来时，才计数单词数，
     标志位就是用来设置后者条件的，本程序
	 标志位的使用和分支的控制较有技巧，很值得学习
头文件: <ctype.h>
        <stddef.h>
作者: Lee.C
完成时间:2016-07-02
************************************************/
size_t CountCol(const char *pChar)
{
	size_t retNum = 0;
	Status borderFlag = TRUE;

	while(*pChar)
	{
		if(isspace(*pChar))
			borderFlag = TRUE;
		//当字符不是空白且标志位已置位的情况下进入计数分支
		else if(borderFlag)
		{
			retNum++;
			borderFlag = FALSE;
		}

		pChar++;
	}

	return retNum;
}