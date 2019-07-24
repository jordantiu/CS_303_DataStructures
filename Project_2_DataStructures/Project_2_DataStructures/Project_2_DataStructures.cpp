// Project_2_DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Binary_Search_Tree.h"
#include "map.h"

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <map>

using namespace std;

int main()
{

	/****************morse code map****************/

	map<char, string>morse_map;
	string line2;

	ifstream myfile2("morse.txt"); //open file

								   //Create morse_map
	if (myfile2.is_open())
	{

		while (getline(myfile2, line2))
		{
			char key = line2.at(0);
			string code = line2.substr(1, line2.length());

			morse_map.insert(pair<char, string>(key, code));
		}

		myfile2.close();
	}

	cout << morse_map.size() << endl;

	// verify morse_code map is correct: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ (REFERENCE to print MAP KEY)
	map<char, string>::iterator itr;
	cout << "\nThe morse code map is : \n";
	cout << "\tKEY\tELEMENT\n";

	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;



	//https://www.geeksforgeeks.org/map-key_comp-function-in-c-stl/

	string test = "....";

	////Tests if test string is equal to code, if it is then output the key (i might not need this?)
	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
		if (test == itr->second)
			cout << itr->first << endl;
	}

	string line;

	vector<string> BinarySearchData;

	BinarySearchData.push_back("#"); //use to set dummy value for root when converting to binary search tree

	int i = 0;

	ifstream myfile("morse_mod.txt"); //open file

	if (myfile.is_open()) 
	{
		//Push data from modified morse code file into a vector
		while (getline(myfile, line))
		{
			BinarySearchData.push_back(line);
		}

		myfile.close();
	}

	//Test of BinarySearchData vector (Delete later)
	//for(int j = 0; j < BinarySearchData.size(); j++)
	//{
	//	cout << BinarySearchData[j] << endl;
	//}

	Binary_Search_Tree<string> binary_tree;
	binary_tree.read_tree(BinarySearchData);

	string target = "fad";

	cout << target.size();

	//if statement that states that if I dont find the target
	
	for (int i = 0; i < target.size(); i++)
	{
		string& temp = target.at[i];
		binary_tree.find(temp);
	}

	//binary_tree.find(target)

	//{
	//	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
	//		if (test == itr->second)
	//			cout << itr->first << endl;
	//	}
	//}
	//
	









	////TODO: Encoder Function
	//encoder("eish"); // ==> Output .... ... .. . 
	string encoder_test = "ace";





	////TODO: Decoder Function
	//decoder(".... ... .. ."); // ==> Output eish
	string decoder_test = ".... ... .. ."; //Output is eish
	
	//TODO: Documentation





	system("pause");

    return 0;
}

