/**********************************
��������:ASCII���������
����1:Ҫ��ʾ�����ݵ��ַ�����ʽ
����ֵ:��
˵��:����˼·�������ģ����ѭ������䣬�ַ�����ʾҲ������ˣ�
     Ҫ�ĵĵط����Ƿ���ʾ'*'�Ż��������ź�������ʾ���������ŵ�����
�����׼���ļ�:stdio.h
����: Lee.C
���ʱ��:2015-12-23
�޸�ʱ��:
**************************************/
void ASCIINumberDisplay(const char* string)
{
	unsigned int len = 0, i = 0;
	len = strlen(string);

	//��һ��
	for(i=0; i<len-1; i++)
	{
		switch(string[i])
		{
			case '*':
				printf(" ");
				break;
			case '0':
			case '2':
			case '3':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				printf(" - ");
				break;
			default:
				printf("   ");
		}
	}
	switch(string[i])
	{
		case '0':
		case '2':
		case '3':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			printf(" - \n");
			break;
		default:
			printf("   \n");
	}


	//�ڶ���
	for(i=0; i<len-1; i++)
	{
		
		switch(string[i])
		{
			case '*':
				printf(" ");
				break;
			case '0':
			case '4':
			case '8':
			case '9':
				printf("| |");
				break;
			case '1':
			case '2':
			case '3':
			case '7':
				printf("  |");
				break;
			default:
				printf("|  ");
		}
	}
	switch(string[i])
	{
		case '0':
		case '4':
		case '8':
		case '9':
			printf("| |\n");
			break;
		case '1':
		case '2':
		case '3':
		case '7':
			printf("  |\n");
			break;
		default:
			printf("|  \n");
	}


	//������
	for(i=0; i<len-1; i++)
	{
		switch(string[i])
		{
			case '*':
				printf("*");
				break;
			case '0':
			case '1':
			case '7':
				printf("   ");
				break;
			default:
				printf(" - ");
		}
	}
	switch(string[i])
	{
		case '0':
		case '1':
		case '7':
			printf("   \n");
			break;
		default:
			printf(" - \n");
	}

	//������
	for(i=0; i<len-1; i++)
	{
		switch(string[i])
		{
			case '*':
				printf(" ");
				break;
			case '0':
			case '6':
			case '8':
				printf("| |");
				break;
			case '1':
			case '3':
			case '4':
			case '5':
			case '7':
			case '9':
				printf("  |");
				break;
			default:
				printf("|  ");
		}
	}
	switch(string[i])
	{
		case '0':
		case '6':
		case '8':
			printf("| |\n");
			break;
		case '1':
		case '3':
		case '4':
		case '5':
		case '7':
		case '9':
			printf("  |\n");
			break;
		default:
			printf("|  \n");
	}

	//������
	for(i=0; i<len-1; i++)
	{
		switch(string[i])
		{
			case '*':
				printf(" ");
				break;
			case '0':
			case '2':
			case '3':
			case '5':
			case '6':
			case '8':
				printf(" - ");
				break;
			default:
				printf("   ");
		}
	}
	switch(string[i])
	{
		case '0':
		case '2':
		case '3':
		case '5':
		case '6':
		case '8':
			printf(" - \n");
			break;
		default:
			printf("   \n");
	}
	
}