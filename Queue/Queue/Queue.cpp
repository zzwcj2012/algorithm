#include <iostream>
#include <cassert>
using namespace std;

class Queue {
private:
	int *data;
	int head, tail, length; //����Ԫ�أ���βԪ�أ����鳤��
public:
	Queue(int length_input)
	{
		data = new int[length_input];
		length = length_input;
		head = 0;
		tail = -1;


	}

	~Queue()
	{
		delete[] data;
	}

	//�����в���Ԫ��
	void push(int element)
	{
		if (tail + 1<length)
		{
			tail++;
			data[tail] = element;
		}
	}

	//���������Ԫ��
	void output() {
		for (int i = head; i <= tail; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	int front() //����Ԫ�����
	{
		assert(head <= tail);
		return data[head];
	}

	void pop() //ɾ������Ԫ��
	{
		assert(head <= tail);
		head++;
	}
};

int main() {
	Queue queue(1000);
	for (int i = 1; i <= 10; i++)
	{
		queue.push(i);
	}
	queue.output();
	cout << queue.front() << endl;
	queue.pop();
	queue.output();
	return 0;
}