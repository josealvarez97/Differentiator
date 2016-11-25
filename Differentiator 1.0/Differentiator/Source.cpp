#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
	CBinaryTree* tree = new CBinaryTree();
	string expression = "2*C(2*x)";
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