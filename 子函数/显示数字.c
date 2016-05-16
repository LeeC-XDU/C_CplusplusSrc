/**********************************
��������:��ָ����������ʾһά���������
����1:һά����
����2:����������Ԫ�صĸ���
����3:ÿ������Ԫ�ص��ֳ���һ���� sizeof(float)��
����4:ÿ����ʾ�ĸ���(����)
����5:Ԫ��֮��ķָ���
����6:������ʾ��ʽ
����ֵ:��
�����׼���ļ�:stdio.h
˵��:ʹ���� void* ���Դ����κ���������飻�ú���ָ�봫��������ʾ�������β�Ҳ�� void* ���ܴ����������
     �¸�����һ������ĺ���ָ���ʵ������
����: Lee.C
���ʱ��:2012-12-22
�޸�ʱ��:2016-01-08
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
		//�޲��ĵ�ַ���Ϳ��ƶ����ٸ��ֽڴ�����һ��������
		p += size;
	}
	print_(p);
	putchar('\n');
}

//���� print ��һ��ʵ��
void print(void *p)
{
	double*temp = (double *)p;

	printf("%9.4f", *temp);
}


/**********************************
��������:��ָ����������ʾһά���������
����1:һά����
����2:����������Ԫ�صĸ���
����3:ÿ����ʾ�ĸ���(����)
����ֵ:��
�����׼���ļ�:stdio.h; math.h
˵��:�ɰ汾
����: Lee.C
���ʱ��:2015-12-22
�޸�ʱ��:
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
			//�������*array������array[]������ͺÿ�
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


