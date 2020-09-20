/*
* @ 计数排序是稳定的，具有相同的元素在输出数组中的相对
*/
#include <iostream>
#include <vector>

void counting_sort(std::vector<int>& vec)
{
	int length = vec.size();
	std::cout << "length = " << length << std::endl;
	
	if (length == 0)
	{
		std::cout << "数组为空！！！" << std::endl;
		return;
	}

	int maxval = 0; // 记录形参中向量最大元素
	for (auto a : vec)
	{
		if (a > maxval)
			maxval = a;
	}
	std::cout << "maxval = " << maxval << std::endl;
	
	std::vector<int> arr(maxval + 1, 0); // 初始化临时数组， 将其所有元素置为零
	for (auto a : arr)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;

	std::vector<int> b(vec); // 原向量的一份拷贝
	for (auto a : b)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
	// 
	for (int i = 0; i != length; ++i)
	{
		arr[vec[i]] = arr[vec[i]] + 1;
	}
	for (auto a : arr)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;

	//
	for (int j = 1; j != maxval + 1; ++j)
	{
		arr[j] = arr[j] + arr[j - 1];
	}

	for (auto a : arr)
	{
		std::cout << a << " ";
	}
	std::cout << "哈哈" << std::endl;

	//
	for (int i = length - 1; i != 0; --i)
	{
		vec[arr[b[i]] - 1] = b[i]; // arr[b[i]]是为了算出vec[i]这个数在数列中的位置,减去1是因为向量下标从0开始
		arr[b[i]] = arr[b[i]] - 1;
	}

}

int main()
{
	std::vector<int> vec{ 1, 5, 7, 6, 2, 4, 23, 14, 24, 16, 9, 7, 11 };
	counting_sort(vec);
	for (auto a : vec)
		std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}
