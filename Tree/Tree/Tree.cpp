#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* lchild, *rchild;
	Node(int _data)
	{
		data = _data;
		lchild = NULL;
		rchild = NULL;
	}

	~Node()
	{
		if (lchild != NULL)
		{
			delete lchild;
		}

		if (rchild != NULL)
		{
			delete rchild;
		}
	}

	//先序输出二叉树
	void preorder()
	{
		cout << data << " ";
		if (lchild != NULL)
		{
			lchild->preorder();
		}
		if (rchild != NULL)
		{
			rchild->preorder();
		}
	}
	//中序
	void inorder() {
		if (lchild != NULL) {
			lchild->inorder();
		}
		cout << data << " ";
		if (rchild != NULL) {
			rchild->inorder();
		}
	}
	//后序
	void postorder()
	{
		if (lchild != NULL)
		{
			lchild->postorder();
		}
		if (rchild != NULL)
		{
			rchild->postorder();
		}
		cout << data << " ";
	}

};

class BinaryTree {
private:
	Node* root;


public:
	BinaryTree()
	{
		root = NULL;
	}
	~BinaryTree()
	{
		if (root != NULL)
		{
			delete root;
		}
	}

	void build_demo()//二叉树的存储函数
	{
		root = new Node(1);
		root->lchild = new Node(2);
		root->rchild = new Node(3);
		root->lchild->lchild = new Node(4);
		root->lchild->rchild = new Node(5);
		root->rchild->rchild = new Node(6);
	}

	void preorder()
	{
		root->preorder();
	}

	void inorder() {
		root->inorder();
	}

	void postorder()
	{
		root->postorder();
	}
};


int main() {

	BinaryTree binarytree;
	binarytree.build_demo();
	binarytree.preorder();
	cout << endl;
	binarytree.inorder();
	cout << endl;
	binarytree.postorder();
	cout << endl;
	return 0;
}