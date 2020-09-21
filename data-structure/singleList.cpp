#ifndef SINGLE_LIST_ZJY
#define SINGLE_LIST_ZJY

template<typename T>
class Node
{
public:
	
	Node() = default;
	Node(T value, Node* next): _value(value), _next(next) {}
public:
	T _value;
	Node* _next;
};

template<typename T>
class SingleLink
{
public:
	typedef Node<T>* pointer;
	SingleLink();
	~SingleLink();

	int size();
	bool isEmpty();

	Node<T>* insert(int insert, T t);   // 在指定位置插入
	Node<T>* insert_head(T t);   // 在链表头部插入
	Node<T>* insert_last(T t);   // 在链表尾部插入

	void del(int index);   // 删除指定位置节点
	void delete_head();   // 删除表头位置节点
	void delete_last();   // 删除表尾位置节点

	//T get(int index);   // 获得指定位置节点元素
	//T get_head();   // 获得头节点元素
	//T get_last();   // 获得尾节点元素

	Node<T>* getHead();   // 获得链表头节点
private:
	int _count;
	Node<T>* _phead;  // 头指针
private:
	Node<T>* getNode(int index);   // 获取指定索引的上一个节点
};

// 默认构造函数
template<typename T>
SingleLink<T>::SingleLink() : _count(0), _phead(nullptr)
{
	_phead = new Node<T>();
	_phead->_next = nullptr;
};

// 析构函数
template<typename T>
SingleLink<T>::~SingleLink()
{
	Node<T>* pNode = _phead;
	while (pNode != nullptr)
	{
		Node<T>* temp = pNode;
		pNode = pNode->_next;
		delete temp;
	}
};

// 返回指定索引的上一个节点
template<typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
	if (index > _count || index < 0)
		return nullptr;

	int temp = 0;
	Node<T>* preNode = _phead;
	while (temp < index)
	{
		++temp;
		preNode = preNode->_next;
	}
	return preNode;
}

// 傅斯年回头节点
template<typename T>
Node<T>* SingleLink<T>::getHead()
{
	return _phead->_next;
}
// 返回链表的长度
template<typename T>
int SingleLink<T>::size()
{
	return _count;
};

//判断链表是否为空
template<typename T>
bool SingleLink<T>::isEmpty()
{
	return _count == 0;
};

// 在链表指定位置插入
template<typename T>
Node<T>* SingleLink<T>::insert(int index, T t)
{
	Node<T>* preNode = getNode(index);
	if (preNode)
	{
		Node<T>* newNode = new Node<T>(t, preNode->_next);
		preNode->_next = newNode;        // 问题？？？
		++_count;
		return newNode;
	}
	return nullptr;
};

// 在链表头部插入
template<typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
	return insert(0, t);
};

// 在链表尾部插入
template<typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert(_count, t);
};

// 删除指定索引处元素
template<typename T>
void SingleLink<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	Node<T>* preNode = getNode(index);
	Node<T>* delNode = preNode->_next;
	preNode->_next = delNode->_next;
	--_count;
	delete delNode;
};

// 删除链表首节点
template<typename T>
void SingleLink<T>::delete_head()
{
	del(0);
}
;
// 删除链表尾节点
template<typename T>
void SingleLink<T>::delete_last()
{
	del(_count);
};

//// 返回指定索引元素
//template<typename T>
//T SingleLink<T>::get(int index)
//{
//    Node<T>* isNode = getNode(index);
//	return isNode->_value;
//}
//
//// 返回链表首节点元素
//template<typename T>
//T SingleLink<T>::get_head()
//{
//	return get(1);
//}
//
////返回链表尾节点元素
//template<typename T>
//T SingleLink<T>::get_last()
//{
//	return get(_count);
//}
#endif // !SINGLE_LIST