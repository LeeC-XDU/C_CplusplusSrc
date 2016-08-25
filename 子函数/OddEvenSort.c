/**********************************************
函数功能:以奇数在前，偶数在后的顺序排列数组
参数1(Output):待排序数组
参数2:数组长度
返回值:无
说明:快排数组调整的思想，两边向中间搜寻
头文件:无
作者: Lee.C
完成时间:2016-07-24
********************************************/
void OddEvenSort1(int *pData, int length)
{
	if(!pData || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length -1;

	while(pBegin < pEnd)
	{
		if(IsOddNumber(*pBegin))
			pBegin++;
		else if(!IsOddNumber(*pEnd))
			pEnd--;
		else
			swap(pBegin, pEnd);
	}
}

/**********************************************
函数功能:以奇数在前，偶数在后的顺序排列数组
参数1(Output):待排序数组
参数2:数组长度
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-07-25
********************************************/
void OddEvenSort2(int *pData, int length)
{
	if(!pData || length == 0)
		return;

	int fast = 0;
	int slow = -1;

	for(fast=pData; fast<length-1; fast++)
	{
		if( IsOddNumber(pData[fast] )
		{
			slow++;
			swap(pData[slow], pData[fast]);
		}
	}
	
	//slow+1处的元素一定不满足条件，一定要放到后面，
	//length-1处的数字没有检测，无论奇偶都行，交换后
	//这个数作为奇偶分界的边界。
	swap(pData[slow+1], pData[length-1]);
}

/**************************************
函数功能:判断某数是否是奇数
参数1:待判断数字
返回值:是奇数返回TRUE，否则返回FALSE
说明:学习一种用位去判断的方法
头文件:无
作者: Lee.C
完成时间:2016-07-24
****************************************/
Status IsOddNumber(int data)
{
	if(data & 0x01)
		return TRUE;
	else
		return FALSE;
}

/**************************************
函数功能:交换两数程序
参数1(Output):待交换数字1
参数1(Output):待交换数字
返回值:无
说明:
头文件:无
作者: Lee.C
完成时间:2016-07-24
****************************************/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}