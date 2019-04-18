#include <iostream>
#include <vector>

using namespace std;

/*
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
*/

int maxProfit(vector<int> &prices);
int maxProfit2(vector<int> &prices);
int maxProfit3(vector<int> &prices);
void main_maxProfit()
{
	vector<int> prices;
	int price;
	while (cin >> price)
	{
		prices.push_back(price);
	}

	cout << maxProfit3(prices) << endl;
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
	//�Ե�iλ��β���Ӵ�����Сֵ�Ƕ���
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
	//�Ե�iλ��ͷ���Ӵ������ֵ�Ƕ���
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
���  ��-��
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