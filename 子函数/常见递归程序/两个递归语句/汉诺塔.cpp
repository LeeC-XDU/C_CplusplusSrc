/**********************************
模块功能:汉诺塔的实现和打印输出
说明:标准的尾递归，物理场景很明确
     注意分析的过程
	 (1)将多个盘子从一个针移动到另一个针上，这是一个递归过程
	 (2)将一个盘子从一个针上移动到另一个针上
	 参考《C++程序设计》P77
作者: Lee.C
完成时间:2016-03-20
修改时间:
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
	move(src, dest);		//这一步是原子操作
	hanoi(n-1, medium, src, dest);
}