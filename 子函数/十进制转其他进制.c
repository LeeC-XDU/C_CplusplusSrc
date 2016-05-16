/**********************************
函数功能:自定义栈方式非递归方式进行十进
		 制对其他进制(十进制以内)的转换
参数1:十进制数
参数2:输出参数,存储转换后的每一位数字到一个数组
参数3:进制权值
返回值:无
说明:进制转换的求余操作一直到商为0才停止
作者: Lee.C
完成时间:2015-6-6
修改时间:
**************************************/
void conversion(int dec,int *des,int sys)
{
	SqStack S;
	int i=0;

	InitStack(&S);

	while(dec)
	{
		Push(S,dec%sys);
		dec = dec/sys;
	}
	while(!StackIsEmpty)
		octal[i++] = Pop(&S);
}

/**********************************
函数功能:递归方式进行十进制对其
		 他进制(十进制以内)的转换
参数1:十进制数
参数2:输出参数,存储转换后的每一位数字到一个数组
参数3:进制权值
返回值:无
说明:进制转换的求余操作一直到商为0才停止
作者: Lee.C
完成时间:2015-6-6
修改时间:
**************************************/
void conversion(int dec,int *des,int sys)
{
	static int i=0;
	int r;
	
	r = dec%sys;
	if(dec>=sys)
		conversion(dec/sys,des,sys);
	
	des[i++] = r;
}