/**********************************
模块功能:游标尺的输出
说明:尾递归，物理情景也挺明确的，见《C++ Primer Plus》P241
作者: Lee.C
完成时间:2016-03-20
修改时间:
**************************************/
#include <iostream>
const int Len = 66;
const itn Divs = 6;

void subdivide(char *ar, int low, int high, int level);

int main()
{
	char ruler[Len];
	int i;
	for(int i=1; i<Len-2; i++)
		ruler[i] = ' ';
	ruler[Len-1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;
	for(i=1; i<=Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for(int j=1; j<Len-2; j++)
			ruler[j] = ' ';
	}
	return 0;
}

void subdivide(char *ar, int low, int high, int level)
{
	if(level == 0)
		return;
	//以下两步为原子操作
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}