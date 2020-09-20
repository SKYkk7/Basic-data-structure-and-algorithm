
#include <iostream>
#include <vector>
#include <time.h>

void printVector(std::vector<int> vec)
{
	for (auto a : vec)
		std::cout << a << " ";
	std::cout << std::endl;
}

int partition(std::vector<int>& vec, int begin, int end)
{
	int temp = 0;
	srand((unsigned)time(NULL));
	temp = rand() % (end - begin + 1) + begin;
	
	int p = begin;
	int r = end;
	while (r > p)
	{
		while (r > p && temp < vec[r])
			--r;
		vec[p] = vec[r];

		while (r > p && temp >= vec[p])
			++p;
		vec[r] = vec[p];
	}
	vec[p] = temp;
	return p;
}


void quicksort(std::vector<int>& vec, int begin, int end)
{
	if (begin < end)
	{
		int temp = partition(vec, begin, end);
		quicksort(vec, begin, temp - 1);
		quicksort(vec, temp + 1, end);
	}
}



int main()
{
	std::vector<int> vec{ 4, 69, 36, 14, 2, 3, 6, 4, 8, 25, 11 };
	quicksort(vec, 0, vec.size() - 1);
	printVector(vec);

	return 0;
}
