#include <iostream>
#include <stdio.h>

using namespace std;
/*
����һ��������ľ���ֻ��0 1 2
2���Ⱦ�Լ����������ҵ�1�������ٵĸ�Ⱦ����
*/

int infectRange(int a[][100], int x, int y, int n, int m)
{
	int count = 0;
	if (y - 1 >= 0 && a[x][y - 1] == 1)
	{
		count++;
	}
	if (x - 1 >= 0 && a[x - 1][y] == 1)
	{
		count++;
	}
	if (y + 1 < m && a[x][y + 1] == 1)
	{
		count++;
	}
	if (x + 1 < n && a[x + 1][y] == 1)
	{
		count++;
	}
	return count;
}

int infect(int a[][100], int x, int y, int n, int m)
{
	int left = 0, up = 0, right = 0, down = 0;
	int max_range = 0;//left 1 up 2 right 3 down 4
	int max_range_mark = 1;
	int range = 0;
	if (y - 1 >= 0 && a[x][y - 1] == 1)
	{
		a[x][y - 1] = 2;
		left = 1;
		range = infectRange(a, x, y - 1, n, m);
		if (range > max_range)
		{
			max_range = range;
			max_range_mark = 1;
		}
		
	}
	if (x - 1 >= 0 && a[x - 1][y] == 1)
	{
		a[x - 1][y] = 2;
		up = 1;
		range = infectRange(a, x-1, y, n, m);
		if (range > max_range)
		{
			max_range = range;
			max_range_mark = 2;
		}
		
	}
	if (y + 1 < m && a[x][y + 1] == 1)
	{
		a[x][y + 1] = 2;
		right = 1;
		range = infectRange(a, x, y + 1, n, m);
		if (range > max_range)
		{
			max_range = range;
			max_range_mark = 3;
		}
		
	}
	if (x + 1 < n && a[x + 1][y] == 1)
	{
		a[x + 1][y] = 2;
		down = 1;
		range = infectRange(a, x+1, y, n, m);
		if (range > max_range)
		{
			max_range = range;
			max_range_mark = 4;
		}
		
	}
	if (left == 0 && up == 0 && right == 0 && down == 0)
	{
		return 0;
	}
	int count = 0;
	//�ж���һ�����ܱ߿ɸ�Ⱦ�������ģ��ʹ���һ���㿪ʼѭ����·��
	if (max_range_mark == 1)
	{
		if (y - 1 >= 0 && left == 1)
		{
			count += infect(a, x, y - 1, n, m);
		}
		if (x - 1 >= 0 && up == 1)
		{
			count += infect(a, x-1, y, n, m);
		}
		if (y + 1 < m && right == 1)
		{
			count += infect(a, x, y + 1, n, m);
		}
		if (x + 1 < n && down == 1)
		{
			count += infect(a, x+1, y, n, m);
		}
	}
	if (max_range_mark == 2)
	{
		
		if (x - 1 >= 0 && up == 1)
		{
			count += infect(a, x - 1, y, n, m);
		}
		if (y + 1 < m && right == 1)
		{
			count += infect(a, x, y + 1, n, m);
		}
		if (x + 1 < n && down == 1)
		{
			count += infect(a, x + 1, y, n, m);
		}
		if (y - 1 >= 0 && left == 1)
		{
			count += infect(a, x, y - 1, n, m);
		}
	}
	if (max_range_mark == 3)
	{
		
		if (y + 1 < m && right == 1)
		{
			count += infect(a, x, y + 1, n, m);
		}
		if (x + 1 < n && down == 1)
		{
			count += infect(a, x + 1, y, n, m);
		}
		if (y - 1 >= 0 && left == 1)
		{
			count += infect(a, x, y - 1, n, m);
		}
		if (x - 1 >= 0 && up == 1)
		{
			count += infect(a, x - 1, y, n, m);
		}
	}
	if (max_range_mark == 4)
	{
		
		if (x + 1 < n && down == 1)
		{
			count += infect(a, x + 1, y, n, m);
		}
		if (y - 1 >= 0 && left == 1)
		{
			count += infect(a, x, y - 1, n, m);
		}
		if (x - 1 >= 0 && up == 1)
		{
			count += infect(a, x - 1, y, n, m);
		}
		if (y + 1 < m && right == 1)
		{
			count += infect(a, x, y + 1, n, m);
		}
	}
	cout << "x: " << x << " y: " << y << endl;
	cout << count + 1 << endl;

	return count + 1;
}

void leastInfectTimes()
{
	int a[100][100];//�������ĳ�������100
	//������벻�������������
	int c;
	int n = 0, m = 0;
	//�ȶ�һ��
	while (1)
	{
		cin >> a[0][m];
		m++;
		if (cin.get() == '\n')
			break;
	}
	//�ٶ�ʣ�µ�
	n = 1;
	while (1)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> a[n][i];
		}
		n++;
		if (cin.get() == EOF)
			break;
	}
	//����������ͬ�������߱�̵���վ��ֱ��ʹ������������Զ��벻�����ľ���
	//������VS����Ϊ��βEOF���뻻�У���õ���nҪ��ʵ���ϴ�1
	n--;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 2)
			{
				count += infect(a, i, j, n, m);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
			if (a[i][j] == 1)
				count = -1;
		}
		cout << endl;
	} 

	cout << "���ٵĲ���" << count << endl;

}