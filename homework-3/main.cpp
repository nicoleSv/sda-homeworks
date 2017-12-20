#include <iostream>
#include "BinTree.h"

template <typename T>
void levelOrder(node<T>* root)
{
	if (!root) return;
	else
	{
		std::cout << root->inf << " ";
		if (root->left && root->right)
		{
			std::cout << root->left->inf << " " << root->right->inf << " ";
			levelOrder(root->left->left);
			levelOrder(root->left->right);
		}
		else if(root->left) levelOrder(root->left);
		else if(root->right) levelOrder(root->right);
	}
}

template <typename T>
node<T>* lca(node<T>* root, T v1, T v2)
{
	if (root->inf < v1 && root->inf < v2) root = lca(root->right, v1, v2);
	if (root->inf > v1 && root->inf > v2) root = lca(root->left, v1, v2);
	return root;
}


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
	/*
	BinTree<int> tree;
	tree.Create();
	tree.printTree();
	
	ChainBinTree tree;
	tree.CreateTree();
	tree.print();
	
	ParentBinTree tree;
	tree.CreateTree(2);
	tree.print();
	*/

	/*
	BinOrdTree<int> tree;
	tree.Create();
	tree.printTree();
	std::cout << std::endl << tree.height(tree.GetRoot()) << std::endl;
	levelOrder(tree.GetRoot());

	node<int>* p = lca(tree.GetRoot(), 4, 6);
	std::cout << p->inf << std::endl;
	*/

	return 0;
}