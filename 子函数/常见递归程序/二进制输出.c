/**********************************
函数功能:二进制输出(递归实现)
参数1:十进制数
参数2(output):二进制字符
返回值:无
说明:进制转换的求余操作一直到商为0才停止
作者: Lee.C
完成时间:2015-05-01
修改时间:
修改说明:
**************************************/
void toBinary(const int dec, char *des)
{
	int r;
	static int i = 0;
	r = dec % 2;

	if(dec)
		toBinary(dec/2, des);
	else
		return;

	
	des[i++] = '0' + r;
}

/**********************************
函数功能:二进制输出(栈实现)
参数1:十进制数
参数2(output):二进制字符
返回值:无
说明:进制转换的求余操作一直到商为0才停止
作者: Lee.C
完成时间:2015-05-01
修改时间:
修改说明:
**************************************/
void toBinary2(int dec, char *des)
{
	Item tempStackValue = 0, i = 0;
	SqStack S;
	InitStack(&S);

	while(dec)
	{
		tempStackValue = dec % 2;
		Push(&S, &tempStackValue);
		dec /= 2;
	}


	while(!isEmptyStack(&S))
	{
		Pop(&S, &tempStackValue);
		des[i++] = '0' + tempStackValue;
	}
}


