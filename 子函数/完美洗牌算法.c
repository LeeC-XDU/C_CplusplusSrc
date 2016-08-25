/**********************************
函数功能:完美洗牌算法1
参数1(Output):洗牌后的数组
参数2:数组元素的个数
返回值:无
说明:时间复杂度为 O(n)，空间复杂度为 O(n)
头文件:<stdlib.h>
       <string.h>
	   <assert.h>
作者: Lee.C
完成时间:2016-08-23
**************************************/
void PerfectShuffle1(int *arr, int num)
{
	assert(arr);
	assert(num > 0);
	assert(num%2 == 0);
	
	int num2 = num * 2;
	int i = 0;
	int *brr = (int*)malloc(num2 * sizeof(int));

	for(i=1; i<=num2; i++)
		brr[(i*2 % (num2+1))-1] = arr[i-1];

	memcpy(arr, brr, num2*sizeof(int));
	
	SwapOddEven(array, num);

	free(brr);
}

/**********************************
函数功能:完美洗牌算法2
参数1(Output):洗牌后的数组
参数2:数组元素的个数
返回值:无
说明:时间复杂度为 O(n)，空间复杂度为 O(1)
头文件:<stdlib.h>
       <string.h>
	   <assert.h>
作者: Lee.C
完成时间:2016-08-23
**************************************/
void PerfectShuffle2(int *arr, int num)
{
	assert(arr);
	assert(num > 0);
	assert(num%2 == 0);
	
	int num2 = 0, m = 0, i = 0, k = 0, t = 0;

	while(num > 1)
	{
		num2 = num * 2;
		k = 0;
		m = 1;
		while(num2/m >= 3)
		{
			k++;
			m *= 3;
		}

		m /= 2;

		RightRotate(arr+m, num, m);

		for(i=0, t=1; i<k; i++, t*=3)
			CycleLeader(arr, t, m*2+1);

		arr += m*2;
		num -= m;
	}

	t = arr[0];
	arr[0] = arr[1];
	arr[1] = t;
}

/**********************************
函数功能:按一个环的顺序调整数组
参数1(Output):按一个环的顺序洗牌后的数组
参数2:环头位置
参数2:模数
返回值:无
说明:
头文件:
作者: Lee.C
完成时间:2016-08-23
**************************************/
void CycleLeader(int *arr, int from, int mod)
{
	int t = 0, i = 0;
	for(i=from*2%mod; i!=from; i=i*2%mod)
	{
		t = arr[i-1];
		arr[i-1] = arr[from-1];
		arr[from-1] = t;
	}
}

/**********************************
函数功能:指定区间元素翻转
参数1(Output):待翻转数组
参数2:待翻转区间首
参数2:待翻转区间尾
返回值:无
说明:
头文件:
作者: Lee.C
完成时间:2016-08-23
**************************************/
void Reverse(int *arr, int begin, int end)
{
	int temp = 0;

	while(begin < end)
	{
		temp = arr[begin-1];
		arr[begin-1] = arr[end-1];
		arr[end-1] = temp;

		begin++;
		end--;
	}
}

/**********************************
函数功能:三步翻转法右旋数组
参数1(Output):待翻转数组
参数2:数组元素个数
参数2:翻转位置
返回值:无
说明:
头文件:
作者: Lee.C
完成时间:2016-08-23
**************************************/
void RightRotate(int *arr, int num, int k)
{
	//旋转前半部分
	Reverse(arr, 1, num-k);
	//旋转右半部分
	Reverse(arr, num-k+1, num);
	//全部旋转
	Reverse(arr, 1, num);
}

/**********************************
函数功能:数组奇偶位对调
参数1(Output):待对调数组
参数2:数组元素个数
返回值:无
说明:
头文件:
作者: Lee.C
完成时间:2016-08-23
**************************************/
void SwapOddEven(int *arr, int num)
{
	int num2 = 2 * num;
	int i = 0;

	for(i=0; i<num2; i+=2)
		Swap(&arr[i], &arr[i+1]);
}


/**********************************
函数功能:交换函数
**************************************/
void Swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
