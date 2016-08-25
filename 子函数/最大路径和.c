/**********************************
函数功能:寻找矩阵中的最大路径和
参数1:矩阵数组
参数2:矩阵数组的行数
参数3:矩阵数组的列数
返回值:最大路径和
说明:动态规划的典型应用之一
头文件:<stdlib.h>
       <string.h>
作者: Lee.C
完成时间:
修改时间:
修改说明:
**************************************/
int maxPathSum(const int *arr[], int row, int col)
{
	if(!arr || row<=0 || col<=0)
		return 0;

	int i = 0, j = 0;
	int retValue = 0;

	int **dp = (int **)malloc(row*sizeof(int *));
	for(i=0; i<row; i++)
	{

		dp[i] = (int*)malloc(col*sizeof(int));
		memset(dp[i], 0, col*sizeof(int));
	}

	dp[0][0] = arr[0][0];
	
	//第一列的元素很好确定大小
	for(i=1; i<row; i++)
		dp[i][0] = dp[i-1][0] + arr[i][0];

	//第一行的元素亦很好确定大小
	for(j=1;j<col; j++)
		dp[0][j] = dp[0][j-1] + arr[0][j];

	for(i=1; i<row; i++)
		for(j=1; j<col; j++)
			//把＞换成＜就是最小路径和了
			dp[i][j] = dp[i-1][j]>dp[i][j-1] ? dp[i-1][j]+arr[i][j] : dp[i][j-1]+arr[i][j]; 

	retValue = dp[row-1][col-1];

	for(i=0; i<row; i++)
		free(dp[i]);
	free(dp);

	return retValue;
}