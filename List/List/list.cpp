#include <iostream>
#include <cstring>

using namespace std;
class List {
private:
	int size, length;
	int* data;
public:
	List(int input_size)
	{
		size = input_size;
		length = 0;
		data = new int[size];
	}

	~List()
	{
		delete[]data;
	}


	void print()
	{
		cout << "当前线性表中的元素：" << endl;
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";

		cout << endl;
		
	}

	//插入
	bool insert(int loc, int value)
	{
		if (loc<0 || loc>length)
		{
			cout << "插入失败" << endl;
			return false;
		}

		if (size <= length)
		{
			cout << "插入失败" << endl;
			return false;
		}
		for (int i = length; i > loc; i--)
		{
			data[i] = data[i - 1];
		}
		data[loc] = value;
		length += 1;
		cout << "插入成功" << endl;
		return true;
	}

	//扩容
	void expand()
	{
		int* old_data = data;
		size = size * 2;
		data = new int[size];
		for (int i = 0; i < length; i++)
		{
			data[i] = old_data[i];
		}
		delete old_data;
	}

	//查找

	int search(int value)
	{
		for (int i = 0; i < length; i++)
		{
			if (data[i] == value)
			{
				return i;
			}
			
		}
		return -1;
	}

	//删除
	bool remove(int index)
	{
		if (index < 0 || index >= length)
		{
			cout << "删除元素失败" << endl;
			return false;
		}
		for (int i = index + 1; i < length; i++)
		{
			data[i-1] = data[i];
		}
		length = length - 1;
		cout << "删除元素" << data[index] << "成功" << endl;
		return true;
	}
};


int main()
{
	List mylist(5);
	cout << mylist.insert(0, 1) << endl;
	cout << mylist.insert(1, 3) << endl;
	cout << mylist.insert(2, 15) << endl;
	cout << mylist.insert(1, 6) << endl;
	mylist.print();
	cout << mylist.remove(1) << endl;
	mylist.print();

	return 0;
}

