#include <iostream>
#include <vector>

using namespace std;

/*
�������������е���
�����д������ҵ������д��ϵ��µ���

����˼·��һ�����ҵ�һ����׼���������Ͻǻ������½ǣ����Ͻ����з��򶼱���С���з��򶼱�����Ȼ������
һ����ʹ�ö��ֲ��ң�ע��ֻ����һ�������϶��ֲ��ң���Ϊa��ߵ�����һ����a�������С
*/
void Find()
{
	vector<vector<int>> a{ {1, 4 , 5, 6},{2, 6, 8, 9}, {4, 7, 9, 11} };
	int target = 10;
	int rows = a.size();
	int cols = a[0].size();
	int x = rows - 1;
	int y = 0;
	while (x >= 0 && y < cols)
	{
		if (target == a[x][y])
		{
			cout << "true" << endl;
			return;
		}
		if (target < a[x][y])
		{
			x--;
			//��Ϊ������x�Ѿ������ģ������ʹ��continue������ıȽ��Ǵ��
			continue;
		}
		if (target > a[x][y])
		{
			y++;
			continue;
		}
	}
	cout << "false" << endl;
	return;
}