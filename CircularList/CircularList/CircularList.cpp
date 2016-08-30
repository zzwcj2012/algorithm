//用循环链表解决约瑟夫环问题


#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int _data) {
		data = _data;
		next = NULL;
	}
};
class LinkList {
private:
	Node* head;
public:
	LinkList() {
		head = NULL;
	}

	//循环链表插入元素
	void insert(Node *node, int index) {
		if (head == NULL) {
			head = node;
			head->next = head;
			return;
		}
		if (index == 0) {
			node->next = head->next;
			head->next = node;
			return;
		}
		Node *current_node = head->next;
		int count = 0;
		while (current_node != head && count < index - 1) {
			current_node = current_node->next;
			count++;
		}
		if (count == index - 1) {
			node->next = current_node->next;
			current_node->next = node;
		}

		if (node == head->next)
		{
			head = node;
		}
	}

	//输出被删除的元素
	void output_delete(int m)
	{
		Node* current_node = head;
		while (current_node->next != current_node)
		{
			for (int i = 1; i < m; i++)
			{
				current_node = current_node->next;
			}
			cout << current_node->next->data << " ";
			Node* delete_node = current_node->next;
			current_node->next = current_node->next->next;
			delete delete_node;


		}

		cout << current_node->data << endl;
		delete current_node;
	}
};
	int main() {
		LinkList linklist;
		int n, m;
		cout << "请输入整数n和m,有n个人站成一个环，每数m个人就让其退出" << endl;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			Node* node = new Node(i);
			linklist.insert(node, i - 1);
			linklist.output_delete(m);
		}
		return 0;
	}