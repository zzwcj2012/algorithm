#include <iostream>
#include <string>
using namespace std;

//将N个盘子从x借助y移动到z
void move(int n, string x, string y, string z)
{
	if (n == 1)
	{
		cout << x<<"-->"<<z<< endl;
	}
	else
	{
		move(n - 1, x, z, y); //将n-1个盘子从x借助z移动到y上
		cout << x<<"-->"<<z << endl;//将第n个盘子从x移到z上
		move(n - 1, y, x, z);//将n-1个盘子从y借助x移到z上
	}
}

int main()
{
	int n;
	cout << "请输入汉诺塔的层数:" << endl;
	cin >> n;
	cout << "移动的步骤如下:" << endl;
	
	move(n,"x", "y","z");
}