/**********************************
ģ�鹦��:ѭ����ȡ�ַ�������(CPP��)
˵��:�����Ӻ��� eatLine()
����: Lee.C
���ʱ��:2015-12-04
�޸�ʱ��:
**************************************/
cout << "Enter name (enter a blank line to quit):\n";
cin.get(name, 20);
while( name[0] != '\0' )
{
	eatline();
	
	//handle data;
	
	cout << "Enter name (enter a blank line to quit):\n";
	cin.get(name, 20);
}

/**********************************
ģ�鹦��:ѭ����ȡ�ַ�������(C��)
˵��:�����Ӻ��� eatline()
     ��һ�����Ǽ���Ƿ����ļ���β���ڶ����ּ���Ƿ��ǿ���
����: Lee.C
���ʱ��:2015-12-04
�޸�ʱ��:
**************************************/
puts("Enter a string (empty line to quit):");
while( gets(str) && str[0]!='\0' )
{
	//handle data

	puts("Next string:");
}


/**********************************
ģ�鹦��:ѭ����ȡ�ַ�������
˵��:
����: Lee.C
���ʱ��:201-01-03
�޸�ʱ��:
**************************************/
while( (ch=getchar()) != '\n' && ch != EOF )
{
	//handle data
}


/**********************************
ģ�鹦��:ѭ����ȡ���ֲ�����
˵��:
����: Lee.C
���ʱ��:201-01-03
�޸�ʱ��:
**************************************/
printf("Please input one number\n");
printf("(q to quit):");
while( 1 == scanf("%d",&num) )
{
	//handle data

	//������䣬һ������һ�����ݣ�������䣬һ�����������ݣ��ÿո����
	printf("Please input next number(q to quit)");
}


