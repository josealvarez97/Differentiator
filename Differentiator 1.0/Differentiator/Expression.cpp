#include "Expression.h"



CExpression::CExpression()
{
}


CExpression::~CExpression()
{
}

string CExpression::toPostFix(string exp)
{
	string postfix = ""; // just the variable we'll return later
	stack<string> operators; // the stack of operators. Important part of the algorithm
	string currentNumber = ""; // just the variable for reading the string...

	for (int i = 0; i < exp.length(); i++) // just the for for reading the string...
	{
		string currentItem = exp.substr(i, 1); // this is what actually reading a string looks like...

		if (isDigit(currentItem))
		{
			postfix += currentItem; // DIGIT => JUST ADD IT TO THE STRING
			continue; // iterate again on this scope...
		}

		if (isOperator(currentItem))
		{
			// THIS IS WHERE THE GOOD THING HAPPENS
			while ((!operators.empty())
				&& (hierarchy(operators.top()) >= hierarchy(currentItem))) // while the stack is not empty... AND CURRENT OPERATOR HAS LESS HIERARCHY THAN THE TOP OF THE OPERATORS STACK
			{
				// IN TO POST FIX WE ALWAYS WANT OPERATORS OF GREATER HIERARCHY ON THE TOP.

				// SO WE EMPTY THE OPERATORS STACK
				postfix += operators.top(); // JUST ADD EACH OPERATOR TO THE POST FIX STRING
				operators.pop();
			}
			operators.push(currentItem);

		}

	}

	// WE HAVE FINISH READING THE STRING

	// SO WE EMPTY THE OPERATORS STACK
	while (!operators.empty())
	{
		postfix += operators.top(); // just add each operator to the string
		operators.pop();
	}


	return postfix; //THE JOB IS DONE
}

string CExpression::toPrefix(string exp)
{
	//Start with an empty string
	string prefix = "";
	//A stack to order operators until they can be written on the top prefix expression
	stack<string> operators;
	string currentItem;
	//Traverse the infix expression from LAST element to FIRST
	for (int i = exp.length(); i > 0; i--)
	{
		//Get previous element on string
		currentItem = exp.substr(i - 1, 1);

		//If the element is a number, constant or variable
		// prepend it to the final prefix expression
		if (isDigit(currentItem) || isVariable(currentItem))
		{
			prefix = currentItem + prefix;
			continue;
		}
		//If the current element is an operator we need to check
		// for hierarchies and grouping orders
		if (isOperator(currentItem))
		{
			//If the stack is not empty, we have to pop out from the stack any elements
			// that have greater or equal hierarchy than the current item
			while(!operators.empty() 
				&& hierarchy(operators.top()) > hierarchy(currentItem)
				&& operators.top() != ")"
				&& currentItem != "(") // EXCEPT WHEN THE TOP ELEMENT IN THE STACK IS A CLOSING PARENTHESIS
			{
				prefix = operators.top() + prefix;
				operators.pop();
			}


			//iF THE CURRENT ITEM IS AN OPENING PARENTHESIS WE POP OUT EVERYTHING UNTIL WE FIND A CLOSING PARENTHESIS
			if (currentItem == "(")
			{
				while (operators.top() != ")")
				{
					prefix = operators.top() + prefix;
					operators.pop();
				}
				// WE TAKE OUT THE CLOSING PARENTHESIS (needed because the while doesn't take it out
				//pops it out
				operators.pop();
				continue;
			}
			//Push the operator if none of the other two conditions were met
			operators.push(currentItem); // INCLUDES CLOSING PARENTHESIS
		}
	}

	// We finished reading the string
	// Clear any remaining elements on stack
	while (!operators.empty())
	{
		prefix = operators.top() + prefix;
		operators.pop();
	}


	return prefix; // The job is done
}



string CExpression::removeExpression(string exp)
{
	return string();
}

int CExpression::hierarchy(string op)
{
	if (op == ")")
		return INTMAX_MAX;
	if (op == "(")
		return INT_MIN;
	if (op == "+" || op == "-")
		return 1;
	if (op == "*" || op == "/")
		return 2;
	if (op == "^" /*|| op == "^"*/)
		return 3;
	if (op == "sin" || op == "cos" || op == "tan")
		return 10;
	if (op == "~")
		return 10;
}

bool CExpression::isOperator(string op)
{
	string operators = "~+-*/^()";
	return operators.find(op) != string::npos;
	// find returns -1 if it doesn't find the operator. npos is -1 by default
	/*
	good example: http://www.cplusplus.com/forum/beginner/37817/
	static const size_t npos = -1;

Maximum value for size_t
npos is a static member constant value with the greatest possible value for an element of type size_t.

This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".

As a return value, it is usually used to indicate no matches.

This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.*/
}

bool CExpression::isUnaryOperator(string op)
{
	string operators = "~CST";

	return operators.find(op) != string::npos;
}

bool CExpression::isDigit(string op)
{
	const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return digits.find(op) != string::npos;
}

bool CExpression::isVariable(string op)
{
	const string variables = "x";
	return variables.find(op) != string::npos;
}




string CExpression::operate(string op, string aExp, string bExp)
{
	float a, b, c;
	a = std::stof(aExp);
	if (bExp != "")
	{
		b = std::stof(bExp);

		if (op == "+")
		{
			c = a + b;
		}
		if (op == "-")
		{
			c = a - b;
		}
		if (op == "*")
		{
			c = a * b;
		}
		if (op == "/")
		{
			c = a / b;
		}

		if (op == "^")
		{
			c = pow(a, b);
		}
	}

	if (op == "~")
	{
		c = -a;
	}



	return to_string(c);
}
