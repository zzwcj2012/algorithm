#include <iostream>
#include <string>
using namespace std;

//��N�����Ӵ�x����y�ƶ���z
void move(int n, string x, string y, string z)
{
	if (n == 1)
	{
		cout << x<<"-->"<<z<< endl;
	}
	else
	{
		move(n - 1, x, z, y); //��n-1�����Ӵ�x����z�ƶ���y��
		cout << x<<"-->"<<z << endl;//����n�����Ӵ�x�Ƶ�z��
		move(n - 1, y, x, z);//��n-1�����Ӵ�y����x�Ƶ�z��
	}
}

int main()
{
	int n;
	cout << "�����뺺ŵ���Ĳ���:" << endl;
	cin >> n;
	cout << "�ƶ��Ĳ�������:" << endl;
	
	move(n,"x", "y","z");
}