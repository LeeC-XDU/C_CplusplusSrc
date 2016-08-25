/**********************************
函数功能:计数连续1和连续-1的最大个数
参数1:读入数据的文件名
参数2(Output):连续1的最大个数
参数3(Output):连续-1的最大个数
返回值:无
说明:读入的数据类似 1 -1 1 1 1 ...
头文件:<stdio.h>
作者: Lee.C
完成时间:2016-07-17
**************************************/
void CountContiousOne(const char *fileName, int *PosNum, int *NegNum)
{
    FILE *fp = fopen(fileName, "r");
    int preval = 0;
    int val = 0;
    int negative = 0;
    int positive = 0;
    *PosNum = 0;
    *NegNum = 0;

    fscanf(fp, "%d", &preval);
    if(preval>0)
        positive++;
    else
        negative++;

    while(fscanf(fp, "%d", &val) != EOF)
    {
        if(preval<0 && val<0)
        {
            negative++;
        }
        else if(preval>0 && val>0)
        {
            positive++;
        }
        else if(preval<0 && val>0)
        {
            positive++;
            if(*NegNum < negative)
                *NegNum = negative;
            negative = 0;
        }
        else if(preval>0 && val<0)
        {
            negative++;
            if(*PosNum < positive)
                *PosNum = positive;
            positive = 0;
        }
        preval = val;
    }

    if(*NegNum < negative)
        *NegNum = negative;
    if(*PosNum < positive)
        *PosNum = positive;

    fclose(fp);
}