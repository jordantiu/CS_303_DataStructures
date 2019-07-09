// Project_1_Infix.cpp : Defines the entry point for the console application.
//

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

// Function to find precedence of operators. 
int Infix_Evaluator::precedence(char op) {
	
	if (op == 'f') // || comparison
		return 1;
	if (op == 'e') // && comparison
		return 2;
	if (op == 'a') // == comparison
		return 3;
	if (op == '>' || op == '<' || op == 'b' || op == 'c') // (b & c for >= and <= cases)
		return 4;
	if (op == '+' || op == '-')
		return 5;
	if (op == '*' || op == '/' || op == '%')
		return 6;
	if (op == '^')
		return 7;
	if (op == 'g' || op == 'h' || op=='!') // g ==> ++ ; h ==> --
		return 8;
	return 0;
}

// Function to perform arithmetic operations. 
int Infix_Evaluator::applyOp(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a,b);
	case '%': return a % b;
	
	case 'a': // ==
		if (a == b) 
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case 'b': //!=
		if (a != b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case 'c': // >=
		if (a >= b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case 'd': // <=
		if (a <= b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	case 'e': // &&
		if (a && b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case 'f': // ||
		if (a || b )
		{
			return 1;
		}
		else
		{
			return 0;
		}


	case '>': // >
		if (a > b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case '<': // <
		if (a < b)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	case 'g': return ++a; // ++

	case 'h': return --b; // --

	case '!':  // !
		if (a == 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
 }

int Infix_Evaluator::evaluate(string tokens) {
	
	// Print string being evaluated
	cout << tokens << " ==> ";

	for (i = 0; i < tokens.length(); i++) {

		// CHECKING INVALID EXPRESSIONS //

		//Division by zero syntax error
		if (!ops.empty() && ops.top() == '/' && tokens[i] == '0')
		{
			throw Syntax_Error("Can not divide by 0");
		}

		// Syntax error when starting the expression with a binary operator (cases a, b, c, f, e)
		else if (!ops.empty() && numbers.empty() && (ops.top() == 'a' || ops.top() == 'b' || ops.top() == 'c' || ops.top() == 'd' || ops.top() == 'e' || ops.top() == 'f'
			|| ops.top() == '>' || ops.top() == '<'))
		{
			throw Syntax_Error("Expression can't start with a binary operator");
		}

		// Syntax error when expression starts with closing parenthesis
		else if (tokens[0] == ')')
		{
			throw Syntax_Error("Expression can't start with a closing parenthesis.");
		}

		// Syntax error when using two binary oeprators in a row
		else if (!ops.empty() && ((ops.top() == 'a' || ops.top() == 'b' || ops.top() == 'c' || ops.top() == 'd' || ops.top() == 'e' || ops.top() == 'f')) &&
			(tokens[i] == '|' || tokens[i] == '&' || tokens[i] == '=' || tokens[i] == '!' || tokens[i] == '>' || tokens[i] == '<') &&
			(tokens[i + 1] == '|' || tokens[i + 1] == '&' || tokens[i + 1] == '=' || tokens[i + 1] == '!' || tokens[i + 1] == '>' || tokens[i + 1] == '<')) //Checks the next token if any of these conditions occur
		{
			throw Syntax_Error("Expression can't have two binary operators in a row.");
		}

		
		// Parse through string conditions
		if (tokens[i] == '(') 
		{
			ops.push(tokens[i]);
		}

		else if (!ops.empty() && ops.top() == '=' && tokens[i] == '=') //checks if top of ops stack and current token is '=='
		{
			ops.pop();
			ops.push('a'); // push switch condition 'a' to ops stack
		}

		else if (!ops.empty() && ops.top() == '!' && tokens[i] == '=') //checks if top of ops stack and current token is '!='
		{
			ops.pop();
			ops.push('b'); // push switch condition 'b' to ops stack
		}

		else if (!ops.empty() && ops.top() == '>' && tokens[i] == '=') //checks if top of ops stack and current token is '>='
		{
			ops.pop();
			ops.push('c'); // push switch condition 'c' to ops stack
		}

		else if (!ops.empty() && ops.top() == '<' && tokens[i] == '=') //checks if top of ops stack and current token is '<='
		{
			ops.pop();
			ops.push('d'); // push switch condition 'd' to ops stack
		}

		else if (!ops.empty() && ops.top() == '&' && tokens[i] == '&') //checks if top of ops stack and current token is '&&'
		{
			ops.pop();
			ops.push('e'); // push switch condition 'e' to ops stack
		}

		else if (!ops.empty() && ops.top() == '|' && tokens[i] == '|') //checks if top of ops stack and current token is '||'
		{
			ops.pop();
			ops.push('f'); // push switch condition 'f' to ops stack
		}

		else if (!ops.empty() && ops.top() == '+' && tokens[i] == '+')
		{
			ops.pop();
			ops.push('g'); // push switch condition 'g' to ops stack
		}
		
		else if (!ops.empty() && ops.top() == '-' && tokens[i] == '-')
		{
			ops.pop();
			ops.push('h'); // push switch condition 'h' to ops stack
		}

		else if (!ops.empty() && ops.top() == '!' && tokens[i] == '!') //Negate double !
		{
			ops.pop();
		}

		//Statement will add currenet token to temporary_string
		else if (isdigit(tokens[i]) && temporary_string.empty() == true) 
		{	
			//Temporary string value for token[i]
			temporary_string = tokens[i];
			
		}
		//if the current token is a digit AND temporary_string is NOT empty, merge strings together
		else if (isdigit(tokens[i]) && temporary_string.empty() == false)
		{
			temporary_string_addon = tokens[i];
			temporary_string = temporary_string + temporary_string_addon;
			temporary_string_addon = ""; //empty temp addon string
		}

		// if temporary_string is not empty and the current token is not a digit (PUSH OPERATOR ONTO STACK)
		else if (temporary_string.empty() == false && !isdigit(tokens[i]) && tokens[i] != ')')
		{
			//Use stoi to convert string into an integer
			string_conversion = stoi(temporary_string);

			//Push number to top of the stack
			numbers.push(string_conversion);

			temporary_string = "";

			//If ops stack is NOT empty and the precedence of top of ops stack is greater than or equal to the precedence of the token
			if (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
			{
				int value2 = numbers.top();
				numbers.pop();

				int value1 = numbers.top();
				numbers.pop();

				char op = ops.top();
				ops.pop();

				//Evaluate and push number to top of numbers stack
				numbers.push(applyOp(value1, value2, op));
				
				ops.push(tokens[i]);
			}
			else
			{
				ops.push(tokens[i]);
			}

			
		}

		//Closing brace encountered, solve entire brace:
		else if (tokens[i] == ')')
		{
			
			//Use stoi to convert string into an integer
			string_conversion = stoi(temporary_string);

			//Push number to top of the stack
			numbers.push(string_conversion);

			temporary_string = "";

			// Evaulate arithmetic expression within parenthesis
			while (!ops.empty() && ops.top() != '(')
			{
				int value2 = numbers.top();
				numbers.pop();

				int value1 = numbers.top();
				numbers.pop();
				char op = ops.top();
				ops.pop();

				numbers.push(applyOp(value1, value2, op));
			}
			
			//pops opening brace
			ops.pop();
		}

		//Current token in an operator
		else
		{
			//If ops stack is NOT empty and the precedence of top of ops stack is greater than or equal to the precedence of the token
			if (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
			{
				int value2 = numbers.top();
				numbers.pop();

				int value1 = numbers.top();
				numbers.pop();

				char op = ops.top();
				ops.pop();

				numbers.push(applyOp(value1, value2, op));
			}
			else
			{
				ops.push(tokens[i]);
			}
		}

		//THIS IF STATEMENT WILL CHECK CONDITIONS FOR THE LAST PART OF THE STRING
		//push number to stack if it is the last number in the string
		if (i == tokens.length() - 1 && isdigit(tokens[i]))
		{
			
			temporary_string = tokens[i];
			
			//Use stoi to convert string into an integer
			string_conversion = stoi(temporary_string);

			//Push number to top of the stack
			numbers.push(string_conversion);

			temporary_string = "";
		}

	}

	
	//Evaluate stacks while ops stack is not empty
	while (!ops.empty())
	{
		if (numbers.size() == 1)
		{
			numbers.push(0); // push 0 if only one number is in stack to prevent compiling error
		}

		int value2 = numbers.top();
		numbers.pop();

		int value1 = numbers.top();
		numbers.pop();

		char op = ops.top();
		ops.pop();

		numbers.push(applyOp(value1, value2, op));
	}

	//Return result
	return numbers.top();
}

// Main function used for testing various conditions
int main()
{
	Infix_Evaluator eval;

	cout << eval.evaluate("1+2*3") << endl; // Result 7

	cout << eval.evaluate("2+2^2*3") << endl; // Result 14

	cout << eval.evaluate("1==2") << endl; // Return 0 (False)

	cout << eval.evaluate("1+3>2") << endl; // Return 1 (True)
	
	cout << eval.evaluate("(4>=4)&&0") << endl; // Return 0 (False)
	
	cout << eval.evaluate("(1+2)*3") << endl; // Result 9

	cout << eval.evaluate("33+4") << endl; //Result 37

	cout << eval.evaluate("1||0") << endl; // Return 1 (True)

	cout << eval.evaluate("6>5&&4>5") << endl; // Return 0 (False)

	cout << eval.evaluate("!!!!3>2") << endl; // Return 1 (True)

	cout << eval.evaluate("6!=5") << endl; // Return 1 (True)

	cout << eval.evaluate("6>5") << endl; // Return 1 (True)

	cout << eval.evaluate("!1") << endl; //Return 0

	//// INVALID EXPRESSION Examples
	//cout << eval.evaluate("10<++++3") << endl;

	//cout << eval.evaluate("10+<3") << endl;

	//cout << eval.evaluate("9/0") << endl;

	//cout << eval.evaluate(">=4+4") << endl;

	system("pause");

	return 0;
}