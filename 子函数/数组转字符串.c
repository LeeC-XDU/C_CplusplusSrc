/**********************************
函数功能:把整形数组转换为字符串形式
参数1:整形数组
参数2:数组元素个数
返回值:字符串的首地址
说明:在函数内动态分配内存，在主函数中注意内存释放
     特殊符号'*'视情况而换
所需标准库文件:string.h
作者: Lee.C
完成时间:2015-12-23
修改时间:
**************************************/
char* intToStr(const int *array, const unsigned int count)
{
	unsigned int i = 0;
	char strTemp[5] = {0};
	unsigned int cn = 0, len = 0;
	char *str = (char*)malloc(1*sizeof(char));
	//为了在第一位进行拼接
	str[0] = '\0';

	for(i=0; i<count-1; i++)
	{
		cn = sprintf(strTemp,"%u", array[i]);
		//这里要和下边联合控制len的值，下边的+1是为末尾'\0'预留的；
		len += cn+1;	//这里的+1，是为'*'的，因为每次都有*，但'\0'只会有一个
		str = (char*)realloc( str,(len+1)*sizeof(char) );
		strncat(str,strTemp,cn);
		strcat(str,"*");	//视情况而换
	}
	cn = sprintf(strTemp,"%u", array[i]);
	len += cn+1;
	str = (char*)realloc( str,(len+1)*sizeof(char) );
	strncat(str,strTemp,cn);

	return str;
}


/**********************************
函数功能:把整形数组转换为字符串形式
参数1:(输出参数)转换后的字符串
参数2:整形数组
参数3:数组元素个数
返回值:无
说明:在函数内动态分配内存，在主函数中注意内存释放
     特殊符号'*'视情况而换
所需标准库文件:string.h
作者: Lee.C
完成时间:2015-12-23
修改时间:
**************************************/
void intToStr(char *str, const unsigned int *array, const unsigned int count)
{
	char tempStr[5] = {0};
	unsigned int i = 0;
	
	//为实现在第一个位置进行拼接
	if(str[0])
	{
		str[0] = '\0';
	}

	for(i=0; i<count-1; i++)
	{
		sprintf(tempStr, "%u", array[i]);
		strcat(str, tempStr);
		strcat(str, "*");	//视情况而换
	}
	sprintf(tempStr, "%u", array[i]);
	strcat(str, tempStr);
}