#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
�����沨����ʾ��������ʽ��ֵ��

��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

˵����

��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
ʾ�� 1��

����: ["2", "1", "+", "3", "*"]
���: 9
����: ((2 + 1) * 3) = 9
*/

int evalRPN(vector<string>& tokens)
{
	stack<int> nums;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();
			if (tokens[i] == "+")
				nums.push(b + a);
			if (tokens[i] == "-")
				nums.push(b - a);
			if (tokens[i] == "*")
				nums.push(b * a);
			if (tokens[i] == "/")
				nums.push(b / a);
		}
		else
		{
			nums.push(atoi(tokens[i].c_str()));
			cout << nums.top() << endl;
		}
	}
	
	return nums.top();
}

void evalRPN_main()
{
	vector<string> tokens;
	string str;
	while (cin >> str)
	{
		tokens.push_back(str);
	}

	cout << evalRPN(tokens) << endl;
	return;
}