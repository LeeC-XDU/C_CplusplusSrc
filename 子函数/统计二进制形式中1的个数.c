/******************************************
函数功能:统计非负数中二进制形式中1的个数
参数1:待统计数字
返回值:二进制形式中1的个数
说明:
头文件: <assert.h>
        <stddef.h>
作者: Lee.C
完成时间:2016-06-19
******************************************/
size_t countOne(int num)
{
	assert(num >= 0);
	
	size_t count = 0;
	
	while(num)
	{
		count++;
		num &= num-1;
	}
	
	return count;
}