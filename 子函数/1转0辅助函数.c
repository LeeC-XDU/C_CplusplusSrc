/**********************************
函数功能:增加一个辅助空间数组
参数1(Output):原数组
参数2:数组元素个数，不是空间大小，切记
返回值:辅助数组首地址
说明:为了把下标从0开始处理的程序转为
     下标从1开始处理，见笔记《程序员知识——把一个
	 数组下标从1开始的程序转为从0开始的程序的思考》
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-08-23
**************************************/
int *AddOneSpace(const int *arr, int size)
{
	int *dstArr = (int*)malloc( (size+1)*sizeof(int) );
	memmove(dstArr+1, arr, size*sizeof(int));
	*dstArr = 222;

	return dstArr;
}

/**********************************
函数功能:释放辅助空间
参数1(Output):目标数组
参数2:待释放辅助空间
参数3:数组元素个数，不是空间大小，切记
返回值:辅助数组首地址
说明:
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:2016-08-23
**************************************/
void DeleteOneSpace(int *dstArr, int **arr, int size)
{
	memmove(dstArr, *arr+1, size*sizeof(int));

	free(*arr);
}