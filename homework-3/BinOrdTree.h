#pragma once
#include <iostream>

template <typename T>
struct node
{
	T inf;
	node<T> *left;
	node<T> *right;
};

template <typename T>
class BinOrdTree
{
	node<T>* root;
	void DeleteTree(node<T>* &p) const;
	void Copy(node<T>* &pos, node<T>* const&r) const;
	void CopyTree(BinOrdTree<T> const& r);
	void print(const node<T> *p) const;
	void Add(node<T>* &p, T const &x) const;
public:
	BinOrdTree();
	BinOrdTree(BinOrdTree<T> const& r);
	BinOrdTree& operator=(BinOrdTree<T> const& r);
	~BinOrdTree();

	T RootTree() const;
	node<T>* GetRoot() const;
	BinOrdTree<T> LeftTree() const;
	BinOrdTree<T> RightTree() const;

	bool empty()const;
	void printTree() const;
	void AddNode(T const& x);
	void DeleteNode(T const& x);
	void Create3(T x, BinOrdTree<T> left, BinOrdTree<T> right);
	void Create();
	void MinTree(T &x, BinOrdTree<T> &minT) const;
};

template <typename T>
BinOrdTree<T>::BinOrdTree() : root(NULL) {}

template <typename T>
BinOrdTree<T>::BinOrdTree(BinOrdTree<T> const& r)
	{
		Copy(root, r.root);
	}

template <typename T>
BinOrdTree<T>& BinOrdTree<T>::operator=(BinOrdTree<T> const& r)
	{
		if (this != &r)
		{
			DeleteTree();
			Copy(root, r.root);
		}
		return *this;
	}

template <typename T>
BinOrdTree<T>::~BinOrdTree()
	{
		DeleteTree(root);
	}

template <typename T>
void BinOrdTree<T>::DeleteTree(node<T>* &p) const
{
	if (p)
	{
		DeleteTree(p->left);
		DeleteTree(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void BinOrdTree<T>::Copy(node<T>* &pos, node<T>* const&r) const
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
void BinOrdTree<T>::CopyTree(BinOrdTree<T> const& r)
{
	Copy(root, r.root);
}

template <typename T>
void BinOrdTree<T>::print(const node<T> *p) const
{
	if (p)
	{
		print(p->left);
		std::cout << p->inf << " ";
		print(p->right);
	}
}

template <typename T>
void BinOrdTree<T>::Add(node<T>* &p, T const &x) const
{
	if (!p)
	{
		p = new node<T>;
		p->inf = x;
		p->left = NULL;
		p->right = NULL;
	}
	else if (x < p->inf) Add(p->left, x);
	else Add(p->right, x);
}

template <typename T>
T BinOrdTree<T>::RootTree() const
{
	return root->inf;
}

template <typename T>
node<T>* BinOrdTree<T>::GetRoot() const
{
	return root;
}

template <typename T>
BinOrdTree<T> BinOrdTree<T>::LeftTree() const
{
	BinOrdTree<T> tree;
	Copy(tree.root, root->left);
	return tree;
}

template <typename T>
BinOrdTree<T> BinOrdTree<T>::RightTree() const
{
	BinOrdTree<T> tree;
	Copy(tree.root, root->left);
	return tree;
}

template <typename T>
bool BinOrdTree<T>::empty() const
{
	return root == NULL;
}

template <typename T>
void BinOrdTree<T>::printTree() const
{
	print(root);
}

template <typename T>
void BinOrdTree<T>::AddNode(T const& x)
{
	Add(root, x);
}

template <typename T>
void BinOrdTree<T>::DeleteNode(T const& x)
{
	if (root)
	{
		T a = RootTree();
		BinOrdTree<T> tree;
		if (a == x && !root->left) *this = RightTree();
		else if (a == x && !root->right) *this = LeftTree();
		else if (a == x)
		{
			T c;
			RightTree().MinTree(c, tree);
			Create3(c, LeftTree(), tree);
		}
		else if (x < a)
		{
			tree = *this;
			*this = LeftTree();
			DeleteNode(x);
			Create3(a, *this, tree.RightTree());
		}
		else if (x > a)
		{
			tree = *this;
			*this = RightTree();
			DeleteNode(x);
			Create3(a, tree.LeftTree(), *this);
		}
	}
}

template <typename T>
void BinOrdTree<T>::Create3(T x, BinOrdTree<T> left, BinOrdTree<T> right)
{
	root = new node<T>;
	root->inf = x;
	Copy(root->left, left.root);
	Copy(root->right, right.root);
}

template <typename T>
void BinOrdTree<T>::Create()
{
	root = NULL;
	T x;
	char c;

	do
	{
		std::cout << "< ";
		std::cin >> x;
		AddNode(x);
		std::cout << "next element? y/n ";
		std::cin >> c;
	} while (c == 'y');
}

template <typename T>
void BinOrdTree<T>::MinTree(T &x, BinOrdTree<T> &minT) const
{
	T a = RootTree();
	if (!root->left)
	{
		x = a;
		minT = RightTree();
	}
	else
	{
		BinOrdTree<T> tree;
		LeftTree().MinTree(x, tree);
		minT.Create3(a, tree, RightTree());
	}
}
