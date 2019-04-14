#include <iostream>

using namespace std;
/*
һ�������˴�1-N�ߣ�kλ�õ�����ΪEk��
if H(k+1) > Ek, Ek+1 = Ek-(H(k+1)-Ek);
else Ek+1 = Ek+(Ek-H(k+1));
N��λ�õĸ߶�H(K)���������
����С�ĳ�ʼ����

������ѧ���㣬Ek+1 = 2*Ek - H(k+1)  ->  Ek = (Ek+1 + H(k+1)) / 2
*/

void minimumEnergy()
{
	//input
	int n; // N
	cin >> n;
	double a[100]; //����һ���ռ����洢ÿһ���߶�
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	double ek[100]; // �洢��Ӧÿһ���߶�ʱ������
	//�������㣬����������µ�����Ϊ0
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