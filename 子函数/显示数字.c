/**********************************
函数功能:以指定的列数显示一维数组的数字
参数1:一维数组
参数2:数组中所含元素的个数
参数3:每个数据元素的字长，一般是 sizeof(float)等
参数4:每行显示的个数(列数)
参数5:元素之间的分隔符
参数6:具体显示方式
返回值:无
所需标准库文件:stdio.h
说明:使用了 void* 可以传入任何种类的数组；用函数指针传入具体的显示操作，形参也用 void* 不能传入具体类型
     下附上了一个具体的函数指针的实现样子
作者: Lee.C
完成时间:2012-12-22
修改时间:2016-01-08
**************************************/
void showArray(const void *array, size_t num, size_t size, size_t cols, char ch, void (*print_)(void*))
{
	int index;
	char *p = (char*)array;

	for(index=0; index<num-1; index++)
	{
		print_(p);
		if(index % cols == cols-1 )
			putchar('\n');
		else
			putchar(ch);
		//无差别的地址，就看移动多少个字节代表下一个数字了
		p += size;
	}
	print_(p);
	putchar('\n');
}

//具体 print 的一个实例
void print(void *p)
{
	double*temp = (double *)p;

	printf("%9.4f", *temp);
}


/**********************************
函数功能:以指定的列数显示一维数组的数字
参数1:一维数组
参数2:数组中所含元素的个数
参数3:每行显示的个数(列数)
返回值:无
所需标准库文件:stdio.h; math.h
说明:旧版本
作者: Lee.C
完成时间:2015-12-22
修改时间:
**************************************/
void displayNum(float *array, const int number, const int cols)
{
	float temp = 0.0;
	int cn = 0, i = 0, j=0;
	int lineNum = 0;
	
	lineNum = (int)floor(number*1.0/cols);

	for(i=0; i<lineNum; i++)
	{
		for(j=0; j<cols-1; j++)
		{
			//这里可用*array，但用array[]更形象和好控
			printf("%10f,",array[cols*i+j]);
		}
		printf("%10f\n",array[cols*i+j]);
	}
	
	if( number%cols )
	{
		for(j=0; j<number%cols-1; j++)
			printf("%10f,",array[cols*i+j]);
		printf("%10f\n",array[cols*i+j]);
	}
}


