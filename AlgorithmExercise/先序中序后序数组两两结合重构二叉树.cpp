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
���������ع�
*/
Node *preIn(int pre[], int p_start, int p_end, int in[], int in_start, int in_end, map<int, int> hash);
Node *preIntoTree(int pre[], int in[])
{
	if (pre == NULL || in == NULL)
		return NULL;
	//��һ��map������������ݺ��±���ڲ���
	int in_length = sizeof(in) / sizeof(in[0]);
	int pre_length = sizeof(pre) / sizeof(pre[0]);

	map<int, int> hash;
	for (int i = 0;i < in_length;i++)
	{
		hash[in[i]] = i;
	}

	return preIn(pre, 0, pre_length - 1, in, 0, in_length-1, hash);
}

//�ݹ������������򡣹�����
//����ĵ�һ��һ����ͷ�ڵ㣬���������ҵ�ͷ�ڵ㣬ͷ�ڵ���߾������������ұ���������
//����ͷ�ڵ����������������еĳ�����һ����
Node *preIn(int pre[], int p_start, int p_end, int in[], int in_start, int in_end, map<int, int> hash)
{
	Node head(pre[0]);
	map<int, int>::iterator iter;
	iter = hash.find(pre[0]);
	head.left = preIn(pre, p_start + 1, p_start + iter->second - in_start, in, in_start, in_start + iter->second-1, hash);
	head.right = preIn(pre, p_start + iter->second - in_start + 1, p_end, in, iter->second + 1, in_end, hash);
	return &head;
}