#include <iostream>
#include "Expression.h"
#include "BinaryTree.h"
#include <Windows.h>
using namespace std;

int main()
{

	//string expression = "2*x^4+2*x^5";
	//string expression = "2*x^4";
	//string expression = "1/x^2";
	//string expression = "C(4*x^5)/x^3";
	//string* expressionArrayTest = new string[5]
	//{ "C(((((4*x^5)))))/x^3", "2*x^4+2*x^5" , "2*x^4", "1/x^2", "C((4*x^5))/x^3" /*"4*x^5+5*x=5+4*y^3+y*4"*/ };


	//for (int i = 0; i < 5; i++)
	//{
		////cout << "INGRESE INFIX A DERIVAR:  ";
		////cin >> expression;
		//cout << "------------------------------------------------------------------------------------" << endl;
		//cout << "EXPRESION: " << expressionArrayTest[i] << endl;
		//CBinaryTree* tree = new CBinaryTree(CBinaryTree::prefixToBinaryTreeNode(CExpression::toPrefix(expressionArrayTest[i])));
		//cout << "PREFIX: " << CExpression::toPrefix(expressionArrayTest[i]) << endl << endl;
		//cout << "DERIVADA INDICADA: " << tree->IndicatedDifferentiation() << endl;
		//cout << "DERIVADA DETALLADA: " << tree->Differentiate() << endl;
		//cout << "DERIVADA LIMPIA: " << tree->CleanDifferentiation() << endl << endl;

		///*cout << "------------------------------------------------------------------------------------" << endl;*/



		//delete tree;
	//}

	string expression = "";/*"4*x^5+5*x=5+4*x^3+x*4";*/
	CBinaryTree* tree;
	string decision = "";

	while (true)
	{
		try
		{
			//cout.clear();
			system("Cls");
			cout << "1) DERIVAR EXPRESION ALGEBRAICA (en terminos de x) " << endl << "2) DERIVAR ECUACION IMPLICITAMENTE (Respecto a x, puede ser en ter de x Y/O y)" << endl;
			//getline(std::cin, decision);
			cin >> decision;

			cout << "INGRESE INFIX A DERIVAR:  ";
			std::cin >> expression;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "EXPRESION: " << expression << endl;
			/*CBinaryTree**/ tree = new CBinaryTree(CBinaryTree::prefixToBinaryTreeNode(CExpression::toPrefix(expression)));
			cout << "PREFIX: " << CExpression::toPrefix(expression) << endl << endl;
			if (decision == "1")
			{
				cout << "DERIVADA INDICADA: " << tree->IndicatedDifferentiation() << endl;
				cout << "DERIVADA DETALLADA: " << tree->Differentiate() << endl;
				cout << "DERIVADA LIMPIA: " << tree->CleanDifferentiation() << endl << endl;
			}
			else if (decision == "2")
			{
				cout << "DERIVADA INDICADA: " << tree->IndicatedDifferentiation() << endl;
				cout << "DERIVADA IMPLICITA: " << tree->ImplicitDifferentiation() << endl;
			}
			else
			{
				cout << "Algo salio mal, intente de nuevo" << endl;
				continue;
			}

			/*cout << "------------------------------------------------------------------------------------" << endl;*/
			delete tree;

			cout << "DESEA CONTINUAR? (Si: Presione cualquier tecla. No: Presione 1)" << endl;
			//getline(std::cin, decision);
			cin >> decision;

			if (decision == "1")
				break;
		}
		catch (exception e)
		{
			cout << "Manejo mal el programa. Asegurese de verificar que cumple las reglas del tipo de derivada que pide." << endl;
			cout << "El programa se reiniciara automaticamente" << endl;
			system("Pause");
		}
		

	}







	return 0;
}