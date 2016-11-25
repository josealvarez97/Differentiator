#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
using namespace std;

int main()
{

	//string expression = "2*x^4+2*x^5";
	//string expression = "2*x^4";
	//string expression = "1/x^2";
	string expression = "C(4*x^5)/x^3";

	

	CBinaryTree* tree;

	cout << "INGRESE INFIX A DERIVAR:  ";
	//cin >> expression;
	cout << "Expression " << expression;
	tree = new CBinaryTree(CBinaryTree::prefixToBinaryTree(CExpression::toPrefix(expression)));
	cout << endl;

	cout << "PREFIX: " << CExpression::toPrefix(expression) << endl << endl;
	cout << "DERIVADA INDICADA: " << tree->IndicatedDifferentiation() << endl;
	cout << "DERIVADA: " << tree->Differentiate() << endl;

	do
	{


	} while (true);




	CExpression::toPrefix(expression);


	//CExpression exp;
	string post, pre;
	post = CExpression::toPostFix(expression);
	pre = CExpression::toPrefix(expression);
	BinaryTreeStrNode * binTree = CBinaryTree::prefixToBinaryTree(pre);
	CBinaryTree* binTreeObj = new CBinaryTree(CBinaryTree::prefixToBinaryTree(pre));

	cout << expression << "\n" << post << "\n Prefix:" << pre;


	cout << "Derivacion de: " << expression << endl;
	cout << binTreeObj->Differentiate();

	return 0;
}