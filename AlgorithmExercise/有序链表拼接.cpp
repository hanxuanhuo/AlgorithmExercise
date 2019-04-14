/*
指针指来指去这一块还是很混
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode * mergeTowLists(ListNode *l1, ListNode *l2)
{
	if (l1 && l2) // 都存在
	{
		ListNode *tmp;
		tmp = l1->val < l2->val ? l1 : l2;//找到两个链表里较小的哪一个的节点，用tmp存起来
		l2 = (tmp == l2) ? l1 : l2;//如果l2较小，则将原来的l2改为l1，l1始终是表示小的那一个链表
		l1 = tmp;
		l1->next = mergeTowLists(l1->next, l2);
		return l1 ? l1 : l2;//l1是比较小的数，将这个数返回，如果l1为NULL了，则直接返回l2
	}
}