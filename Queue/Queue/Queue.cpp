#include <iostream>
#include <cassert>
using namespace std;

class Queue {
private:
	int *data;
	int head, tail, length; //队首元素，队尾元素，数组长度
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

	//队列中插入元素
	void push(int element)
	{
		if (tail + 1<length)
		{
			tail++;
			data[tail] = element;
		}
	}

	//输出队列中元素
	void output() {
		for (int i = head; i <= tail; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	int front() //队首元素输出
	{
		assert(head <= tail);
		return data[head];
	}

	void pop() //删除队首元素
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