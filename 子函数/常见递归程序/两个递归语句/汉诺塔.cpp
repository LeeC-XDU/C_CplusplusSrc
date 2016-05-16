/**********************************
ģ�鹦��:��ŵ����ʵ�ֺʹ�ӡ���
˵��:��׼��β�ݹ飬����������ȷ
     ע������Ĺ���
	 (1)��������Ӵ�һ�����ƶ�����һ�����ϣ�����һ���ݹ����
	 (2)��һ�����Ӵ�һ�������ƶ�����һ������
	 �ο���C++������ơ�P77
����: Lee.C
���ʱ��:2016-03-20
�޸�ʱ��:
**************************************/
#include <iostream>
using namespace std;

void move(char src, char dest);
void hanoi(int n, char src, char medium, char dest);


int main()
{
	int m;
	cout << "Enter the number of disks: ";
	cin >> m;
	cout << "the steps to moving " << m << "diskes: " << endl;
	hanoi(m, 'A', 'B', 'C');
	return 0;
}

void move(char src, char dest)
{
	cout << src << "-->" << dest << endl;
}

void hanoi(int n, char src, char medium, char dest)
{
	if(n==1)
	{
		move(src,dest);
		return;
	}

	hanoi(n-1, src, dest, medium);
	move(src, dest);		//��һ����ԭ�Ӳ���
	hanoi(n-1, medium, src, dest);
}