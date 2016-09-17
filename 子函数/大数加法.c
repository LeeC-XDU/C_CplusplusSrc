/**********************************
函数功能:大数加法
参数1:加数1
参数2:加数2
返回值:结果和
说明:
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-09-16
**************************************/
char *BigIntegerAdd(const char BigInteger1[], const char BigInteger2[])
{
	char *result = NULL;
	int length1 = 0;
	int length2 = 0;
	int resultLength = 0;
	int i = 0, j = 0, k = 0;
	int num1 = 0, num2 = 0, sum = 0;
	int carry = 0;

	//在这里进行边界条件的检测
	if(BigInteger1)
		length1 = strlen(BigInteger1);
	if(BigInteger2)
		length2 = strlen(BigInteger2);

	resultLength = length1 > length2 ? length1 : length2;

	result = (char*)malloc(resultLength*sizeof(char));
	memset(result, 0, resultLength*sizeof(char));

	i = length1 - 1;
	j = length2 - 1;
	k = resultLength - 1;

	while(i>=0 && j>=0)
	{
		num1 = BigInteger1[i] - '0';
		num2 = BigInteger2[j] - '0';
		sum = num1 + num2 + carry;

		if(sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result[k] = sum + '0';

		i--;
		j--;
		k--;
	}

	while(i>=0)
	{
		num1 = BigInteger1[i] - '0' + carry;

		if(num1 >= 10)
		{
			num1 -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result[k] = num1 + '0';

		i--;
		k--;
	}

	while(j>=0)
	{
		num2 = BigInteger2[j] - '0' + carry;

		if(num2 >= 10)
		{
			num2 -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result[k] = num2 + '0';

		j--;
		k--;
	}

	if(carry == 1)
	{
		result = (char*)realloc(result, (resultLength+1)*sizeof(char));
		memmove(result+1, result, resultLength*sizeof(char));
		result[0] = '1';
	}

	return result;
}