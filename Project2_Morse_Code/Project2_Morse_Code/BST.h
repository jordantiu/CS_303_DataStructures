#pragma once

#include <string>

using namespace std;

class BST
{
private:
	struct node
	{
		char key;
		string code;
		node* left;
		node* right;
	};

	node* root;

	void AddLeafPrivate(char key, string code, node* Ptr);



public:
	BST();
	node* CreateLeaf(char key, string code);
	void AddLeaf(char key, string code);
};