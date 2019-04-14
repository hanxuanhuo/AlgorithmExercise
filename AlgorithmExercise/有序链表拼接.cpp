/*
ָ��ָ��ָȥ��һ�黹�Ǻܻ�
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
	if (l1 && l2) // ������
	{
		ListNode *tmp;
		tmp = l1->val < l2->val ? l1 : l2;//�ҵ������������С����һ���Ľڵ㣬��tmp������
		l2 = (tmp == l2) ? l1 : l2;//���l2��С����ԭ����l2��Ϊl1��l1ʼ���Ǳ�ʾС����һ������
		l1 = tmp;
		l1->next = mergeTowLists(l1->next, l2);
		return l1 ? l1 : l2;//l1�ǱȽ�С����������������أ����l1ΪNULL�ˣ���ֱ�ӷ���l2
	}
}