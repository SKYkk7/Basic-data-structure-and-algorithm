/*
* 堆排序实现升序排列和降序排列
*/
#include <iostream>

int PARENT(int i)
{
	return i / 2;
}

int LEFT(int i)
{
	return 2 * i + 1;
}

int RIGHT(int i)
{
	return 2 * (i + 1);
}

void PrintArray(int a[], int length)
{
	for (int i = 0; i < length; ++i)
		std::cout << a[i] << "  ";
	std::cout << std::endl;
}

void MaxHeapify(int array[], int i, int heapsize) // 排序大顶堆
{
	int l = LEFT(i);  // i的左孩子节点下标
	int r = RIGHT(i);  // i的右孩子节点下标
	int largest = 0;  // 保存i, l, r之间最大数的下标

	if (l < heapsize && array[l] > array[i])
		largest = l;
	else
		largest = i;
	if (r < heapsize && array[r] > array[i] && array[r] > array[l])
		largest = r;

	if (largest != i)
	{
		int temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;

		MaxHeapify(array, largest, heapsize);
	}

}

void MinHeapify(int array[], int i, int heapsize)  // 排序小顶堆
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int smallest = 0;

	if (l < heapsize && array[l] < array[i])
		smallest = l;
	else
		smallest = i;

	if (r < heapsize && array[r] < array[i] && array[r] < array[l])
		smallest = r;
	if (smallest != i)
	{
		int temp = array[smallest];
		array[smallest] = array[i];
		array[i] = temp;

		MinHeapify(array, smallest, heapsize);
	}
}

void BuildMaxHeap(int array[], int length) // 构建大顶堆
{
	for (int i = length / 2 - 1; i >= 0; --i)  // 从最后一个非叶子节点开始构建
	{
		MaxHeapify(array, i, length);
	}
}

void BuildMinHeap(int array[], int length) // 构建小顶堆
{
	for (int i = length / 2 - 1; i >= 0; --i)
	{
		MinHeapify(array, i, length);
	}
}

void HeapSort1(int array[], int length)  // 用堆排序实现升序排序
{
	BuildMaxHeap(array, length);
	
	for (int i = length - 1; i > 0; --i)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		//PrintArray(array, length);
		MaxHeapify(array, 0, i);
	}
}

void HeapSort2(int array[], int length) // 用堆排序实现降序排列
{
	BuildMinHeap(array, length);
	for (int i = length - 1; i > 0; --i)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		MinHeapify(array, 0, i); // 只有根节点没有排序好，将其下沉即可
	}
}

int main()
{
	int a[] = { 38, 15, 33, 19, 444, 78, 25, 14, 3, 6, 8, 24, 11, 45, 54, 78, 14, 69, 25, 147, 66, 25, 12 };
	int length = sizeof(a) / sizeof(a[0]);
	std::cout << "原数组的长度为： " << length << std::endl;
	std::cout << "原数组为：";
	PrintArray(a, length);

	HeapSort1(a, length);
	std::cout << "升序排列后数组为：";
	PrintArray(a, length);

	HeapSort2(a, length);
	std::cout << "降序排列后数组为：";
	PrintArray(a, length);

	return 0;
}