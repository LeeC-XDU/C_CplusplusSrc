/**********************************
��������:�ж�ָ�������Ƿ�������
����:���ж�����
����ֵ:�Ƿ�������
˵��:��ȡ�����еȺţ���1
     ��ȡ�����޵Ⱥţ�����1
�����׼���ļ�:math.h
����: Lee.C
���ʱ��:2014-7-24
�޸�ʱ��:2015-12-23
**************************************/
bool isPrime(long num)
{
	long i = 0;
	long sqrt_num = (long)sqrt(num);
	
	if(num>1)
	{
		for(i=2;i<=sqrt_num;i++)
		{
			if(num%i == 0)
				return false;		//2.break;
		}

		if(i == sqrt_num+1)
			return true;		//2.function();
		else
			return false;		//2.function();
	}
	else
		return false;
}

//��ȡ��
bool isPrime(const unsigned int num)
{
	unsigned int i = 0;
	unsigned int sqrt_num = 0;

	if( num < 2)
	{
		printf("Call 'isPrime' error\n");
		printf("The num is incorrect(<=1)\n");
		return false;
	}

	sqrt_num = (unsigned int)sqrt(num);

	for(i=2; i<=sqrt_num; i++)
	{
		if(num%i == 0)
			return false;		//2.break;
	}
	
	if(i == sqrt_num+1)
		return true;		//2.function();
	else
		return false;		//2.function();
}

//��ȡ��
bool isPrime(const unsigned int num)
{
	unsigned int  i = 0;
	unsigned int sqrt_num = 0;
	
	if( num < 2 )
	{
		printf("Call 'isPrime' error\n");
		printf("The num is incorrect(<=1)\n");
		return false;
	}
	
	sqrt_num = (unsigned int)ceil(sqrt(num));

	for(i=2; i<sqrt_num; i++)
	{
		if(num%i == 0)
			return false;		//2.break;
	}
	
	if(i == sqrt_num)
		return true;		//2.function();
	else
		return false;		//2.function();
}