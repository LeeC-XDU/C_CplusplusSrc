/**********************************
函数功能:获取某数组中最长递增子序列(非连续)
参数1:待处理数组
参数2:数组中元素的个数
返回值:递增子序列数组
说明:需要在外部释放子序列数组堆内存
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-07-16
**************************************/
int *getLIS(const int *array, int num)
{
	if(!array || num <=0)
		return NULL;
	
	int *LISArray = NULL;
	int *dpArray = getDPArray(array, num);
	
	LISArray = generateLIS(array, dpArray, num);
	
	free(dpArray);
	
	return LISArray;
}

/************************************************
函数功能:获取某数组中最长递增子序列主要函数
参数1:待处理数组
参数2:动态规划所获取子问题的解
参数3:两数组中元素的个数(两数组等长)
返回值:递增子序列数组
说明:找dpArray最大值即是array数组的最大递增子序列的长度
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-07-16
**************************************************/
int *generateLIS(const int *array, const int *dpArray, int num)
{
	int len = 0;
	int index = 0;
	int i = 0;
	
	int *LISArray = (int *)malloc(num * sizeof(int));
	memset(LISArray, 0, num*sizeof(int));
	
	//找最大值和其下标
	for(i=0; i<num; i++)
	{
		if(dpArray[i] > len)
		{
			len = dpArray[i];
			index = i;
		}
	}
		
		
	LISArray[--len] = array[index];
	
	for(i=index; i>=0; i--)
	{
		if(array[i]<array[index] && dpArray[i] == dpArray[index]-1)
		{
			LISArray[--len] = array[i];
			index = i;
		}
	}
	
	return LISArray;
}

/************************************************
函数功能:动态规划获取子问题的解
参数1:完整的数组
参数2:数组中元素的个数
返回值:子问题的解
说明: 保存每个元素所对用的该问题的解；
      该数组元素-1即为该元素前比其小且为递增序列的个数
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-07-16
**************************************************/
int *getDPArray(const int *array, int num)
{
	int *dpArray = (int *)malloc(num * sizeof(int));
	int i = 0, j = 0;
	
	for(i=0; i<num; i++)
	{
		dpArray[i] = 1;
		for(j=0; j<i; j++)
			if(array[i]>array[j])
				dpArray[i] = dpArray[i] > dpArray[j]+1 ? dpArray[i] : dpArray[j]+1;
	}
	
	return dpArray;
}