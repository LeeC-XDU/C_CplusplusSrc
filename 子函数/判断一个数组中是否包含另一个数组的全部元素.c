/**************************************************
函数功能:是否array包含demandArray中的全部元素
参数1:原数组
参数2:指定要包含的元素的数组
参数3:原数组的元素个数
参数4:目的数组的元素个数
返回值:全部包含返回true，否则返回false
说明:数据少的在外循环
     数据多的在内循环
所需标准库文件:无
作者: Lee.C
完成时间:2016-03-21
修改时间:2016-03-22
****************************************************/
bool isInclude(const int *array, const int *demandArray, const int arrayNumber, const int demandArrayNumber)
{
	int i,j;

	for(i=0, j=0; i<demandArrayNumber; i++)
	{
		for(j=0; j<arrayNumber; j++)
		{
			if( demandArray[i] == array[j] )
				break;
		}
		if( j == arrayNumber )
			return false;
	}
	return true;
}

bool isInclude(const int *array, const int *demandArray, const int arrayNumber, const int demandArrayNumber)
{
	int arrayIndex = 0, demandArrayIndex = 0;

	while(demandArrayIndex < demandArrayNumber)
	{
		//注意后面是小于，而不能是 <= 
		while(array[arrayIndex++] != demandArray[demandArrayIndex] && arrayIndex < arrayNumber)
			continue;
		if(arrayIndex == arrayNumber)
			return false;
		
		arrayIndex = 0;
		demandArrayIndex++;
	}
	return true;
}