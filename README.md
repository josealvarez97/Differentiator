# Differentiator

This project is a differentiator implemented by the use of binary trees. 
Since binary trees (expression binary trees) give the hierarchy of an algebraic
expression, we can recursivitely differentiate each node by applying the 
respective differentiation rule to the root, and consequently to each node of 
the tree.


##(INSTRUCTIONS FOR RUNNING THE PROGRAM)

The program will ask you to write the algebraic expression you want to differentiate.

You will have the option to:
![alttext]()

IMPORTANT NOTES:
-     DON'T USE SPACES IN THE EXPRESSION
-     EVERY VARIABLE MUST BE LOWER CASE.
-     CONSTANTS ARE WRITTEN IN UPPER CASE.




##HOW DOES THE DIFFERENTIATION WORKS?

###BASIC ALGORITHM IDEA

1. CALL DIFFERENTIATE FOR THE ROOT.
2.    IF(node->value == AnyOperator)

      Apply Differentiation Rule For the operator. Call PRINTTREE() and/or DIFFERENTIATE() when is necessary.
3. In case node->value is constant return 0. Trivial case.

##BASIC STRUCTURE

###Data Structure Implemented

- str Binary Tree

###Principal Classes

- CExpression
- CBinaryTree. Includes struct BinaryTreeStrNode. Str means string node.

###Principal Methods

#### CExpression

- bool CheckParenthesis() // To evaluate if an expression is well structured.
- string ToPostFix(string expression)
- string ToPrefix(string expression)
- int Hierarchy(string operator) //Returns the hierarchy of an operator
- bool IsOperator(string op)
- bool IsUnaryOperator(string op)
- bool IsDigit(string op)
- bool IsVariable(string op)
- string Operate(string op, string aExp, string bExp) // For operating a node and its children.

#### CBinaryTree

- void PrintTree(string treeType) // tree type holds since the implementation was first designed to support int type binary trees, not only string type.
- string Differentiate() returns the differentiation of an expression tree with full details. (A lot of parenthesis)
- string CleanDifferentiation() returns the differentiation of an expression tree without parenthesis
- string IndicatedDifferentiation() returns a big picture indicating what the derivative is.
- BinaryTreeStrNode PrefixToBinaryTree(string prefix) // returns an expression tree


###EXTRAS

- The differentiator can show an indicated differentiation.
(Screen)
- The differetiator can show a clean differentiation. (No parenthesis)
(Screen)

- The differentiator can differentiate an equation implicitely with respect to x.
(Screen)
