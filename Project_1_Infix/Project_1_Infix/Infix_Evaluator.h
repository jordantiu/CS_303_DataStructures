#ifndef INFIX_EVALUATOR_H_
#define INFIX_EVALUATOR_H_

#include "stdafx.h"
#include "Syntax_Error.h"
#include "Infix_Evaluator.h"

#include <iostream>
#include <string>
#include <stack>

#include <cmath>

#include <sstream>
#include <cctype>

#include <sstream>

using namespace std;

class Infix_Evaluator
{

public:
	
	int i;

	int evaluate(string tokens);
	int precedence(char op);
	int applyOp(int a, int b, char op);
	
	// Stack that will contain int values
	stack<int> numbers;

	// Stack that will contain various operators
	stack<char> ops;

	// Variables used when converting token to integers before pushing to numbers stack
	int temporary_number;
	int string_conversion;

	// Strings for dealing with multiple digits in a row
	string temporary_string;
	string temporary_string_addon;
};




#endif