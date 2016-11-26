#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
using namespace std;

int main()
{

	//string expression = "2*x^4+2*x^5";
	//string expression = "2*x^4";
	//string expression = "1/x^2";
	//string expression = "C(4*x^5)/x^3";
	string* expressionArrayTest = new string[5]
	{ "C(((((4*x^5)))))/x^3", "2*x^4+2*x^5" , "2*x^4", "1/x^2", "C((4*x^5))/x^3" /*"4*x^5+5*x=5+4*y^3+y*4"*/ };


	for (int i = 0; i < 5; i++)
	{
		//cout << "INGRESE INFIX A DERIVAR:  ";
		//cin >> expression;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "EXPRESION: " << expressionArrayTest[i] << endl;
		CBinaryTree* tree = new CBinaryTree(CBinaryTree::prefixToBinaryTreeNode(CExpression::toPrefix(expressionArrayTest[i])));
		cout << "PREFIX: " << CExpression::toPrefix(expressionArrayTest[i]) << endl << endl;
		cout << "DERIVADA INDICADA: " << tree->IndicatedDifferentiation() << endl;
		cout << "DERIVADA DETALLADA: " << tree->Differentiate() << endl;
		cout << "DERIVADA LIMPIA: " << tree->CleanDifferentiation() << endl << endl;

		/*cout << "------------------------------------------------------------------------------------" << endl;*/



		delete tree;
	}
	

	//do
	//{


	//} while (true);




	//CExpression::toPrefix(expression);


	//CExpression exp;
	//string post, pre;
	//post = CExpression::toPostFix(expression);
	//pre = CExpression::toPrefix(expression);
	//BinaryTreeStrNode * binTree = CBinaryTree::prefixToBinaryTree(pre);
	//CBinaryTree* binTreeObj = new CBinaryTree(CBinaryTree::prefixToBinaryTree(pre));

	//cout << expression << "\n" << post << "\n Prefix:" << pre;


	//cout << "Derivacion de: " << expression << endl;
	//cout << binTreeObj->Differentiate();

	return 0;
}