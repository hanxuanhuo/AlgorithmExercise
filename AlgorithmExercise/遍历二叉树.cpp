#include <iostream>
#include <stack>

using namespace std;

//使用中序遍历遍历二叉树，非递归
struct Node {
	int val;
	Node * left;
	Node * right;
	Node(int x) :val(x), left(NULL), right(NULL) {};
};

void inOrder(Node *head)
{
	if (head == NULL)
		return;
	stack<Node*> box;
	Node *cur = NULL;
	while (head != NULL || box.empty())
	{
		if (head != NULL)
		{
			box.push(head);
			head = head->left;
		}
		else
		{
			head = box.top();
			box.pop();
			cout << cur->val << endl;
			head = head->right;
		}
	}
}