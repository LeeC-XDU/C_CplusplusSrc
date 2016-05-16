/**********************************
函数功能:自定义栈方式进行括号匹配
参数1:括号字符串(可包括‘[]’‘()’此两类括号)
返回值:括号是否匹配
说明:
**************************************/
bool match_bracket(char *str)
{
	SqStack S;
	bool state = true;		//设置这个标志位还是挺好用的

	InitStack(&S);

	while(*str && state)
	{
		switch(*str)
		{
			case '(':
				Push(&S,*str);
				str++;
				break;
			case '[':
				Push(&S,*str);
				str++;
				break;
			case ')':
				if(!StackIsEmpty(S) && GetTop(S) == '(')
				{
					Pop(&S);
					str++;
				}
				else
					state = false;
				break;
			case ']':
				if(!StackIsEmpty(S) && GetTop(S) == '[')
				{
					Pop(&S);
					str++;
				}
				else
					state = false;
				break;

		}
	}

	if(StackIsEmpty(S) && state)
		return true;
	else
		return false;
}