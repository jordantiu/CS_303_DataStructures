// Project2_Morse_Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BST.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


void code_compare(int limit)
{
	


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

	for (itr = morse_map.begin(); itr != morse_map.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	BST myTree;

	system("pause");

    return 0;
}

