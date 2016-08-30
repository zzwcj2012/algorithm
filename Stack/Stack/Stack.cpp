#include<iostream>
#include<string>
#include<cassert>
using namespace std;

template <class Type> class Stack {
private:
	Type* urls;
	int max_size, top_index;

public:
	Stack(int length_input)
	{
		urls = new Type[length_input];
		max_size = length_input;
		top_index = -1;

	}
	~Stack()
	{
		delete[] urls;
	}

	bool push(const Type& element) //入栈函数
	{
		if (top_index >= max_size - 1)
		{
			return false;
		}

		top_index++;
		urls[top_index] = element;
		return true;
	}

	bool pop() //出栈函数
	{
		if (top_index < 0)
		{
			return false;
		}
		top_index--;
		return true;
	}

	// 输出栈顶元素
	Type top()
	{
		assert(top_index >= 0);
		return urls[top_index];

	}


};

int main() 
{

	int n,m;
	cout << "请输入两个整数n和m，n代表栈的高度，m代表入栈元素数量" << endl;
	cin >> n>>m;
	Stack<string> stack(n);
	for (int i = 1; i <= m; i++)
	{
		cout << "请输入代表操作的编号,0表示插入元素，1表示删除栈顶元素，2表示输出栈顶元素" << endl;
		int opr; 
		cin >> opr;
		if (opr == 0)
		{
			string element;
			cout << "请输入要插入的元素" << endl;
			cin >> element;
			if (stack.push(element))
			{
				cout << "push success!" << endl;
			}

			else
			{
				cout << "push failed!" << endl;
			}

		}


		else if (opr == 1)
		{
			if (stack.pop())
			{
				cout << "pop success!" << endl;
			}
			else
			{
				cout << "pop failed!" << endl;
			}
		}

		else if (opr == 2)
		{
			cout << stack.top() << endl;
		}
	}
	return 0;
}