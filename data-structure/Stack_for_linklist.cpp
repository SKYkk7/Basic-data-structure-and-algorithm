#include <iostream>
#include <string>

// 节点结构
template<typename T>
class Node
{
public:
	Node() = default;
	Node(T value, Node<T>* next): _value(value), _next(next) {}
public:
	T _value;
	Node* _next;
};

// 单链表
template<typename T>
class SingleLink
{
public:
	typedef Node<T>* pointer;
	SingleLink();
	~SingleLink();

	int size();
	bool isEmpty();

	Node<T>* insert(int index, T t);  // 在指定位置进行插入
	Node<T>* insert_head(T t);  // 在表头进行插入
	Node<T>* insert_last(T t);  // 在表尾进行插入

	Node<T>* del(int index);  // 在指定位置删除元素
	Node<T>* delete_head();  // 删除表头元素
	Node<T>* delete_last();  //删除表尾元素

	T get(int index);  // 获取指定位置元素
	T get_head();  // 获取表头元素
	T get_last();  // 获取表尾元素

	Node<T>* getHead();  // 获取链表头结点
	void printStack();
private:
	int _count;
	Node<T>* _phead;
private:
	Node<T>* getNode(int index);  // 获取指定位置节点
};

// 构造函数
template<typename T>
SingleLink<T>::SingleLink() : _count(0), _phead(nullptr)
{
	// 创建头节点
	_phead = new Node<T>();
	_phead->_next = nullptr;
}

// 析构函数
template<typename T>
SingleLink<T>::~SingleLink()
{
	Node<T>* pNode = _phead->_next;
	if (pNode != nullptr)
	{
		Node<T>* temp = pNode;    // 析构头节点吗
		pNode = pNode->_next;
		delete temp;
	}
}

// 返回指定位置的上一个节点
template<typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
	if (_count < index || index < 0)
		return nullptr;
	int temp = 0;
	Node<T>* preNode = _phead;
	while (temp < index)
	{
		preNode = preNode->_next;
		++temp;
	}
	return preNode;
}

// 求链表长度
template<typename T>
int SingleLink<T>::size()
{
	return _count;
}

// 判断链表是否为空
template<typename T>
bool SingleLink<T>::isEmpty()
{
	return _count == 0;
}

// 获取链表头节点
template<typename T>
Node<T>* SingleLink<T>::getHead()
{
	return _phead;
}

//获取指定位置元素
template<typename T>
T SingleLink<T>::get(int index)
{
	Node<T>* preNode = getNode(index);
	T value = preNode->_next->_value;
	return value;
}

// 获取来年表头元素
template<typename T>
T SingleLink<T>::get_head()
{
	Node<T>* preNode = getNode(0);
	T value = preNode->_next->_value;
	return value;
}

// 获取表尾元素
template<typename T>
T SingleLink<T>::get_last()
{
	Node<T>* preNode = getNode(_count);
	T value = preNode->_next->_value;
	return value;
}

template<typename T>
Node<T>* SingleLink<T>::insert(int index, T t)
{
	Node<T>* preNode = getNode(index);
	if (preNode)
	{
		Node<T>* newnode = new Node<T>(t, preNode->_next);
		preNode->_next = newnode;
		++_count;
		return newnode;
	}
	return nullptr;
}

// 在表头插入元素
template<typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
	return insert(0, t);
}

// 在表尾插入元素
template<typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert(_count, t);
}

// 删除指定位置元素
template<typename T>
Node<T>* SingleLink<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	std::cout << " 12" << std::endl;
	Node<T>* preNode = getNode(index);
	Node<T>* delNode = preNode->_next;
	preNode->_next = delNode->_next;
	_count--;
	std::cout << "15" << std::endl;
	delete delNode;
	delNode = nullptr;
	return preNode->_next;
}

// 删除表头元素
template<typename T>
Node<T>* SingleLink<T>::delete_head()
{
	return del(0);
}

// 删除表尾元素
template<typename T>
Node<T>* SingleLink<T>::delete_last()
{
	return del(_count);
}

template<typename T>
void SingleLink<T>::printStack()
{
	Node<T>* temp = _phead;
	for (int i = 0; i != _count; ++i)
	{
		temp = temp->_next;
		std::cout << temp->_value << "  ";
	}
		std::cout << std::endl;
}

int main()
{
	SingleLink<std::string> istack;
	istack.insert_head("老邹");
	istack.insert_head("焰哥");
	istack.insert_head("haah");
	istack.insert_head("sb");
	istack.delete_last();
	//istack.insert_head("haha");

	std::cout << "栈的大小为： " << istack.size() << std::endl;
	std::cout << "栈顶元素为： " << istack.get_head() << std::endl;
	istack.printStack();

	return 0;
}
