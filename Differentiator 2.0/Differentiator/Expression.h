#pragma once
#include <string>
#include <stack>
//#include "BinaryTree.h"
using namespace std;

class CExpression
{
public:
	
	/*static string constant = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";*/
	string expression;
	static string toPostFix(string exp);
	static string toPrefix(string exp);
	string removeExpression(string exp);
	static int hierarchy(string op);
	static bool isOperator(string op);
	static bool isUnaryOperator(string op);
	static bool isDigit(string op);
	static bool isVariable(string op);
	static string operate(string op, string a, string b);
	
	CExpression();
	~CExpression();

	static bool CheckParenthesis(string expression);



};

