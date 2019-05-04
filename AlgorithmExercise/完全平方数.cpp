#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
/*
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ�������
����: n = 12
���: 3
����: 12 = 4 + 4 + 4.
*/
//����static��leetcode�������
map<int, int> computed;
map<int, int>::iterator iter;
int numSquares(int n)
{
	if (sqrt(n) - floor(sqrt(n)) == 0)
	{
		cout << n << " is a complete square number" << endl;
		return 1;
	}
	iter = computed.find(n);
	if (iter != computed.end())
	{
		return iter->second;
	}

	int g_min = INT_MAX;
	int count = 0;
	for (int i = int(floor(sqrt(n))); i > 0; i--)
	{
		int tmp = n - pow(i, 2);
		count = numSquares(tmp) + 1;
		cout << n << " = " << tmp << " + " << pow(i, 2) << " count = " << count << endl;
		g_min = g_min > count ? count : g_min;
	}
	computed[n] = g_min;
	cout << n << " has least " << g_min << " additions" << endl;
	return g_min;
}

int numSquares_dp(int n)
{
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int g_min = INT_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			g_min = g_min > dp[i - j*j] ? dp[i - j*j] : g_min;
			cout << i << " = " << j*j << " + " << i - j*j << " g_min = " << g_min + 1 << endl;
		}
		dp[i] = g_min + 1;
	}
	return dp[n];
}

void numSquares_main()
{
	int n;
	cin >> n;
	numSquares(n);
	numSquares_dp(n);

	return;
}