/**********************************
函数功能:生成Zigzag数组
参数1(Output):数组指针
参数2:数组元素的行列数
返回值:无
说明:zigzag是"之"字型递增的方阵，其矩阵左上角的部分都是一样的，
由定义规则也可知，当递增至右下角时，此时可选择↓，表示未达到n，
当到达n的时候，这选择→，以生成右下角部分的矩阵。
头文件:
作者: Lee.C
完成时间:2016-07-23
**************************************/
void Zigzag(int **array, int n)
{
	int i = 0, j = 0;
	int num = 0;
	
	while(i < n)
	{
		//↗方向生成数字
		while(i > 0)
		{
			array[i--][j++] = num++;
		}
		array[i][j++] = num++;
		
		//↙方向生成数字
		while(j > 0)
		{
			array[i++][j--] = num++;
		}
		array[i++][j] = num++;
	}
	
	i--;
	num--;

	while(i < n)
	{
		//↙方向生成数字
		while(i < n-1)
		{
			array[i++][j--] = num++;
		}
		array[i][j++] = num++;
		
		//↗方向生成数字
		while(j < n-1)
		{
			array[i--][j++] = num++;
		}
		array[i++][j] = num++;
	}
}