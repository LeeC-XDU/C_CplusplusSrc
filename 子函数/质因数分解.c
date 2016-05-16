/**********************************
函数功能:质因数分解，并保存到一个数组中
参数1:需要分解的数字
参数2:(输出参数)所分解的因数的个数(数组元素个数)
返回值:保存因数的数组的首地址
说明:在函数中会分配内存，在主函数中注意释放
     对于素数，会保存1和其本身
所需标准库文件:stdlib.h stdio.h
作者: Lee.C
完成时间:2015-12-23
修改时间:
**************************************/
unsigned int * primeFactors( const unsigned int num, unsigned int *_count )
{
	//最终的质因数所存放的数组
	unsigned int *r_array;
	//质数所存放的数组
	unsigned int *prime = NULL;

	//count记录质数数组的个数，cn记录质因数数组的个数
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

	//下取整，这个地方也是要有等号的
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