// Project2_Morse_Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>

#include "BST.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// verify morse_code map is correct: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ (REFERENCE to print MAP KEY)


//BST::BST()
//{
//	root = NULL; //TODO:need a dummy value for the initial root
//}

BST::node* BST::CreateLeaf(char key, string code)
{
	//might need to rework this portion?

	node* n = new node;
	n->key = key;
	n->code = code;

	n->left = NULL;
	n->right = NULL;
	return n;
}

//idk if i will need this since the tree auto populates
void BST::AddLeaf(char key, string code)
{
	AddLeafPrivate(key, code, root);
}

void BST::AddLeafPrivate(char key, string code, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf('$', "Dummy_Node");
	}

	if (code.at(index) == dot) //DOT PATHWAY (LEFT)

	{
		if (Ptr->left == NULL) //left node IS empty, CreateLeaf
		{
			index = 0; //reset index to 0
			Ptr->left = CreateLeaf(key, code);
		}
		else
		{
			index++; //increment index by one
			AddLeafPrivate(key, code, Ptr->left); //recursive call
		}
	}

	else if (code.at(index) == dash) //DASH PATHWAY (RIGHT)
	{
		if (Ptr->right == NULL) //right node IS empty, CreateLeaf
		{
			index = 0; //reset index to 0
			Ptr->right = CreateLeaf(key, code);

		}
		else //if right node is empty, add node to the tree
		{
			index++; //increment index by one
			AddLeafPrivate(key, code, Ptr->right); //recursive call
		}
	}
	else
	{
		cout << "Morse Code BST building is complete." << endl;
	}
}

//TEH TEMPLATE FELT CUTE MIGHT DELETE LATER
//void BST::AddLeafPrivate(char key, string code, node* Ptr)
//{
//	if (root == NULL)
//	{
//		root = CreateLeaf(key, code);
//	}
//	else if (key < Ptr->key)
//	{
//		if (Ptr->left != NULL) //left node is not empty, move down to next left node
//		{
//			AddLeafPrivate(key, code, Ptr->left);
//		}
//		else //if left node is empty, add node to the tree
//		{
//			Ptr->left = CreateLeaf(key, code);
//		}
//	}
//	else if (key > Ptr->key)
//	{
//		if (Ptr->right != NULL) //right node is not empty, move down to next left node
//		{
//			AddLeafPrivate(key, code, Ptr->right);
//		}
//		else //if right node is empty, add node to the tree
//		{
//			Ptr->right = CreateLeaf(key, code);
//		}
//	}
//	else
//	{
//		cout << "They key" << key << "has already been added to the tree" << endl;
//	}
//}


void BST::tree_build(map<char, string>map_var)
{
	map<char, string>::iterator itr;

	//Minimum length of morse code will be one character
	int string_length = 1;

	AddLeafPrivate('#', "TESTDUMMY", root);

	while (string_length <= 4)
	{
		//Iterate through the map
		for (itr = map_var.begin(); itr != map_var.end(); ++itr)
		{
			//iterate through the map, starting with itr->second; if the lengths are the same then call the node 
			//building function that will tokenize through (and find the correct node locations
			//note that the base root will be NULL/empty (dummy value?)

			if (itr->second.length() == string_length)
			{
				////CALL THE NODE BUILDING FUNCTION Pass through itr->second AND itr->first as arguments
				//cout << itr->first << endl;
				//cout << itr->second << endl;

				AddLeafPrivate(itr->first, itr->second, root);
			}

			//cout << '\t' << itr->first
			//	<< '\t' << itr->second << '\n';
		}
		string_length++;
	}

	//compare the codes of they key, have an integer limit
	//that will start building the tree from height one, then height two, then height 3 and so on and so forth
	//whne you build the leaf you update the key and code for each node
}






int main()
{
	/****************morse code map****************/
	map<char, string>morse_map;
	string line2;

	ifstream myfile2("morse.txt"); //open text file
								   //Create morse_map
	if (myfile2.is_open())
	{

		while (getline(myfile2, line2))
		{
			char key = line2.at(0);
			string code = line2.substr(1, line2.length());

			morse_map.insert(pair<char, string>(key, code));
		}

		myfile2.close(); //close text file

	}

	// verify morse_code map is correct: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ (REFERENCE to print MAP KEY)
	map<char, string>::iterator itr;
	cout << "\nThe morse code map is : \n";
	cout << "\tKEY\tELEMENT\n";

	//Keep for reference (allowed us to iterate through the map and print values)
	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) 
	{
	cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}


	BST mytree;

	//Populate root of BST with dummy root
	
	//mytree.CreateLeaf('#', "DUMMY_ROOT");
	
	mytree.tree_build(morse_map);


	string tester = "LEST";

	//get character at end of string
	cout << tester.at(tester.length() - 1) << endl;


	system("pause");

    return 0;
}

