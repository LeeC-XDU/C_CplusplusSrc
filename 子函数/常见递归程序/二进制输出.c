/**********************************
��������:���������(�ݹ�ʵ��)
����1:ʮ������
����2(output):�������ַ�
����ֵ:��
˵��:����ת�����������һֱ����Ϊ0��ֹͣ
����: Lee.C
���ʱ��:2015-05-01
�޸�ʱ��:
�޸�˵��:
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
��������:���������(ջʵ��)
����1:ʮ������
����2(output):�������ַ�
����ֵ:��
˵��:����ת�����������һֱ����Ϊ0��ֹͣ
����: Lee.C
���ʱ��:2015-05-01
�޸�ʱ��:
�޸�˵��:
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


