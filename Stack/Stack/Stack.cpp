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

	bool push(const Type& element) //��ջ����
	{
		if (top_index >= max_size - 1)
		{
			return false;
		}

		top_index++;
		urls[top_index] = element;
		return true;
	}

	bool pop() //��ջ����
	{
		if (top_index < 0)
		{
			return false;
		}
		top_index--;
		return true;
	}

	// ���ջ��Ԫ��
	Type top()
	{
		assert(top_index >= 0);
		return urls[top_index];

	}


};

int main() 
{

	int n,m;
	cout << "��������������n��m��n����ջ�ĸ߶ȣ�m������ջԪ������" << endl;
	cin >> n>>m;
	Stack<string> stack(n);
	for (int i = 1; i <= m; i++)
	{
		cout << "�������������ı��,0��ʾ����Ԫ�أ�1��ʾɾ��ջ��Ԫ�أ�2��ʾ���ջ��Ԫ��" << endl;
		int opr; 
		cin >> opr;
		if (opr == 0)
		{
			string element;
			cout << "������Ҫ�����Ԫ��" << endl;
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