#include "BinaryTree.h"

static int index = 0;


CBinaryTree::CBinaryTree()
{
	expreessionObj = new CExpression();
}

CBinaryTree::CBinaryTree(BinaryTreeStrNode * aRoot)
{
	this->strRoot = aRoot;
	expreessionObj = new CExpression();
}


CBinaryTree::~CBinaryTree()
{
}

BinaryTreeStrNode * CBinaryTree::GetNodePtr(string value)
{
	return this->GetNodePtr(this->strRoot, value);
}

void CBinaryTree::Insert(string value)
{
	if (this->strRoot != nullptr)
		Insert(this->strRoot, value);
	else
	{
		this->strRoot = new BinaryTreeStrNode();
		this->strRoot->value = value;
	}
}

void CBinaryTree::Insert(int value)
{
	if (this->intRoot != nullptr)
		this->Insert(this->intRoot, value);
	else
	{
		this->intRoot = new BinaryTreeIntNode();
		this->intRoot->value = value;
	}
}

string CBinaryTree::printTree(treeType type, BinaryTreeStrNode * node)
{
	string expressionToPrint = "";
	if (expreessionObj->isOperator(node->value))
		expressionToPrint = printTree(STRING_TREE, node->left) + node->value + printTree(STRING_TREE, node->right);
	else if (expreessionObj->isUnaryOperator(node->value))
		expressionToPrint = node->value + "[" + printTree(STRING_TREE, node->left)+"]";
	else if (expreessionObj->isDigit(node->value)) //Aqui digits tambien tiene C S Y T tomar en cuenta aunque no entra porque antes esta la otra validacion
		expressionToPrint = node->value;
	else
		expressionToPrint = node->value;


	return expressionToPrint;
}

BinaryTreeStrNode * CBinaryTree::GetNodePtr(BinaryTreeStrNode * node, string value)
{
	if (node == nullptr)
		return nullptr;

	if (value < node->value)
		return this->GetNodePtr(node->left, value);
	else if (value > node->value)
		return this->GetNodePtr(node->right, value);
	else if (value == node->value)
		return node;
	else
		return nullptr;
}

void CBinaryTree::Insert(BinaryTreeStrNode * node, string value)
{
	if (value <= node->value)
		if (node->left != nullptr)
			this->Insert(node->left, value);
		else
		{
			node->left = new BinaryTreeStrNode();
			node->left->value = value;
		}
	else
		if (node->right != nullptr)
			this->Insert(node->right, value);
		else
		{
			node->right = new BinaryTreeStrNode();
			node->right->value = value;
		}

}

void CBinaryTree::Insert(BinaryTreeIntNode * node, int value)
{
	if (value <= node->value)
		if (node->left != nullptr)
			this->Insert(node->left, value);
		else
		{
			node->left = new BinaryTreeIntNode();
			node->value = value;
		}
	else
		if (node->right != nullptr)
			this->Insert(node->right, value);
		else
		{
			node->right = new BinaryTreeIntNode();
			node->value = value;
		}
}

string CBinaryTree::Differentiate()
{
	if (this->strRoot != nullptr)
	{
		return Differentiate(this->strRoot);
	}
	else
		return "Arbol vacio";
}

string CBinaryTree::Differentiate(BinaryTreeStrNode * node)
{
	if (node->value == "+")
		return Differentiate(node->left) + "+" + Differentiate(node->right);
	else if (node->value == "-")
		return Differentiate(node->left) + "-" + Differentiate(node->right);
	else if (node->value == "*")
		return "(" + Differentiate(node->left) + " )(" + this->printTree(STRING_TREE, node->right) + ") + (" + this->printTree(STRING_TREE, node->left) + ")(" + Differentiate(node->right) + ")";
	else if (node->value == "/")
		return "((" + Differentiate(node->left) + " )(" + this->printTree(STRING_TREE, node->right) + ") - (" + this->printTree(STRING_TREE, node->left) + ")(" + Differentiate(node->right) + "))/ (" + Differentiate(node->right) + ")^ 2 ";
	else if (node->value == "^")
		return"(" + this->printTree(STRING_TREE, node->right) + ")" + "(" + this->printTree(STRING_TREE, node->left) + ") ^ ( " + CExpression::operate("-", node->right->value, "1") + " )";
	else if (node->value == "S")
		return "cos( " + this->printTree(STRING_TREE, node->left) + ") ( " + Differentiate(node->left) + " )";
	else if (node->value == "C")
		return "-sen( " + this->printTree(STRING_TREE, node->left) + ") ( " + Differentiate(node->left) + " )";
	else if (node->value == "T")
		return "sec^2( " + this->printTree(STRING_TREE, node->left) + ") ( " + Differentiate(node->left) + " )";
	else if (node->value == "~")
		return "~" + Differentiate(node->left);
	else if (node->value == "x")
		return "_";
	else if (expreessionObj->isDigit(node->value) == true)
		return "(0)";
	else
		return "(Something went wrong...)";
}




BinaryTreeStrNode * CBinaryTree::prefixToBinaryTree(string prefix)
{
	index = 0;
	return prefixToBinaryTree_(prefix);
}

BinaryTreeStrNode * CBinaryTree::prefixToBinaryTree_(string prefix)
{
	BinaryTreeStrNode* tree = new BinaryTreeStrNode();
	string currentElement = prefix.substr(index++, 1); // here is where we actually read the string and ADD UP THE COUNTER.
													   // (SINCE THE COUNTER IS STATIC, IT GUARANTEES THAT WE'LL READ THE CORRESPONDING POSITION OF 
													   // THE STRING CORRECTLY EVERY TIME WE CALL PrefixToBinaryTree)

	if (CExpression::isOperator(currentElement))
	{
		tree->value = currentElement;
		// If we had an operator we have to operate something... don't we?
		tree->left = prefixToBinaryTree_(prefix); // create branch of whatever it takes since the father is an operator.
		tree->right = prefixToBinaryTree_(prefix); // create a correspondent branch since we're are talking about a binary operation.
	}

	if (CExpression::isDigit(currentElement) || CExpression::isVariable(currentElement))
	{
		tree->value = currentElement; // create just a terminal node since its a digit.
	}
	if (CExpression::isUnaryOperator(currentElement))
	{
		tree->value = currentElement;
		tree->left = prefixToBinaryTree_(prefix);
	}

	return tree;
}