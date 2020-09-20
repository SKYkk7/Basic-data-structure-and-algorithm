#include <iostream>
#include <cstring>

void Merge(int array[], int nStart_, int nMiddle_, int nEnd_)
{
	if (array == nullptr || nStart_ > nMiddle_ || nMiddle_ > nEnd_)
		return;
	 
	// 建立一个临时数组，存放中间数据
	int nIndex = 0;
	int* newarray = new int[nEnd_ - nStart_]; // 临时的数组。最后一定要手动释放

	// 对两个子数组进行合并
	int _nStartchange = nStart_;
	int _nMiddlechange = nMiddle_;
	while (_nStartchange < nMiddle_ && _nMiddlechange < nEnd_)
	{
		if (array[_nStartchange] > array[_nMiddlechange])
		{
			newarray[nIndex] = array[_nMiddlechange];
			++_nMiddlechange;
		}
		else
		{
			newarray[nIndex] = array[_nStartchange];
			++_nStartchange;
		}

		++nIndex;
	}

	if (nMiddle_ > _nStartchange)
		memcpy(newarray + nIndex, array + _nStartchange, sizeof(int) * (nMiddle_ - _nStartchange));
	else if (nEnd_ > _nMiddlechange)
		memcpy(newarray + nIndex, array + _nMiddlechange, sizeof(int) * (nEnd_ - _nMiddlechange));
	else
	{

	}

	// 交换数据
	memcpy(array + nStart_, newarray, sizeof(int) * (nEnd_ - nStart_));
	delete[] newarray;
	newarray = nullptr;
}

// 归并排序实现函数
void Merge_sort(int array[], int _nStart, int _nEnd)
{
	if (array == nullptr || _nEnd - _nStart <= 1) // 数组指针为空，或者数组内的个数少于或等于一个时，直接返回
		return;

	// 划分为两个子数组，并递归调用自身进行排序
	int _nMiddle = (_nStart + _nEnd) / 2;

	// 检测输出
	for (int i = _nStart; i < _nMiddle; ++i) // 0~4
		std::cout << array[i] << " ";
	std::cout << std::endl;
	for (int i = _nMiddle; i < _nEnd; ++i) 
		std::cout << array[i] << " ";
	std::cout << std::endl;


	Merge_sort(array, _nStart, _nMiddle);  // 0 5；
	Merge_sort(array, _nMiddle, _nEnd);  // 5 10；

	// 合并排序完成的子数组
	Merge(array, _nStart, _nMiddle, _nEnd);
}

// 打印数组函数
void print(int array[], int length)
{
	if (array == nullptr || length <= 0)
		return;
	for (int i = 0; i < length; ++i)
		std::cout << array[i] << "  ";
	std::cout << std::endl;
}

int main()
{
	// 测试1
	int array1[9] = { 3, 41, 52, 26, 38, 57, 9, 49, 14};
	print(array1, 9);
	Merge_sort(array1, 0, 9);
	print(array1, 9);

/*-------------------------------------------------------------

4  86  32  5  7  64  32  14  56  24
4 86 32 5 7
64 32 14 56 24
4 86
32 5 7
4
86
32
5 7
5
7
64 32
14 56 24
64
32
14
56 24
56
24
4  5  7  14  24  32  32  56  64  86

分治法的典型例子

----------------------------------------------------------------------*/

	return 0;
}