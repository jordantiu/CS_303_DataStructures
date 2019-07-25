#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class BST
{
private:

	struct node
	{
		//data for node
		char key;
		string code;

		//Node pointers
		node* left;
		node* right;
	};

	//root pointer (reference root of tree)
	node* root;

	void AddLeafPrivate(char key, string code, node* Ptr);

	char dot = '.';
	char dash = '-';

public:

	BST(); //constructor

	//build populate nodes with data from created map
	void tree_build(map<char, string>map_var);


	node* CreateLeaf(char key, string code);

	void AddLeaf(char key, string code);


};

#endif