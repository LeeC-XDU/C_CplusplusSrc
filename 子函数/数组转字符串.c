/**********************************
��������:����������ת��Ϊ�ַ�����ʽ
����1:��������
����2:����Ԫ�ظ���
����ֵ:�ַ������׵�ַ
˵��:�ں����ڶ�̬�����ڴ棬����������ע���ڴ��ͷ�
     �������'*'���������
�����׼���ļ�:string.h
����: Lee.C
���ʱ��:2015-12-23
�޸�ʱ��:
**************************************/
char* intToStr(const int *array, const unsigned int count)
{
	unsigned int i = 0;
	char strTemp[5] = {0};
	unsigned int cn = 0, len = 0;
	char *str = (char*)malloc(1*sizeof(char));
	//Ϊ���ڵ�һλ����ƴ��
	str[0] = '\0';

	for(i=0; i<count-1; i++)
	{
		cn = sprintf(strTemp,"%u", array[i]);
		//����Ҫ���±����Ͽ���len��ֵ���±ߵ�+1��Ϊĩβ'\0'Ԥ���ģ�
		len += cn+1;	//�����+1����Ϊ'*'�ģ���Ϊÿ�ζ���*����'\0'ֻ����һ��
		str = (char*)realloc( str,(len+1)*sizeof(char) );
		strncat(str,strTemp,cn);
		strcat(str,"*");	//���������
	}
	cn = sprintf(strTemp,"%u", array[i]);
	len += cn+1;
	str = (char*)realloc( str,(len+1)*sizeof(char) );
	strncat(str,strTemp,cn);

	return str;
}


/**********************************
��������:����������ת��Ϊ�ַ�����ʽ
����1:(�������)ת������ַ���
����2:��������
����3:����Ԫ�ظ���
����ֵ:��
˵��:�ں����ڶ�̬�����ڴ棬����������ע���ڴ��ͷ�
     �������'*'���������
�����׼���ļ�:string.h
����: Lee.C
���ʱ��:2015-12-23
�޸�ʱ��:
**************************************/
void intToStr(char *str, const unsigned int *array, const unsigned int count)
{
	char tempStr[5] = {0};
	unsigned int i = 0;
	
	//Ϊʵ���ڵ�һ��λ�ý���ƴ��
	if(str[0])
	{
		str[0] = '\0';
	}

	for(i=0; i<count-1; i++)
	{
		sprintf(tempStr, "%u", array[i]);
		strcat(str, tempStr);
		strcat(str, "*");	//���������
	}
	sprintf(tempStr, "%u", array[i]);
	strcat(str, tempStr);
}