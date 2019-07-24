// Project2_Morse_Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include "BST.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;



void tree_build(map<char, string>map_var)
{
	map<char, string>::iterator itr;

	//Minimum length of morse code will be one character
	int string_length = 1;

	while (string_length != 5)
	{
		//Iterate through the map
		for (itr = map_var.begin(); itr != map_var.end(); ++itr) 
		{
			//iterate through the map, starting with itr->second; if the lengths are the same then call the node 
			//building function that will tokenize through (and find the correct node locations
			//note that the base root will be NULL/empty (dummy value?)
			
			if (itr->second.length() == string_length)
			{
				//CALL THE NODE BUILDING FUNCTION Pass through itr->second AND itr->first as arguments
				cout << itr->first << endl;
				cout << itr->second << endl;
				//leafcreate(string_length, itr->first, itr->second);
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

void leafcreate(int length, char key, string code)
{
	//PUT KEY AND CODE INTO A PAIR?
}



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

	//Keep for reference (allowed us to iterate through the map and print values)
	/*for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;*/

	//BST myTree;

	//Add these void functions into a class when functionality is verified
	void treebuild();
	void leafcreate();

	tree_build(morse_map); //build binary search tree from map

	system("pause");

    return 0;
}

