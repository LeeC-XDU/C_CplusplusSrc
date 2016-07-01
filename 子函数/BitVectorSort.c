/**********************************
函数功能:位向量排序
参数1:数据输入文件
参数2:数据输出文件
返回值:无
说明:读入10000000个正整数数据，对此数据进
     行排序，排序后的数字输出到指定文件中
作者: Lee.C
完成时间:2016-06-05
**************************************/
#define N 10000000
#define SHIFT 5
#define MASK 0x1F
#define BITPERWORD 32
void BitVectorSort(FILE *outFile, FILE *inFile)
{
	assert(inFile);
	assert(outFile);
	
	int i = 0;
	int array[(N-1)/BITPERWORD + 1];
	memset(array, 0, ((N-1)/BITPERWORD+1)*sizeof(int));

	while(fscanf(inFile, "%d", &i))
		set(array, i);

	for(i=0; i<N; i++)
		if(test(array, i))
			fprintf(outFile, "%d", i);
}

void set(int *array, int i)
{
	array[i>>SHIFT] |= (1<<(i & MASK));
}

void clr(int *array, int i)
{
	array[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int *array, int i)
{
	return array[i>>SHIFT] & (1<<(i & MASK));
}
