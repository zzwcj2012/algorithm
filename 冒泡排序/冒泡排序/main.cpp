#include <iostream>
#include <cstring>
using namespace std;
class Vector {
private:
	int size, length;
	int * data;
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
	void print() {
		for (int i = 0; i < length; ++i) {
			if (i > 0) {
				cout << " ";
			}
			cout << data[i];
		}
		cout << endl;
	}
	void bubble_sort()
	{
		for (int i = 0; i < length - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < length - i - 1; j++)
			{
				if (data[j] > data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
					swapped = true;
				}
			}

			if (swapped == false)
			{
				break;
			}

		}
	}
};
int main() {
	int n;
	cout << "请输入一个整数，表示待排元素的个数：" << endl;;
	cin >> n;
	Vector arr(n);
	cout << "请输入" << n << "个整数：" << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.insert(i, x);
	}
	arr.bubble_sort();
	arr.print();
	return 0;
}