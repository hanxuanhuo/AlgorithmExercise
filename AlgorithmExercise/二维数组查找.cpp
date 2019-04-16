#include <iostream>
#include <vector>

using namespace std;

/*
查找有序数组中的数
数组行从左至右递增，列从上到下递增

两种思路，一种是找到一个基准，比如右上角或者左下角，右上角在行方向都比他小，列方向都比他大，然后搜索
一种是使用二分查找；注意只能在一个方向上二分查找，因为a左边的数不一定比a下面的数小
*/
void Find()
{
	vector<vector<int>> a{ {1, 4 , 5, 6},{2, 6, 8, 9}, {4, 7, 9, 11} };
	int target = 10;
	int rows = a.size();
	int cols = a[0].size();
	int x = rows - 1;
	int y = 0;
	while (x >= 0 && y < cols)
	{
		if (target == a[x][y])
		{
			cout << "true" << endl;
			return;
		}
		if (target < a[x][y])
		{
			x--;
			//因为到这里x已经被更改，如果不使用continue，下面的比较是错的
			continue;
		}
		if (target > a[x][y])
		{
			y++;
			continue;
		}
	}
	cout << "false" << endl;
	return;
}