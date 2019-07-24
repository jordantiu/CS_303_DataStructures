#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "stdafx.h"

#include "Binary_Search_Tree.h"
#include "map.h"

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <map>

using namespace std;

class evaluate
{
public:

	string encode(string test);
	string decode(string test);

	map<char, string>morse_map;
	string line2;

	map<char, string>::iterator itr;



};


#endif