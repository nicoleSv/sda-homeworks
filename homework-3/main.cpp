#include <iostream>
#include "BinOrdTree.h"

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

int main()
{
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

	BinOrdTree<int> tree;
	tree.Create();
	tree.printTree();
	std::cout << std::endl << tree.height(tree.GetRoot()) << std::endl;
	levelOrder(tree.GetRoot());

	return 0;
}