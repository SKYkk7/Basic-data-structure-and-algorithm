#include <iostream>

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s);  // 构造函数
	~ArrayStack();  // 析构函数
public:
	T top();  // 获取栈顶元素
	void push(T t);  // 压栈操作
	T pop();  // 出栈操作
	bool isEmpty();  // 判空
	int size();  // 求栈大小
private:
	int count = 0;  // 栈的元素数量
	int capacity = sizeof(array) / sizeof(array[0]);  // 栈的容量
	T* array;  // 底层为数组
};

template<typename T>
ArrayStack<T>::ArrayStack(int s) : count(0), capacity(s), array(nullptr)
{
	array = new T[capacity];
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	if (array)
	{
		delete[] array;
		array = nullptr;
	}
}
template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
T ArrayStack<T>::top()
{
	if (count != 0)
	{
		return array[count - 1];
	}
	else
	{
		std::cout << "此时栈为空！！！" << std::endl;
		return 1;
	}
}

template<typename T>
void ArrayStack<T>::push(T t)
{
	if (count < capacity)
	{
		array[count++] = t;  // count可以是栈顶指针，始终指向最后一个一个元素的下一个位置
	}
	//else
	//{
	//	std::cout << "栈满！！！" << std::endl;
	//	return 1;
	//}
}

template<typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)
	{
		return array[--count];         
	}
	else
	{
		std::cout << "此时栈为空！！！" << std::endl;
		return 1;
	}
											// 发生错误C4715,待解决
}

template<typename T>
int ArrayStack<T>::size()
{
	return count;
}

int main()
{
	ArrayStack<int> p = 5;
	for (int i = 0; i < 5; ++i)
	{
		p.push(i);
	}

	std::cout << "栈的大小为： " << p.size() << std::endl;
	std::cout << "栈顶元素为： " << p.top() << std::endl;
	std::cout << "栈是否为空： " << p.isEmpty() << std::endl;
	std::cout << "依次出栈： " << std::endl;
	while (!p.isEmpty())
	{
		std::cout << p.pop() << std::endl;
	}

	return 0;
}
