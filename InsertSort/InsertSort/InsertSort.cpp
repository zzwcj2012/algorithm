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
	void sort() {

	}
};
int main() {
	
	int n;
	cout << "������һ����������ʾ���鳤�ȣ�" << endl;
	cin >> n;
	Vector arr(n);
	cout << "������" << n << "����������ʾ�����йؼ��ֵ�ֵ��" << endl;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.insert(i, x);
	}
	cout << "����Ľ���ǣ�" << endl;
	arr.sort();
	arr.print();
	return 0;
}