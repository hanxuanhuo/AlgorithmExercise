#include <iostream>

using namespace std;
/*
一个机器人从1-N走，k位置的能量为Ek，
if H(k+1) > Ek, Ek+1 = Ek-(H(k+1)-Ek);
else Ek+1 = Ek+(Ek-H(k+1));
N个位置的高度H(K)由外界输入
求最小的初始能量

经过数学推算，Ek+1 = 2*Ek - H(k+1)  ->  Ek = (Ek+1 + H(k+1)) / 2
*/

void minimumEnergy()
{
	//input
	int n; // N
	cin >> n;
	double a[100]; //保留一个空间来存储每一个高度
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	double ek[100]; // 存储对应每一个高度时的能量
	//倒着推算，最后最少留下的能量为0
	ek[n - 1] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ek[i - 1] = (ek[i] + a[i]) / 2;
	}
	int ans;
	ans = ceil((ek[0] + a[0]) / 2);
	cout << ans << endl;
	return;
}