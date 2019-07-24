#include "stdafx.h"

#include <iostream>
#include <cstdlib>

#include "BST.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>



BST::BST()
{
	root = NULL;
}

BST::node* BST::CreateLeaf(pair<char, string>data)
{
	//might need to rework this portion?
	node* n = new node;
	data.first = 'e';
	data.second = "....";

	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::AddLeaf(char key, string code)
{
	AddLeafPrivate(key, code, root);
}

void BST::AddLeafPrivate(char key, string code, node* Ptr)
{
	if (root == NULL) //Maybe remove this?
	{
		root = CreateLeaf(key, code);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL) //left node is not empty, move down to next left node
		{
			AddLeafPrivate(key, code, Ptr->left);
		}
		else //if left node is empty, add node to the tree
		{
			Ptr->left = CreateLeaf(key, code);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL) //right node is not empty, move down to next left node
		{
			AddLeafPrivate(key, code, Ptr->right);
		}
		else //if right node is empty, add node to the tree
		{
			Ptr->right = CreateLeaf(key, code);
		}
	}
	else
	{
		cout << "They key" << key << "has already been added to the tree" << endl;
	}
}