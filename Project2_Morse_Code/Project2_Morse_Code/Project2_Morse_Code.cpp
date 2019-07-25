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

BST::node* BST::CreateLeaf(char key, string code)
{
	node* n = new node;
	n->key = key;
	n->code = code;

	n->left = NULL;
	n->right = NULL;
	return n;
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

			if (itr->second.length() == string_length)
			{

				AddLeafPrivate(itr->first, itr->second, root);
			}

		}
		string_length++;
	}

}

//THIS FUNCTIONS PROPERLY
string BST::encoder(string input)
{
	string final_encoder;
	string encoded_message;

	for (int i = 0; i < input.length(); i++)
	{
		encoder_result = "";

		encoded_message = encoderPrivate(input.at(i), root);
		final_encoder = final_encoder + " " + encoded_message;
	}

	return final_encoder;
}

//FUNCTIONS PROPERLY EXCEPT THE LOGIC IS WONKY (Maybe utilize find()?)
string BST::encoderPrivate(char target, node* Ptr)
{
	if (Ptr->left != NULL) //If left side is not null
	{
		if (Ptr->key == target)
		{
			encoder_result = (Ptr->code);
			return encoder_result;
		}
		else
		{
			encoderPrivate(target, Ptr->left);
		}
	}

	if(Ptr->right != NULL) //If right side is not null
	{
		if (Ptr->key == target)
		{
			encoder_result = (Ptr->code);
			return encoder_result;
		}
		else 
		{
			encoderPrivate(target, Ptr->right);
		}

	}

	if (Ptr->left == NULL && Ptr->right == NULL) //if left and right are null (accounts for leafs)
	{
		if (Ptr->key == target)
		{
			encoder_result = (Ptr->code);
			return encoder_result;
		}
	}
	return encoder_result;
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
	cout << '\t' << itr->first << '\t' << itr->second << endl;
	}

	cout << endl;

	BST mytree;

	//Populate root of BST with dummy root
	
	//mytree.CreateLeaf('#', "DUMMY_ROOT");
	
	mytree.tree_build(morse_map);




	cout << mytree.encoder("dog") << endl;
	cout << mytree.encoder("queen") << endl;
	cout << mytree.encoder("fire") << endl;
	cout << mytree.encoder("emblem") << endl;
	cout << mytree.encoder("odin") << endl;
	cout << mytree.encoder("leet") << endl;
	cout << mytree.encoder("pragmatic") << endl;
	cout << mytree.encoder("jordan") << endl;

	system("pause");

    return 0;
}

