/**********************************
��������:�Զ���ջ��ʽ��������ƥ��
����1:�����ַ���(�ɰ�����[]����()������������)
����ֵ:�����Ƿ�ƥ��
˵��:
**************************************/
bool match_bracket(char *str)
{
	SqStack S;
	bool state = true;		//���������־λ����ͦ���õ�

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