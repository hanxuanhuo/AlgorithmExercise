#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
输入:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
输出:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
*/

void setZeros(vector<vector<int>> &matrix)
{
	if (matrix.size() == 0)
		return;
	bool firstrow = false;
	bool firstcol = false;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			firstcol = true;
			break;
		}
	}
	for (int j = 0; j < matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			firstrow = true;
			break;
		}
	}
	for (int i = 1; i< matrix.size(); i++)
	{
		for (int j = 1; j < matrix[0].size();j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < matrix[0].size(); j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	for (int j = 1; j < matrix.size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < matrix[0].size(); i++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	
	if (firstcol)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i][0] = 0;
		}
	}
	if (firstrow)
	{
		for (int j = 0; j < matrix[0].size();j++)
		{
			matrix[0][j] = 0;
		}
	}
	return;
}

void setZeros_main()
{
	vector<vector<int>> matrix;
	vector<int> row;
	int item;
	while (cin >> item)
	{
		row.push_back(item);
		if (cin.get() == '\n')
		{
			matrix.push_back(row);
			row.clear();
		}
	}
	
	setZeros(matrix);

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size();j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return;
}