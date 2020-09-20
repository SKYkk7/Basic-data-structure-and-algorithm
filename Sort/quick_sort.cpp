/*
* 快速排序（升序/降序实现）
*/
#include <iostream>

void QuickSort1(int array[], int begin, int end) // 升序排列
{
	if (end > begin)
	{
		int temp = array[begin];
		int i = begin;
		int j = end;
		while (i < j)
		{
			while (j > i && array[j] > temp)
				--j;
			array[i] = array[j];

			while (j > i && array[i] <= temp)
				++i;
			array[j] = array[i];
		}

		array[i] = temp;
		QuickSort1(array, begin, i - 1);
		QuickSort1(array, i + 1, end);
	}
	else  // 如果数组中只有一个数，返回
		return;
}

void QuickSort2(int array[], int begin, int end)
{
	if (end > begin)
	{
		int temp = array[begin];
		int i = begin;
		int j = end;

		while (i < j)
		{
			while (i < j && array[j] < temp)
				--j;
			array[i] = array[j];
			while (i < j && array[i] >= temp)
				++i;
			array[j] = array[i];
		}

		array[i] = temp;
		QuickSort2(array, begin, i - 1);
		QuickSort2(array, i + 1, end);
	}
	else
		return;
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
		std::cout << array[i] << "  ";
	std::cout << std::endl;
}

int main()
{
	int a[] = { 5, 8, 3, 58, 14, 65, 88, 23, 19, 84, 64, 24, 3, 16, 33 };
	int length = sizeof(a) / sizeof(a[0]);

	printArray(a, length);
	QuickSort2(a, 0, length - 1);
	printArray(a, length);

	return 0;
}
