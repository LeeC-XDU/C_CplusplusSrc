/**********************************
函数功能:ASCII码绘制数字
参数1:要显示的内容的字符串形式
返回值:无
说明:要打印的字符串是类似这样的 1*2*13，
     字符串中保存的字符是 '1', '*', '2', '*', '1', '3' 这六个字符；
	 基本思路是这样的，五个循环不会变，字符的显示也不会变了；
     要改的地方是是否显示'*'号或其他符号和在哪显示这个特殊符号的问题
头文件:<stdio.h>
作者: Lee.C
完成时间:2015-12-23
修改时间:
**************************************/
void ASCIINumberDisplay(const char* string)
{
	size_t len = 0, i = 0;
	len = strlen(string);

	//第一行
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


	//第二行
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


	//第三行
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

	//第四行
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

	//第五行
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