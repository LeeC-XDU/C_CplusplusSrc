/************************************************
函数功能:求连续子序列的最大和
参数1:数组
参数2:数组中元素的个数
返回值:连续子序列的最大和
说明: 程序比较简单，比较值得学习
头文件:
作者: Lee.C
完成时间:2016-08-18
**************************************************/
int FindGreatestSumOfSubArray(const int *pData, int nLength)
{
	if(!pData || nLength <=0)
		return 0;
	
	int nCurSum = 0;
	int nGreatestSum  = 0;
	
	for(int i=0; i<nLength; i++)
	{
		if(nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];
		
		if(nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}
	
	return nGreatestSum;
}