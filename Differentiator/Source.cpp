#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
	string expression = "2*S(2+x)";
	CExpression exp;
	string post, pre;
	post = exp.toPostFix(expression);
	pre = exp.toPrefix(expression);
	BinaryTreeStrNode * binTree = CBinaryTree::prefixToBinaryTree(pre);
	CBinaryTree* binTreeObj = new CBinaryTree(CBinaryTree::prefixToBinaryTree(pre));

	cout << expression << "\n" << post << "\n Prefix:" << pre;


	cout << "Derivacion de: " << expression << endl;
	cout << binTreeObj->Differentiate();

	return 0;
}