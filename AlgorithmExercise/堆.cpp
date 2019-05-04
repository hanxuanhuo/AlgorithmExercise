#include <iostream>
#include <vector>

using namespace std;
/*
堆实现
堆插入
堆调整
堆排序
*/

static void swap(vector<int> &heap, int index1, int index2)
{
	int tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void heapInsert(vector<int> &heap, int index)
{
	//(index-1)/2是父节点，这里构建的是最大堆
	while (heap[index] > heap[(index - 1) / 2])
	{
		swap(heap, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

//往下调整  heapsize是指示堆的有效区域
void heapify(vector<int> &heap, int index, int heapsize)
{
	int left = index * 2 + 1;
	while (left < heapsize)
	{
		int largest = ((left + 1) < heapsize) && (heap[left] < heap[left + 1]) ? left+1 : left;
		if (heap[index] < heap[largest])
		{
			swap(heap, index, largest);
			index = largest;
			left = index * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//将一个混乱的数组调整为最大堆  最小堆同理
void createHeap(vector<int> &heap)
{
	//log1+log2+log3+.... -> O(N)
	for (int i = 0; i < heap.size();i++)
	{
		heapInsert(heap, i);
	}
}

void heapSort(vector<int> &heap)
{
	int heapsize = heap.size();
	while (heapsize > 0)
	{
		swap(heap, 0, --heapsize);
		heapify(heap, 0, heapsize);
	}
}

void printHeap(vector<int> &heap)
{
	int line = 0;
	int limit = pow(2, line);
	for (int i = 0; i < heap.size(); )
	{
		cout << heap[i++] << " ";
		if (i == limit)
		{
			cout << endl;
			line++;
			limit += pow(2, line);
		}
	}
}
void heap_main()
{
	vector<int> heap;
	int item;
	while (cin >> item)
	{
		heap.push_back(item);
	}
	printHeap(heap);
	createHeap(heap);
	printHeap(heap);

	heapSort(heap);
	printHeap(heap);
}