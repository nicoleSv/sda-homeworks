#include <iostream>
#include "BinOrdTree.h"

template <typename T>
node<T>* lca(node<T>* root, T v1, T v2)
{
	if (root->inf < v1 && root->inf < v2) root = lca(root->right, v1, v2);
	if (root->inf > v1 && root->inf > v2) root = lca(root->left, v1, v2);
	return root;
}

int main()
{
	BinOrdTree<int> tree;
	tree.Create();
	tree.printTree();

	node<int>* p = lca(tree.GetRoot(), 4, 6);
	std::cout << p->inf << std::endl;

	return 0;
}
