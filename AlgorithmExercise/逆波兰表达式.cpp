#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
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