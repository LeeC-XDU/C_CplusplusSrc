/**********************************
模块功能:循环读取字符并处理(CPP版)
说明:调用子函数 eatLine()
作者: Lee.C
完成时间:2015-12-04
修改时间:
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
模块功能:循环读取字符并处理(C版)
说明:调用子函数 eatline()
     第一部分是检测是否是文件结尾，第二部分检测是否是空行
作者: Lee.C
完成时间:2015-12-04
修改时间:
**************************************/
puts("Enter a string (empty line to quit):");
while( gets(str) && str[0]!='\0' )
{
	//handle data

	puts("Next string:");
}


/**********************************
模块功能:循环读取字符并处理
说明:
作者: Lee.C
完成时间:201-01-03
修改时间:
**************************************/
while( (ch=getchar()) != '\n' && ch != EOF )
{
	//handle data
}


/**********************************
模块功能:循环读取数字并处理
说明:
作者: Lee.C
完成时间:201-01-03
修改时间:
**************************************/
printf("Please input one number\n");
printf("(q to quit):");
while( 1 == scanf("%d",&num) )
{
	//handle data

	//加上这句，一次输入一个数据，不加这句，一次输入多个数据，用空格隔开
	printf("Please input next number(q to quit)");
}


