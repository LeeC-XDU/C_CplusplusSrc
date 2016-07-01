/**********************************
函数功能:质因数分解，并保存到一个数组中
参数1:需要分解的数字
参数2(Output):保存素数的数组
返回值:所分解的因数的个数(数组元素个数)
说明:在函数中会分配内存，在主函数中注意释放
     对于素数，会保存1和其本身
头文件:<stdlib.h>
       <stdio.h>
作者: Lee.C
完成时间:2015-12-23
修改时间:2016-06-23
修改说明:代码重构
**************************************/
size_t primeFactors( int num, int **array )
{
	/****************************************
	 *  Num      : num的副本，防止num被意外修改
	 * meanNum   : Num的一半
	 *retCount   : 返回值，记录质因数的个数
	 *   i       : 循环计数变量
	 *primeArray : 质数所存放的数组
	 *PrimerCount: 记录2-meanNum中素数的个数
	*****************************************/
	int Num = num;
	int meanNum = (int)(Num/2);
	size_t retCount = 0, i = 0;
	
	int *primeArray = NULL;
	size_t PrimerCount = 0;

	if( isPrime(Num) )
	{
		*array = (int*)malloc(2*sizeof(int));
		if( !*array )
		{
			fputs("Call 'promerFactors' error\n", stderr);
			fputs("Memory allocation failed(1).\n", stderr);
			exit(EXIT_FAILURE);
		}
		(*array)[0] = 1;
		(*array)[1] = Num;
		retCount = 2;
		return retCount;
	}
	

	primeArray = (int*)malloc(PrimerCount * sizeof(int));
	*array = (int*)malloc(retCount * sizeof(int));
	if( !primeArray || !*array )
	{
		fputs("Call 'promerFactors' error\n", stderr);
		fputs("Memory allocation failed(1).\n", stderr);
		exit(EXIT_FAILURE);
	}

	//把小于 Num/2 的质数存入 primeArray 中
	//下取整，这个地方也是要有等号的
	for(i=2; i<=meanNum; i++)
	{
		if(isPrime(i))
		{
			primeArray = (int *)realloc( primeArray, ++PrimerCount * sizeof(int));
			primeArray[PrimerCount-1] = i;
		}
	}

	i = 0;

	while( i<PrimerCount )
	{
		if( !(Num%primeArray[i]) )
		{
			*array = (int*)realloc(*array, ++retCount * sizeof(int));
			(*array)[retCount-1] = primeArray[i];
			Num /= primeArray[i];
		}
		else
			i++;
	}

	free(primeArray);
	return retCount;
}