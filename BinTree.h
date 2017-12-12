#pragma once
#include <iostream>

template <typename T>
struct node
{
	T inf;
	node<T> *left, *right;
};

template <typename T>
class BinTree
{
	node<T> *root;
	void DeleteBinTree(node<T>* &p) const;
	void Copy(node<T>* &pos, node<T>* const& r) const;
	void CopyBinTree(BinTree<T> const& other);
	void print(const node<T>* p) const;
	void CreateBinTree(node<T>* &r) const;
public:
	BinTree();
	BinTree(BinTree<T> const& other);
	BinTree& operator=(BinTree<T> const& other);
	~BinTree();

	T RootBinTree() const;
	BinTree<T>& LeftBinTree() const;
	BinTree<T>& RightBinTree() const;
	node<T>* GetRoot();
	bool empty() const;
	void printTree() const;
	void Create();
	void Create3(T x, BinTree<T> left, BinTree<T> right);
};

template <typename T>
BinTree<T>::BinTree() : root(NULL) {}

template <typename T>
BinTree<T>::BinTree(BinTree<T> const& other)
{
	CopyBinTree(other);
}

template <typename T>
BinTree<T>& BinTree<T>::operator=(BinTree<T> const& other)
{
	if (this != &other)
	{
		DeleteBinTree(root);
		CopyBinTree(other);
	}
	return *this;
}

template <typename T>
BinTree<T>::~BinTree()
{
	DeleteBinTree(root);
}

template <typename T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const
{
	if (p)
	{
		DeleteBinTree(p->left);
		DeleteBinTree(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void BinTree<T>::Copy(node<T>* &pos, node<T>* const& r) const
{
	pos = NULL;
	if (r)
	{
		pos = new node<T>;
		pos->inf = r->inf;
		Copy(pos->left, r->left);
		Copy(pos->right, r->right);
	}
}

template <typename T>
void BinTree<T>::CopyBinTree(BinTree<T> const& other)
{
	Copy(root, other.root);
}

template <typename T>
void BinTree<T>::print(const node<T>* p) const
{
	if (p)
	{
		print(p->left);
		std::cout << p->inf << " ";
		print(p->right);
	}
}

template <typename T>
void BinTree<T>::CreateBinTree(node<T>* &r) const
{
	T x;
	char c;
	std::cout << "root: ";
	std::cin >> x;

	r = new node<T>;
	r->inf = x;
	r->left = NULL;
	r->right = NULL;

	std::cout << "Left BinTree of: " << x << " y/n?\n";
	std::cin >> c;
	if (c == 'y') CreateBinTree(r->left);

	std::cout << "Right BinTree of: " << x << " y/n?\n";
	std::cin >> c;
	if (c == 'y') CreateBinTree(r->right);
}

template <typename T>
T BinTree<T>::RootBinTree() const
{
	return root->inf;
}

template <typename T>
bool BinTree<T>::empty() const
{
	return root == NULL;
}

template <typename T>
node<T>* BinTree<T>::GetRoot()
{
	return root;
}

template <typename T>
BinTree<T>& BinTree<T>::LeftBinTree() const
{
	BinTree<T> tree;
	Copy(tree, root->left);
	return tree;
}

template <typename T>
BinTree<T>& BinTree<T>::RightBinTree() const
{
	BinTree<T> tree;
	Copy(tree, root->right);
	return tree;
}

template <typename T>
void BinTree<T>::printTree() const
{
	print(root);
}

template <typename T>
void BinTree<T>::Create()
{
	CreateBinTree(root);
}

template <typename T>
void BinTree<T>::Create3(T x, BinTree<T> left, BinTree<T> right)
{
	root = new node<T>;
	root->inf = x;
	Copy(root->left, left.root);
	Copy(root->right, right.root);
}