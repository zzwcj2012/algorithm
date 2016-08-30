//线性表的循环左移
/** 
输入格式：

第一行输入两个整数 n(1 \leq n \leq 100)n(1≤n≤100) 和 k(0 \leq k \leq n)k(0≤k≤n)，分别表示顺序表的元素个数和循环左移的位移量。

第二行一共 nn 个整数 a_i(0 \leq a_i \leq 10000)a
​i
​​ (0≤a
​i
​​ ≤10000)，表示顺序表中元素的值。

输出格式：

输出输出只有一行 nn 个整数，顺序输出循环左移后顺序表中每个元素的值，每个元素之间用一个空格分隔。行末不要有多余空格。**/

#include <iostream>
#include <cstring>
using namespace std;
class Vector {
private:
	int size, length;
	int *data;
public:
	Vector(int input_size) {
		size = input_size;
		length = 0;
		data = new int[size];
	}
	~Vector() {
		delete[] data;
	}
	bool insert(int loc, int value) {
		if (loc < 0 || loc > length) {
			return false;
		}
		if (length >= size) {
			return false;
		}
		for (int i = length; i > loc; --i) {
			data[i] = data[i - 1];
		}
		data[loc] = value;
		length++;
		return true;
	}


	int search(int value) {
		for (int i = 0; i < length; ++i) {
			if (data[i] == value) {
				return i;
			}
		}
		return -1;
	}
	bool remove(int index) {
		if (index < 0 || index >= length) {
			return false;
		}
		for (int i = index + 1; i < length; ++i) {
			data[i - 1] = data[i];
		}
		length = length - 1;
		return true;
	}
	void print() {
		for (int i = 0; i<length; i++)
		{
			if (i>0)
			{
				cout << " ";
			}
			cout << data[i];
		}
		cout << endl;

	}

	int get_data(int index)
	     {
		        if (index < 0 || index >= length)
		             return -1;
		         else {
			            return data[index];
			
		}
		     



	}
};
int main() {
	int  n, k, m;
	cout << "请输入两个整数 n和 k，分别表示顺序表的元素个数和循环左移的位移量：" << endl;
	cin >> n >> k;
	Vector a(n);
	cout << "请输入" << n<< "个数字创建线性表" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a.insert(i,m);

	}

	for (int i = 0; i < k; i++)
	{
		
		int temp = a.get_data(0);
		a.remove(0);
		a.insert(n - 1, temp);
	}

	cout << "移位后的元素是：" << endl;
	a.print();

	

	return 0;
}