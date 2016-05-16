/**********************************
��������:�����ַ���ƥ���㷨
����1:����
����2:ƥ�䴮
����3:��������Ҫ��ʼƥ�������
����ֵ:������ƥ���Ӵ�����Ԫ������,��ƥ�䷵����
˵��: ���� string.h
����: Lee.C
���ʱ��:2015.6.7
�޸�ʱ��:2016-04-30
�޸�˵��:�ɿ���λ�ø�Ϊ�����±�
**************************************/
int Index(char *S, char *T, int pos)
{
	//i��ʾ����S��������j��ʾ�Ӵ�T������
	int i = pos, j = 0;
	while(i<strlen(S) && j<strlen(T))
	{
		if(S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			//ʧƥ��ʱ��iָ����һ��λ�ã�j�˻ص�T�Ŀ�ͷ
			i = i-j+1;
			j = 0;
		}
	}
	
	if(j>=strlen(T))
		return i-strlen(T);
	else
		return 0;
}

/**********************************
��������:KMP�㷨ƥ���ַ���
����1:����
����2:ƥ�䴮
����3:��������Ҫ��ʼƥ�������
����ֵ:������ƥ���Ӵ�����Ԫ������,��ƥ�䷵����
˵��: ���� string.h stdlib.h
����: Lee.C
���ʱ��:2015.6.7
�޸�ʱ��:2015-04-30
�޸�˵��:�ɿ���λ�ø�Ϊ�����±�
         next����һ���Է���
**************************************/
int Index_KMP(char *S, char *T, int pos)
{
	int i = pos, j = 1;
	int *next  = (int*)malloc(strlen(T) * sizeof(int));

	get_next(T, next);
	
	while(i<strlen(S) && j<=strlen(T))
	{
		if(j == 0 || S[i] == T[j-1])
		{
			++i;
			++j;
		}
		else
			j = next[j-1];
	}
	
	free(next);
	
	if(j>strlen(T))
		return i-strlen(T);
	else
		return 0;
}

/**********************************
��������: next ����ֵ��ֵ����
����1:ģʽ��
����2:�������,��� next ֵ
����ֵ:��
˵��: ���� string.h stdlib.h
����: Lee.C
���ʱ��:2015.6.7
�޸�ʱ��:2015-04-30
�޸�˵��:
**************************************/
void get_next(char *T, int *next)
{
	int i = 0, j = 0;

	next[i] = 0;
	
	while(i<strlen(T)-1)
	{
		if(j==0 || T[i] == T[j-1] )
		{
			++i;
			++j;

			next[i] = j;
		}
		else
			j = next[j-1];
	}
}

/**********************************
��������: �Ľ��� next ����ֵ��ֵ����
����1:ģʽ��
����2:�������,��� next ֵ
����ֵ:��
˵��: ���� string.h stdlib.h
����: Lee.C
���ʱ��:2015.6.8
�޸�ʱ��:2015-04-30
�޸�˵��:
**************************************/
void get_nextval(char *T, int *nextval)
{
	int i = 0, j = 0;

	nextval[i] = 0;
	
	while(i<strlen(T)-1)
	{
		if(j==0 || T[i] == T[j-1] )
		{
			++i;
			++j;

			if(T[i] != T[j-1])
				nextval[i] = j;
			else
				nextval[i] = nextval[j-1];
		}
		else
			j = nextval[j-1];
	}
}