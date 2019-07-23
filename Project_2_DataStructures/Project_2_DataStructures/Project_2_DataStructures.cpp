// Project_2_DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Binary_Search_Tree.h"

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <map>

using namespace std;


int main()
{

	//string line;

	//vector<string> BinarySearchData;

	//BinarySearchData.push_back("#"); //use to set dummy value for root when converting to binary search tree

	//int i = 0;

	//ifstream myfile("morse_mod.txt"); //open file

	//if (myfile.is_open()) 
	//{
	//	//Push data from modified morse code file into a vector
	//	while (getline(myfile, line))
	//	{
	//		BinarySearchData.push_back(line);
	//	}

	//	myfile.close();
	//}

	////for(int j = 0; j < BinarySearchData.size(); j++)
	////{
	////	cout << BinarySearchData[j] << endl;
	////}

	//Binary_Search_Tree<string> binary_tree;
	//binary_tree.read_tree(BinarySearchData);
	//const std::string* maxNode = binary_tree.max();
	//const std::string* minNode = binary_tree.min();

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
			string code = line2.substr(1,line2.length());

			morse_map.insert(pair<char, string>(key, code));
		}

		myfile2.close();
	}

	cout << morse_map.size() << endl;
	
	// printing morse_code map for reverence : https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ (REFERENCE to print MAP KEY)
	map<char, string>::iterator itr;
	cout << "\nThe morse code map is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;



	system("pause");

    return 0;
}

