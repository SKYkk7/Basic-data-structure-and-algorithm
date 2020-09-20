/*
* 基数排序：记住计数排序是基数排序的一个子过程
* 重点：在使用范围for语句的时候要慎重
*/

#include <iostream>
#include <vector>

void printVec(std::vector<int> vec)
{
	for (auto a : vec)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
}

void countingSort(std::vector<int>& vec) // 计数排序
{
	int maxval = 0;
	for (auto a : vec)
	{
		if (a > maxval)
			maxval = a;
	}
	std::vector<int> temp(vec);
	std::vector<int> a(maxval + 1, 0);

	for (int i = 0; i != vec.size(); ++i)
	{
		a[vec[i]] = a[vec[i]] + 1;
	}
	std::cout << "哈哈2" << std::endl;

	for (int i = 1; i != maxval + 1; ++i) // 
	{
		a[i] = a[i] + a[i - 1];
	}
	std::cout << "哈哈1" << std::endl;

	for (int i = vec.size() - 1; i != 0; --i)
	{
		vec[a[temp[i]] - 1] = temp[i];
		a[temp[i]] = a[temp[i]] - 1;
	}

}

int maxbit(const std::vector<int>& vec)
{
	int max_bit = 1;
	int p = 10;
	for (auto a = vec.begin(); a != vec.end(); ++a)
	{
		if (*a >= p)
		{
			++max_bit;
			p = p * 10;
		}
	}
	return max_bit;
}

void RadixSort(std::vector<int>& vec)
{
	int d = maxbit(vec);
	std::vector<int> count(10, 0);
	int radix = 1;
	std::vector<int> temp(vec);

	for (int i = 1; i != d + 1; ++i)
	{
		for (auto a = count.begin(); a != count.end(); ++a)   // 每次将计数器清空
		{
			*a = 0;
		}
		printVec(vec);
		printVec(count);
		// 下面三个for循环，都是计数排序的过程
		for (int j = 0; j != vec.size(); ++j)
		{
			int k = (vec[j] / radix) % 10; 
			count[k] = count[k] + 1;
		}
		printVec(count);

		for (int j = 1; j != 10; ++j)
		{
			count[j] = count[j] + count[j - 1];
		}
		printVec(count);
		
		for (int j = vec.size() - 1; j >= 0; --j)
		{
			int k = (vec[j] / radix) % 10;
			temp[count[k] - 1] = vec[j];
			count[k] = count[k] - 1;
		}
		printVec(temp);

		for (int j = 0; j != vec.size(); ++j)
		{
			vec[j] = temp[j];
		}
		printVec(vec);
		radix = radix * 10;
	}
}

int main()
{
	std::vector<int> vec{ 61, 46, 24, 29, 82, 14, 90, 19, 63 };
	RadixSort(vec);
	for (auto a : vec)
		std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}
