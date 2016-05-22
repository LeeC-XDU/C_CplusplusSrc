/**********************************
函数功能:Fibonacci查找
参数1:待被查找的数组
参数2:数组元素的个数
参数3:待查找的元素
参数4:菲波那切数列
返回值:key在数组array中的地址索引，没有返回NULL
说明:Fibonacci中的数值记录的是要查找的区间中有多少个字符(见《大话数据结构》P306)
     k指明要使用第几个Fibonacci中的数值；
     本函数并没有改变array数组的值，但为了与返回值匹配，就没有用 const 修饰
作者: Lee.C
完成时间:2015-05-22
**************************************/
int *FibonacciSearch(int *array, const size_t num, const int key, const int *Fibonacci)
{
	assert(array);
	assert(Fibonacci);

	/******************************************
	 *low       最低下标首位置
	 *high      最高下标首位置
	 * k　      指明要使用第几个Fibonacci中的数值
	 * i        循环变量
	 *retValue  返回的地址索引位置
	 *arrayCpy  扩展后的数组
	******************************************/
	size_t low = 0, high = num - 1, mid = 0;
	size_t k = 1, i = 0;
	int *retValue = NULL, *arrayCpy = NULL;

	//查找num在Fibonacci中的位置
	while(num > Fibonacci[k]-1)
		k++;

	arrayCpy = (int*)malloc((Fibonacci[k]-1) * sizeof(int));
	memcpy(arrayCpy, array, num*sizeof(int));
	//将数组个数扩展到 Fibonacci[k]-1 个
	for(i=num; i<Fibonacci[k]-1; i++)
		arrayCpy[i] = array[num-1];

	while(low <= high)
	{
		mid = low + Fibonacci[k-1]-1;
		if(key < arrayCpy[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if(key > arrayCpy[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if(mid <= num)
			{
				retValue = array + mid;
				break;
			}
			else
			{
				//mid>num 说明是补全数值，则返回num-1的位置
				retValue = array + num - 1;   
				break;
			}
		}
	}

	free(arrayCpy);

	return retValue;
}


/**********************************
函数功能:Fibonacci查找
参数1:待被查找的数组
参数2:数组元素的个数
参数3:待查找的元素
返回值:key在数组array中的地址索引，没有返回NULL
说明:函数自己生成Fibonacci数列，这不是一个好的设计；
     每次查找时计算Fibonacci数列可是很耗时的，这个工作就应该交给其他模块完成，
     本函数应只负责查找，这样写虽然节省了一点空间，但耗费了大量时间
作者: Lee.C
完成时间:2015-05-22
**************************************/
int *FibonacciSearch(int *array, const size_t num, const int key)
{
	assert(array);

	size_t low = 0, high = num - 1, mid = 0;
	size_t k = 2, i = 0;
	int *retValue = NULL;
	int *arrayCpy = NULL, *Fibonacci = NULL;
	Fibonacci = (int*)malloc(k*sizeof(int));

	Fibonacci[0] = 0;
	Fibonacci[1] = 1;

	while(num > Fibonacci[k-2]+Fibonacci[k-1]-1)
	{
		Fibonacci = (int*)realloc(Fibonacci, ++k*sizeof(int));
		Fibonacci[k-1] = Fibonacci[k-3] + Fibonacci[k-2];
	}
	Fibonacci = (int*)realloc(Fibonacci, (k+1)*sizeof(int));
	Fibonacci[k] = Fibonacci[k-2] + Fibonacci[k-1];

	arrayCpy = (int*)malloc((Fibonacci[k]-1) * sizeof(int));
	memcpy(arrayCpy, array, num*sizeof(int));
	//将数组个数扩展到 Fibonacci[k]-1 个
	for(i=num; i<Fibonacci[k]-1; i++)
		arrayCpy[i] = array[num-1];

	while(low <= high)
	{
		mid = low + Fibonacci[k-1]-1;
		if(key < arrayCpy[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if(key > arrayCpy[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if(mid <= num)
			{
				retValue = array + mid;
				break;
			}
			else
			{
				retValue = array + num - 1;   
				break;
			}
		}
	}

	free(Fibonacci);
	free(arrayCpy);

	return retValue;
}
