#include "binary_search_tree.h"


// 默认构造函数
template <typename T>
BSTree<T>::BSTree() : root(nullptr) {}

// 析构函数
template <typename T>
BSTree<T>::~BSTree()
{
	destory(root);
}

// 插入函数
template <typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T>* pnode = root;
	BSNode<T>* pparent = nullptr;

	while (pnode != nullptr)    // 寻找合适的插入位置
	{
		pparent = pnode;
		if (pnode->value > key)
			pnode = pnode->lchild;
		else if (pnode->value < key)
			pnode = pnode->rchild;
		else
			break;
	}

	pnode = new BSNode<T>(key);
	if (pparent == nullptr)
	{
		root = pnode;
	}
	else
	{
		if (key > pparent->value)
			pparent->rchild = pnode;
		else
			pparent->lchild = pnode;
	}
	pnode->parent = pparent;    // 指明新节点的父节点
}
// 查找指定节点（非递归）
template <typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T>* p = root;
	while (p != nullptr)
	{
		if (key == p->value)    // 找到
			return p;
		if (key < p->value)     // 关键字比节点值小，在节点左子树上查找
			p = p->lchild;
		else
			p = p->rchild;      // 关键字比节点值大，在节点右子树上查找
	}

	return nullptr;
}
// 查找指定节点（递归）
template <typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);
}

// 查找递归的类内部实现
template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* pnode, T key)
{
	if (pnode == nullptr)
		return nullptr;
	if (pnode->value == key)
		return pnode;

	if (pnode->value > key)
		return search(pnode->lchild, key);
	else
		return search(pnode->rchild, key);
}

// 删除指定节点
template <typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
}

// 删除指定节点，类内部实现
template <typename T>
void BSTree<T>::remove(BSNode<T>* pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel = nullptr;
			if (pnode->lchild == nullptr || pnode-> rchild == nullptr)    // 情况二：被删除节点只有左子树或右子树或都没有
				pdel = pnode;
			else
				pdel = predecessor(pnode);    // 情况一：被删除节点同时有左右子树，则删除该节点的前驱

			// 此时被删除节点只有一个孩子，或没有孩子（保存孩子指针）
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;

			// 让孩子指向被删除节点的父节点
			if (pchild != nullptr)
				pchild->parent = pdel->parent;

			// 如果要删除的节点是父节点，注意更改root的值
			if (pdel->parent == nullptr)
				root = pchild;

			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
				pdel->parent->rchild = pchild;

			if (pnode->value != pdel->value)
				pnode->value = pdel->value;
			delete pdel;
		}
		else if (pnode->value > key)
			remove(pnode->lchild, key);
		else
			remove(pnode->rchild, key);
	}
}

// 查找指定节点的前驱节点
/*
* 一个节点的前驱节点有下面三种情况：
* 1：存在左子树时，其左子树中最大值为其前驱节点。
* 2：不存在左子树时，且它本身为右子树时，其前驱为其父节点
* 3：不存在左子树时。且它本身为左子树时，其前驱为右父母的第一个左父母
*/
template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>* pnode)
{
	if (pnode->lchild != nullptr)   // 第一种情况
	{
		pnode = pnode->lchild;
		while (pnode->lchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while(pnode->parent != nullptr && pparent->lchild == pnode)    // 成立则为第三种情况，否则为第二种情况
	{
		pnode = pparent;
		pparent = pnode->parent;
	}
	return pparent;
}

// 查找指定节点的后继节点
/*
* 一个节点的后继节点有下面三种情况
* 1：存在右子树时，其后继节点为右子树中最小的节点
* 2：不存在右子树时，且它本身为左子树时，其前驱节点为其父节点
* 3：不存在右子树时，且它本身为右子树时，其前驱节点为其左父母的第一个右父母
*/
template <typename T>
BSNode<T>* BSTree<T>::successor(BSNode<T>* pnode)
{
	if (pnode->rchild != nullptr)   // 第一种情况
	{
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while (pnode->parent != nullptr && pparent->rchild == pnode)    // 成立则为第三种情况，否则为第二种情况
	{
		pnode = pparent;
		pparent = pnode->parent;
	}
	return pparent;
}

// 前序遍历算法
template <typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
}

template <typename T>
void BSTree<T>::preOrder(BSNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		std::cout << pnode->value;
		preOrder(pnode->lchild);
		preOrder(pnode->rchild);
	}
}

// 中序遍历算法
template <typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}

template <typename T>
void BSTree<T>::inOrder(BSNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		inOrder(pnode->lchild);
		std::cout << pnode->value << std::endl;
		inOrder(pnode->rchild);
		std::cout << "haha" << std::endl;
	}
}

// 后序遍历算法
template <typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
}

template <typename T>
void BSTree<T>::postOrder(BSNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		postOrder(pnode->lchild);
		postOrder(pnode->rchild);
		std::cout << pnode->value << std::endl;
	}
}

// 寻找最小元素
template <typename T>
T BSTree<T>::search_minimun()
{
	return search_minimun(root);
}

template <typename T>
T BSTree<T>::search_minimun(BSNode<T>* pnode)
{

		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}
		return pnode->value;

}

// 寻找最大元素
template <typename T>
T BSTree<T>::search_maximun()
{
	return search_maximun(root);
}

template <typename T>
T BSTree<T>::search_maximun(BSNode<T>* pnode)
{
		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode->value;

}

// 销毁二叉搜索树
template <typename T>
void BSTree<T>::destory()
{
	destory(root);
}

template <typename T>
void BSTree<T>::destory(BSNode<T>* &pnode)
{
	if (pnode != nullptr)
	{
		if (pnode->lchild != nullptr)
			destory(pnode->lchild);
		if (pnode->rchild != nullptr)
			destory(pnode->rchild);
		delete pnode;
		pnode = nullptr;
	}
}