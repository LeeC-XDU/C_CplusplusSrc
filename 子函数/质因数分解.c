/**********************************
��������:�������ֽ⣬�����浽һ��������
����1:��Ҫ�ֽ������
����2:(�������)���ֽ�������ĸ���(����Ԫ�ظ���)
����ֵ:����������������׵�ַ
˵��:�ں����л�����ڴ棬����������ע���ͷ�
     �����������ᱣ��1���䱾��
�����׼���ļ�:stdlib.h stdio.h
����: Lee.C
���ʱ��:2015-12-23
�޸�ʱ��:
**************************************/
unsigned int * primeFactors( const unsigned int num, unsigned int *_count )
{
	//���յ�����������ŵ�����
	unsigned int *r_array;
	//��������ŵ�����
	unsigned int *prime = NULL;

	//count��¼��������ĸ�����cn��¼����������ĸ���
	unsigned int i = 0, count = 0, cn = 0;
	unsigned int meanNum = 0;
	unsigned int Num = num;

	if( isPrime(Num) )
	{
		r_array = (unsigned int*)malloc(2*sizeof(unsigned int));
		if( !r_array )
		{
			printf("Call 'promerFactors' error\n");
			printf("Memory allocation failed(1).\n");
			exit(EXIT_FAILURE);
		}
		r_array[0] = 1;
		r_array[1] = Num;
		*_count = 2;
		return r_array;
	}
	
	meanNum = (unsigned int)(Num/2);
	
	prime = (unsigned int*)malloc(count*sizeof(unsigned int));
	r_array = (unsigned int*)malloc(cn*sizeof(unsigned int));
	if( !prime && !r_array )
	{
		printf("Call 'promerFactors' error.\n");
		printf("Memory allocation failed(2).\n");
		exit(EXIT_FAILURE);
	}

	//��ȡ��������ط�Ҳ��Ҫ�еȺŵ�
	for(i=2; i<=meanNum; i++)
	{
		if(isPrime(i))
		{
			prime = (unsigned int *)realloc( prime, ++count*sizeof(unsigned int));
			prime[count-1] = i;
		}
	}

	i = 0;

	while( i<count )
	{
		if( !(Num%prime[i]) )
		{
			r_array = (unsigned int*)realloc(r_array,++cn*sizeof(unsigned int));
			r_array[cn-1] = prime[i];
			Num /= prime[i];
		}
		else
		{
			i++;
		}
	}

	*_count = cn;

	free(prime);
	return r_array;
}