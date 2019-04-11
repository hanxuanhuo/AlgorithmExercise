/*
LeetCode原题
找到给定字符串中最长的回文子串，假设s的最大长度为1000

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案
*/

#include <iostream>
#include <string>

using namespace std;

//采用普通的动态规划方法
//o(N2)时间复杂度与空间复杂度
//注意因为需要递进的调用，所以其实是不能够从（0，0）开始，而要从（n-1，n-1）开始
string longestPalindrome(string s)
{
	int dp[100][100] = {0};//VS调试使用dp[1001][1001]堆溢出，减小数组大小可以运行
	int max = 1;//顺便储存最长回文子串的长度
	string ans = "";
	
	//先检查字符串长度
	if (s.size() == 0)
	{
		return s;
	}

	//准备初始的下标，从（n-1，n-1）开始
	int n = s.size();
	//先初始化长度为1和长度为2的情况
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			//max = 2的情况也要计算
			max = 2;
			start = i;
		}
		else
		{
			dp[i][i + 1] = 0;
		}
	}

	int start = 0;//记录最长子串的起始下标
	for (int i = n - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < n; j++)
		{
			dp[i][j] = (int)(dp[i + 1][j - 1] && (s[i] == s[j]));
			//更新起始位置只在max更新的时候发生
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