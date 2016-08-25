/********************************************
函数功能:求解约瑟夫环问题
参数1:环中元素个数
参数2:待删除的第几个数
返回值:最后剩下的那个数
说明:详细可见笔记《算法——约瑟夫环》
头文件:无
作者: Lee.C
完成时间:2016-08-20
**********************************************/
int LastRemaining1(int nums, int k)
{
    if(nums<1 || k<1)
        return -1;

    list<int> JosephuseLoop;
    for(int i=0; i<nums; i++)
        JosephuseLoop.push_back(i);

    list<int>::iterator current = JosephuseLoop.begin();
    while(JosephuseLoop.size() > 1)
    {
        //循环k-1次，找到第k个节点
        for(int i=1; i<k; i++)
        {
            current++;
            if(current == JosephuseLoop.end())
                current = JosephuseLoop.begin();
        }

        list<int>::iterator next = ++current;
        if(next == JosephuseLoop.end())
            next = JosephuseLoop.begin();

        //list的迭代器不是随机访问迭代器，没有+n的功能，只能先加再减
        --current;

        JosephuseLoop.erase(current);
        current = next;
    }

    return *current;
}

/********************************************
函数功能:求解约瑟夫环问题
参数1:环中元素个数
参数2:待删除的第几个数
返回值:最后剩下的那个数
说明:详细可见笔记《算法——约瑟夫环》
头文件:无
作者: Lee.C
完成时间:2016-08-20
**********************************************/
int LastRemaining2(int nums, int k)
{
    if(nums<1 || k<1)
        return -1;

    int last = 0;
    for(int i=2; i<=nums; i++)
        last = (last + k)%i;

    return last;
}