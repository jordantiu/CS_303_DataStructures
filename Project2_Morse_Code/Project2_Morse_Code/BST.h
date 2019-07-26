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

	const char dot = '.';
	const char dash = '_';
	const char space = ' ';
	
	int index = 0;
	string encoderPrivate(char target, node* Ptr);
	string encoder_result_Private;

	
	int decoder_index = 0;
	char decoderPrivate(string target, node*Ptr);
	char decoder_result_Private;
	

public:

	//build populate nodes with data from created map
	void tree_build(map<char, string>map_var);
	node* CreateLeaf(char key, string code);

	string encoder(string input);
	string decoder(string input);

};

#endif