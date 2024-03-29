#pragma once
#include <string>
#include "Expression.h"
#include <fstream>
#include <stdlib.h>
#include <algorithm> 

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
enum treeType {STRING_TREE, INT_TREE};


using namespace std;

struct BinaryTreeStrNode
{
	string value = "";
	BinaryTreeStrNode* left = nullptr;
	BinaryTreeStrNode* right = nullptr;
};

struct BinaryTreeIntNode
{
	int value = NULL;
	BinaryTreeIntNode* left = nullptr;
	BinaryTreeIntNode* right = nullptr;
};


class CBinaryTree
{
public:
	CBinaryTree();
	CBinaryTree(BinaryTreeStrNode* aRoot);

	~CBinaryTree();

	BinaryTreeStrNode* strRoot;
	BinaryTreeIntNode* intRoot;
	CExpression* expreessionObj;


	BinaryTreeStrNode* GetNodePtr(string value);
	BinaryTreeIntNode* GetNodePtr(int value); // it's not that usefull for numbers...
	
public:
	static BinaryTreeStrNode* prefixToBinaryTreeNode(string prefix);

private:
	static BinaryTreeStrNode* prefixToBinaryTree_(string prefix);



	bool IsAnElement(string value);
	bool IsAnElement(int value);
	int strTreeLevel();
	int intTreeLevel();
	void Insert(string value);
	void Insert(int value);

	string printTree(int treeType);
	string printTree(treeType type, BinaryTreeStrNode* node);
	string ListAllPossiblePathResults();
private:
	BinaryTreeStrNode* GetNodePtr(BinaryTreeStrNode* node, string value);
	void Insert(BinaryTreeStrNode* node, string value);
	void Insert(BinaryTreeIntNode* node, int value);

public:
	string Differentiate();
	string ImplicitDifferentiation();
	string IndicatedDifferentiation();

	string CleanDifferentiation();

private:
	string Differentiate(BinaryTreeStrNode* node);
	string ImplicitDifferentiation(BinaryTreeStrNode* node);
	string IndicatedDifferentiation(BinaryTreeStrNode* node);
	string CleanDifferentiation(BinaryTreeStrNode* node);




};

