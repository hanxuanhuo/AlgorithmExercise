#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/

int maxProfit(vector<int> &prices);
int maxProfit2(vector<int> &prices);
int maxProfit3(vector<int> &prices);
int maxProfit4(vector<int> &prices);
void main_maxProfit()
{
	vector<int> prices;
	int price;
	while (cin >> price)
	{
		prices.push_back(price);
	}

	cout << maxProfit4(prices) << endl;
	return;
}

int maxProfit(vector<int> &prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}
	vector<int> max(prices.size());
	vector<int> min(prices.size());
	max[prices.size() - 1] = prices[prices.size()-1];
	min[0] = prices[0];
	//以第i位结尾的子串的最小值是多少
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < min[i - 1])
		{
			min[i] = prices[i];
		}
		else
		{
			min[i] = min[i - 1];
		}
	}
	//以第i位开头的子串的最大值是多少
	for (int i = prices.size() - 2; i >= 0; i--)
	{
		if (prices[i] > max[i+1])
		{
			max[i] = prices[i];
		}
		else
		{
			max[i] = max[i + 1];
		}
	}



	int maxprofit = 0;
	for (int i = 1; i < prices.size();i++)
	{
		maxprofit = maxprofit > (max[i] - min[i - 1]) ? maxprofit : (max[i] - min[i - 1]);
	}
	return maxprofit;
}

int maxProfit2(vector<int> &prices)
{
	int valley = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < valley)
		{
			valley = prices[i];
		}
		else if(prices[i] - valley > maxprofit)
		{
			maxprofit = prices[i] - valley;
		}
	}
	return maxprofit;
}

/*
峰谷  峰-谷
可以尽可能多的完成交易
*/
int maxProfit3(vector<int> &prices)
{
	int valley = INT_MAX; 
	int peak = 0;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < peak)
		{
			cout << "valley: " << valley << " peak: " << peak << endl;
			maxprofit += peak - valley;
			peak = 0;
			valley = INT_MAX;
		}
		if (prices[i] < valley)
		{
			valley = prices[i];
		}
		else if (prices[i] > peak)
		{
			peak = prices[i];
		}
		
		
	}
	if(peak != 0)
		maxprofit += peak - valley;
	return maxprofit;
}

/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
*/
//暴力解法
int maxProfit4_assis(vector<int> &prices, int start, int end)
{
	int valley = INT_MAX;
	int maxprofit = 0;
	for (int i = start; i < end; i++)
	{
		if (prices[i] < valley)
		{
			valley = prices[i];
		}
		else if (prices[i] - valley > maxprofit)
		{
			maxprofit = prices[i] - valley;
		}
	}
	return maxprofit;
}

int maxProfit4(vector<int> &prices)
{
	if (prices.size() < 2)
		return 0;
	int maxprofit1 = 0;
	int maxprofit2 = 0;
	maxprofit1 = maxProfit4_assis(prices, 0, prices.size());

	for (int i = 2; i < prices.size() - 1; i++)
	{ 
		int profit = maxProfit4_assis(prices, 0, i) + maxProfit4_assis(prices, i, prices.size());
		maxprofit2 = profit > maxprofit2 ? profit : maxprofit2;
	}
	return maxprofit1 > maxprofit2 ? maxprofit1 : maxprofit2;
}

/*
牛逼
考虑 到该天为止第一次买入获得的最大收益（这个受益的当天结算的，买入就是-的）
     到该天为止第一次卖出获得的最大收益
	 到该天为止第二次买入获得的最大收益
	 到该天为止第二次卖出获得的最大收益
更新
	如果当天第一次买入比之前获得收益更大，则更新
	如果当天第一次卖出比之前获得的收益更大，则更新
	同理

	因此考虑的是遍历历史最大收益
*/
int maxprofit5(vector<int> &prices)
{
	int fstbuy = INT_MIN;
	int fstsell = 0;
	int secbuy = INT_MIN;
	int secsell = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		fstbuy = fstbuy > -prices[i] ? fstbuy : -prices[i];
		fstsell = fstsell > fstbuy + prices[i] ? fstsell : fstbuy + prices[i];
		secbuy = secbuy > fstsell - prices[i] ? secbuy : fstsell - prices[i];
		secsell = secsell > secbuy + prices[i] ? secsell : secbuy + prices[i];
	}
	return secsell;
}