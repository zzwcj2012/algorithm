//��ѭ��������Լɪ������


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

	//ѭ���������Ԫ��
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

	//�����ɾ����Ԫ��
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
		cout << "����������n��m,��n����վ��һ������ÿ��m���˾������˳�" << endl;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			Node* node = new Node(i);
			linklist.insert(node, i - 1);
			linklist.output_delete(m);
		}
		return 0;
	}