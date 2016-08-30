#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int _data)
	{
		data = _data;
		next = NULL;

	}
};

class LinkList
{
private:
	Node* head;
public:
	LinkList()
	{
		head = NULL;
	}

	//插入节点
	void insert(Node *node, int index) {
		if (head == NULL) {
			head = node;
			return;
		}
		if (index == 0) { //插入位置在表头
			node->next = head;
			head = node;
			return;
		}
		Node *current_node = head;  //用来在链表里遍历
		int count = 0; //统计遍历了多少个结点
		while (current_node->next != NULL && count < index - 1) {
			current_node = current_node->next;
			count++;
		}
		if (count == index - 1) {
			node->next = current_node->next;
			current_node->next = node;
		}
	}

	//遍历链表
	void output()
	{
		if (head == NULL)
		{
			return;
		}
		Node* current_node = head;
		while (current_node != NULL)
		{
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;

	}

	//删除节点

	void delete_node(int index)
	{
		if (head == NULL)
		{
			return;
		}

		Node* current_node = head;
		int count = 0;//统计遍历了多少个结点
		if (index == 0)
		{
			head = head->next;
			delete current_node;
			return;
		}

		while (current_node->next != NULL && count<index - 1)
		{
			current_node = current_node->next;
			count++;
		}

		if (count == index - 1 && current_node->next != NULL)
		{
			Node* delete_node = current_node->next;
			current_node->next = delete_node->next;
			delete delete_node;
		}
	}

	//反转链表
	void reverse()
	{
		if (head == NULL)
		{
			return;
		}
		Node* next_node, *current_node;
		current_node = head->next;
		head->next = NULL; //需初始化为空
		while (current_node != NULL)
		{
			next_node = current_node->next;
			current_node->next = head; //头结点调到当前节点的下个节点
			head = current_node;//当前节点成为头结点
			current_node = next_node;//更新当前节点
		}
	}
};

int main()
{
	LinkList linklist;
	
	for (int i = 1; i <= 10; i++) {
		Node *node = new Node(i);
		linklist.insert(node, i - 1);
	}

	linklist.output();

	linklist.delete_node(3);
	linklist.output();
	linklist.reverse();
	linklist.output();
	return 0;
}
