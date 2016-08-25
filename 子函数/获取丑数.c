/************************************************
函数功能:获取第index个丑数
参数1:要获取的第几个
返回值:第index个丑数
说明: 详细说明见比价《算法——找第1500个丑数》
头文件:<stdlib.h>
作者: Lee.C
完成时间:2016-08-19
**************************************************/
int GetUglyNumber(int index)
{
    if(index <= 0)
        return 0;

    int retUglyNumber = 0;
    int minUglyNumber = 0;
    int *pUglyArrays = (int*)malloc(index*sizeof(int));
    pUglyArrays[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyArrays;
    int *pMultiply3 = pUglyArrays;
    int *pMultiply5 = pUglyArrays;

    while(nextUglyIndex < index)
    {
        minUglyNumber = MinValue(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyArrays[nextUglyIndex] = minUglyNumber;

        //更新位置
        while(*pMultiply2 * 2 <= pUglyArrays[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3 * 3 <= pUglyArrays[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5 * 5 <= pUglyArrays[nextUglyIndex])
            ++pMultiply5;

        ++nextUglyIndex;
    }

    retUglyNumber = pUglyArrays[index-1];
    free(pUglyArrays);
    return retUglyNumber;
}

int MinValue(int number1, int number2, int number3)
{
    int retMin = 0;

    retMin = (number1<number2) ? number1 : number2;
    retMin = (retMin<number3)  ? retMin  : number3;

    return retMin;
}