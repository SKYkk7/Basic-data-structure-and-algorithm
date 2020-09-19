/*插入排序（升序和降序）*/


#include <iostream>


void insertion_sort_1(int a[], int length)  // 插入排序（升序）
{
	for (int i = 1; i < length; ++i)
	{
		/*---------------for循环---------------*/
		//for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; --j)
		//{
		//		int temp = a[j];
		//		a[j] = a[j + 1];
		//		a[j + 1] = temp;
		//}

		/*---------------while循环---------------*/
		int j = i - 1;
		while (j >= 0 && a[j + 1] < a[j])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			--j;
		}
	}

}

void insertion_sort_2(int a[], int length) // 插入排序（降序）
{
	for (int i = 0; i < length; ++i)
	{
		int j = i - 1;
		while (j >= 0 && a[j + 1] > a[j])
		{
			int temp = a[j + 1];
			a[j + 1] = a[j];
			a[j] = temp;
			--j;
		}
	}
}

int main()
{
	int n, a[10];
	std::cout << "请输入你想排序的个数: ";
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cout << "请输入第" << i + 1 << "个数： ";
		std::cin >> a[i];
	}
	insertion_sort_1(a, n);
	std::cout << "升序排列： " << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << "  " << std::endl;

	insertion_sort_2(a, n);
	std::cout << "降序排列:  " << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << std::endl;

	return 0;
}