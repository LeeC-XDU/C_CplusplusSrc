/**********************************
��������:�����ַ����Ĵ���(��һ���ַ�������)
����1:ͬ��Ҳ���������,���������ַ���
����ֵ:��
˵��:����� string.h ͷ�ļ�
����: Lee.C
���ʱ��:2012.12.4
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
��������:��һ��ż�����ַ���������
		 ����������λ��ż��λ�Ե�
����1:ͬ��Ҳ���������,���������ַ���
����ֵ:��
˵��:��
����: Lee.C
���ʱ��:2012.12.4
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
��������:��һ����������ת�����ַ���
����1:��ת��������
����2:�������,�洢ת���ɵ��ַ���
����ֵ:��
˵��:��
����: Lee.C
���ʱ��:2012.12.4
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
			len++;		//len��¼�ľ����ַ����ĳ���
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
��������:��һ��˫��������ת�����ַ���
����1:��ת��˫��������
����2:�������,�洢ת���ɵ��ַ���
����3:����� string.h ͷ�ļ�
����ֵ:��
˵��:��
����: Lee.C
���ʱ��:2012.12.4
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
	for(j=0;j<i/2;j++)		// i ��¼�ľ����ַ����ĳ���
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
		}		//�������ѭ�� i �̶�����6;
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
��������:��һ���ַ���ת����˫������
����1:��ת�����ַ���
����ֵ:ת����˫��������
˵��:��
����: Lee.C
���ʱ��:2012.12.4
**************************************/
double Str_To_Double(char *Str)
{
	double i,num = 0;	//���num����Ҫ�г�ֵ��
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