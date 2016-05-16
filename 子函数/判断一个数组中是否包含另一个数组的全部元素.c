/**************************************************
��������:�Ƿ�array����demandArray�е�ȫ��Ԫ��
����1:ԭ����
����2:ָ��Ҫ������Ԫ�ص�����
����3:ԭ�����Ԫ�ظ���
����4:Ŀ�������Ԫ�ظ���
����ֵ:ȫ����������true�����򷵻�false
˵��:�����ٵ�����ѭ��
     ���ݶ������ѭ��
�����׼���ļ�:��
����: Lee.C
���ʱ��:2016-03-21
�޸�ʱ��:2016-03-22
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
		//ע�������С�ڣ��������� <= 
		while(array[arrayIndex++] != demandArray[demandArrayIndex] && arrayIndex < arrayNumber)
			continue;
		if(arrayIndex == arrayNumber)
			return false;
		
		arrayIndex = 0;
		demandArrayIndex++;
	}
	return true;
}