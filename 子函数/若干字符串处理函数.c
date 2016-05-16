/**********************************
函数功能:交换字符串的次序(将一个字符串倒序)
参数1:同样也是输出参数,待交换的字符串
返回值:无
说明:需包含 string.h 头文件
作者: Lee.C
完成时间:2012.12.4
**************************************/
void Str_Swap(char *Str)
{
	char tmp;
	int i,len;
	len = strlen(Str);
	for(i=0;i<len/2;i++)
	{
		tmp = *(Str+i);
		*(Str+i) = *(Str+len-1-i);
		*(Str+len-1-i) = tmp;
	}
}


/**********************************
函数功能:将一个偶数个字符个数的字
		 符串的奇数位与偶数位对调
参数1:同样也是输出参数,待交换的字符串
返回值:无
说明:无
作者: Lee.C
完成时间:2012.12.4
**************************************/
void Swap_Odd_Even(char *Str)
{
	int i;
	char tmp;
	for(i=0;Str[i];i++)
	{
		tmp = Str[i];
		Str[i] = Str[i+1];
		Str[i+1] = tmp;
		i++;
	}
}


/**********************************
函数功能:将一个整形数据转换成字符串
参数1:待转换的整数
参数2:输出参数,存储转换成的字符串
返回值:无
说明:无
作者: Lee.C
完成时间:2012.12.4
**************************************/
void Int_To_Str(int num,char *Str)
{
	int len = 0,i;
	char tmp;
	if(num == 0)
	{
		*Str++ = num +0x30;
	}
	else
	{
		while(num)
		{
			*Str++ = num %10 + 0x30;
			len++;		//len记录的就是字符串的长度
			num /= 10;
		}
	}
	*Str = '\0';
	for(i=0;i<len/2;i++)
	{
		tmp = *(Str-1-i);
		*(Str-1-i) = *(Str-len+i);
		*(Str-len+i) = tmp;
	}
}


/**********************************
函数功能:将一个双精度数据转换成字符串
参数1:待转换双精度数据
参数2:输出参数,存储转换成的字符串
参数3:需包含 string.h 头文件
返回值:无
说明:无
作者: Lee.C
完成时间:2012.12.4
**************************************/
void Dou_To_Str(double num,char *Str)
{
	int  Integer = (int)num;
	int  Decimal = (int)((num-Integer)*1000000);
	char Decimal_Str[7];
	char tmp;
	int i=0,j;
	if(Integer == 0)
	{
		Str[i++] = Integer +0x30;
	}
	else
	{
		while(Integer)
		{
			Str[i++] = Integer %10 + 0x30;
			Integer /= 10;
		}
	}
	for(j=0;j<i/2;j++)		// i 记录的就是字符串的长度
	{
		tmp = Str[j];
		Str[j] = Str[i-1-j];
		Str[i-1-j] = tmp;
	}
	if(Decimal==0)
	{
		Str[i] = '\0';
	}
	else
	{
		Str[i] = '.';
		Str[i+1] = '\0';
		i=0;
		while(i!=6)
		{
			Decimal_Str[i++] = Decimal %10 + 0x30;
			Decimal /= 10;
		}		//做完这个循环 i 固定等于6;
		for(j=0;j<3;j++)
		{
			tmp = Decimal_Str[j];
			Decimal_Str[j] = Decimal_Str[5-j];
			Decimal_Str[5-j] = tmp;
		}
		Decimal_Str[i]='\0';
		while(Decimal_Str[--i]=='0')
		{
			Decimal_Str[i]='\0';	
		}
		strcat(Str,Decimal_Str);
	}
}


/**********************************
函数功能:将一个字符串转换成双精度型
参数1:带转换额字符串
返回值:转换的双精度数据
说明:无
作者: Lee.C
完成时间:2012.12.4
**************************************/
double Str_To_Double(char *Str)
{
	double i,num = 0;	//这个num必须要有初值啊
	int dat,Integer = 1;
	while(*Str)
	{
		if(*Str== '.')
		{
			Integer = 0;
			i = 1;
			Str++;
			continue;
		}
		else
			dat = *Str++ - 48;
		
		if(Integer == 1)
			num = num * 10 + dat;
		else
		{
			num += (float)(dat/(10*i));
			i *= 10;
		}

	}
	return num;
}