#include <iostream>
#include <map>

using namespace std;
struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int x) : val(x), left(NULL), right(NULL) {};
};

/*
先序，中序重构
*/
Node *preIn(int pre[], int p_start, int p_end, int in[], int in_start, int in_end, map<int, int> hash);
Node *preIntoTree(int pre[], int in[])
{
	if (pre == NULL || in == NULL)
		return NULL;
	//用一个map来存中序的内容和下标便于查找
	int in_length = sizeof(in) / sizeof(in[0]);
	int pre_length = sizeof(pre) / sizeof(pre[0]);

	map<int, int> hash;
	for (int i = 0;i < in_length;i++)
	{
		hash[in[i]] = i;
	}

	return preIn(pre, 0, pre_length - 1, in, 0, in_length-1, hash);
}

//递归遍历先序和中序。规律是
//先序的第一个一定是头节点，在中序中找到头节点，头节点左边就是左子树，右边是右子树
//先序头节点后和中序左子树序列的长度是一样的
Node *preIn(int pre[], int p_start, int p_end, int in[], int in_start, int in_end, map<int, int> hash)
{
	Node head(pre[0]);
	map<int, int>::iterator iter;
	iter = hash.find(pre[0]);
	head.left = preIn(pre, p_start + 1, p_start + iter->second - in_start, in, in_start, in_start + iter->second-1, hash);
	head.right = preIn(pre, p_start + iter->second - in_start + 1, p_end, in, iter->second + 1, in_end, hash);
	return &head;
}