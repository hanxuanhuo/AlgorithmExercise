#include <iostream>
#include <stdio.h>

using namespace std;
/*
对于一个长款不定的矩阵，只有0 1 2
2会感染自己的上下左右的1，求最少的感染次数
*/

int loc[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int infectRange(int a[][100], int x, int y, int n, int m)
{
	int count = 0;
	for (int i = 0;i < 4; i++)
	{
		int new_x = x + loc[i][0];
		int new_y = y + loc[i][1];
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] == 1)
			count++;
	}
	return count;
}

int infect(int a[][100], int x, int y, int n, int m)
{
	int left = 0, up = 0, right = 0, down = 0;
	int max_range = 0;//left 0 up 1 right 2 down 3
	int max_range_mark = 0;
	int range = 0;
	if (y - 1 >= 0 && a[x][y - 1] == 1)
	{
		a[x][y - 1] = 2;
		left = 1;	
	}
	if (x - 1 >= 0 && a[x - 1][y] == 1)
	{
		a[x - 1][y] = 2;
		up = 1;
	}
	if (y + 1 < m && a[x][y + 1] == 1)
	{
		a[x][y + 1] = 2;
		right = 1;
	}
	if (x + 1 < n && a[x + 1][y] == 1)
	{
		a[x + 1][y] = 2;
		down = 1;
		
	}
	if (left == 0 && up == 0 && right == 0 && down == 0)
	{
		return 0;
	}
	int count = 0;
	//每次从还没有感染的点里选一个能感染的数量最多的
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			range = infectRange(a, x + loc[i][0], y + loc[i][1], n, m);
			if (range > max_range)
			{
				max_range = range;
				max_range_mark = i;
			}
		}
		count += infect(a, x + loc[max_range_mark][0], y + loc[max_range_mark][1], n, m);
	}

	cout << "x: " << x << " y: " << y << endl;
	cout << count + 1 << endl;

	return count + 1;
}

void leastInfectTimes()
{
	int a[100][100];//假设矩阵的长宽最大就100
	//解决输入不定长矩阵的问题
	int c;
	int n = 0, m = 0;
	//先读一行
	while (1)
	{
		cin >> a[0][m];
		m++;
		if (cin.get() == '\n')
			break;
	}
	//再读剩下的
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
	//这里有所不同，在在线编程的网站上直接使用这个方法可以读入不定长的矩阵
	//但是在VS下因为结尾EOF必须换行，则得到的n要比实际上大1
	n--;
	//两种额外的情况，没有2，没有1

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

	cout << "最少的步数" << count << endl;
	return;
}