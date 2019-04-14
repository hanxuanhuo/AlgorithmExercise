/*
LeetCodeԭ��
�ҵ������ַ�������Ļ����Ӵ�������s����󳤶�Ϊ1000

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч��
*/

#include <iostream>
#include <string>

using namespace std;

//������ͨ�Ķ�̬�滮����
//o(N2)ʱ�临�Ӷ���ռ临�Ӷ�
//ע����Ϊ��Ҫ�ݽ��ĵ��ã�������ʵ�ǲ��ܹ��ӣ�0��0����ʼ����Ҫ�ӣ�n-1��n-1����ʼ
string longestPalindrome(string s)
{
	int dp[100][100] = {0};//VS����ʹ��dp[1001][1001]���������С�����С��������
	int max = 1;//˳�㴢��������Ӵ��ĳ���
	int start;
	string ans = "";
	
	//�ȼ���ַ�������
	if (s.size() == 0)
	{
		return s;
	}

	//׼����ʼ���±꣬�ӣ�n-1��n-1����ʼ
	int n = s.size();
	//�ȳ�ʼ������Ϊ1�ͳ���Ϊ2�����
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			//max = 2�����ҲҪ����
			max = 2;
			start = i;
		}
		else
		{
			dp[i][i + 1] = 0;
		}
	}

	for (int i = n - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < n; j++)
		{
			dp[i][j] = (int)(dp[i + 1][j - 1] && (s[i] == s[j]));
			//������ʼλ��ֻ��max���µ�ʱ����
			if (dp[i][j] && (max < (j-i+1)))
			{
				max = j - i + 1;
				start = i;
			}
		}
	}
	for (int i = start; i < max; i++)
	{
		ans += s[i];
	}
	return ans;
}