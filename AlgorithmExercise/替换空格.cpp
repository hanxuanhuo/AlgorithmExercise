#include <iostream>

using namespace std;

/*
将字符串中的空格替换为%20
*/

void replaceSpace()
{
	char *str = "";
	int length = 0;

	if (str == NULL || length <= 0)
	{
		return;
	}
	int blank_count = 0;
	for (int i = 0; i < 20; i++)
	{
		if (str[i] == ' ')
			blank_count++;
	}
	int new_length = length + blank_count * 2;
	char *ans = new char[new_length + 1];
	for (int i = 0, j = 0; j < new_length; i++, j++)
	{
		if (i == length)
			break;
		if (str[i] == ' ')
		{
			ans[j++] = '%';
			ans[j++] = '2';
			ans[j] = '0';
		}
		else
		{
			ans[j] = str[i];
		}
	}
	ans[new_length] = '\0';
	for (int i = 0; i < new_length; i++)
	{
		cout << ans[i];
	}
	delete[]ans;
	return;
}