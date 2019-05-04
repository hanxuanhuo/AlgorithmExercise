#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//merge sort

void merge(vector<int> &arr, int start, int end, int mid, vector<int> &help)
{
	int i = start;
	int p1 = start;
	int p2 = mid+1;
	cout << start << " - " << end << endl;
	cout << "p1" << p1 << "p2" << p2 << endl;
	cout << ((p1 <= mid) && (p2 <= end)) << endl;
	while (p1 <= mid && p2 <= end)
	{
		cout << arr[p1] << "   :   " << arr[p2] << endl;
		help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
		cout << help[i - 1] << endl;
	}
	while (p1 <= mid)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= end)
	{
		help[i++] = arr[p2++];
	}
	for (i = start; i <= end; i++)
	{
		arr[i] = help[i];
	}
}

void sortProcess(vector<int> &arr, int start, int end, vector<int> &help)
{
	if (start == end)
		return;
	int mid = start + ((end - start) / 2);
	sortProcess(arr, start, mid, help);
	sortProcess(arr, mid + 1, end, help);
	cout << "start " << start << "  end " << end << "  mid  " << mid << endl;
	merge(arr, start, end, mid, help);
}

void mergeSort(vector<int> &arr, vector<int> &help)
{
	if (arr.size() == 0)
		return;
	sortProcess(arr, 0, arr.size() - 1, help);
}

void mergeSort_main()
{
	vector<int> arr;
	int item;
	while (cin >> item)
	{
		arr.push_back(item);
	}
	vector<int> help(arr.size(), 0);
	vector<int> copy(arr);
	mergeSort(arr, help);
	sort(copy.begin(), copy.end());
	for (int i = 0; i < help.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << copy[i] << " ";
	}

}