/**********************************
ģ�鹦��:�α�ߵ����
˵��:β�ݹ飬�����龰Ҳͦ��ȷ�ģ�����C++ Primer Plus��P241
����: Lee.C
���ʱ��:2016-03-20
�޸�ʱ��:
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
	//��������Ϊԭ�Ӳ���
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}