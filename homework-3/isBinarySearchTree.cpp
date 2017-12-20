#include <iostream>
#include "BinTree.h"

bool checkBST_helper(node<int> *root, int min, int max)
{
	if (!root) return true;
	if (root->inf < min || root->inf > max) return false;
	return (checkBST_helper(root->left, min, root->inf - 1) && checkBST_helper(root->right, root->inf + 1, max));
}


bool checkBST(node<int> *root)
{
	int min = 0;
	int max = 10000;
	return checkBST_helper(root, min, max);
}

int main()
{
	BinTree<int> tree;
	tree.Create();
	tree.printTree();
	if (checkBST(tree.GetRoot())) std::cout << "YES\n";
	else std::cout << "NO\n";

	return 0;
}
