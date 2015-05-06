#include "menu.h"
#include "Cipher.h"
#include "subCipher.h"
#include "caesarCipher.h"


//Garrett J. Baldwin

pMenu::pMenu()
{
	choice = 0;
}

pMenu::~pMenu()
{
	delete this;
}

void pMenu::displayMainMenu()
{
	cout << "Garrett's CIPHER SYSTEM\n\n1. Caesar\n2. Substitution" << "\n";
}

void pMenu::runMainMenu(int choice, ifstream *in, ofstream *out)
{
	int x = 0, y = 0;

	string input_string;

	system ("cls");

	//check menu option
	if(choice == 1)//Caesar cipher
	{
		cout << "CAESAR CIPHER SYSTEM\n\n1. encode\n2. decode" << "\n";
		do
		{
			cin >> x;
		}while (x < 1 || x > 2);
		system ("cls");
		if (x == 1)//encode
		{
			cout << "How would you like to input the string you would like to encode?\n\n1. Terminal\n2. File" << endl;
			do
			{
				cin >> y;
			}while (y < 1 || y > 2);

			if (y == 1)//input string from cin
			{
				cout << "Please enter your string." << endl;
				cin >> input_string;
			}

			if (y == 2)//input string from fstream
			{
				(*in) >> input_string;
			}
		}

		if (x == 2)//decode
		{
			cout << "How would you like to input the string you would like to encode?\n\n1. Terminal\n2. File" << endl;
			do
			{
				cin >> y;
			}while (y < 1 || y > 2);

			if (y == 1)//input string from cin
			{
				cout << "Please enter your string." << endl;
				cin >> input_string;
			}

			if (y == 2)//input string from fstream
			{
				(*in) >> input_string;
			}
		}
		ceasarmode (x, in, out, input_string);
	}

	else if(choice == 2)//Substitution
	{
		cout << "SUBSTITUTION CIPHER SYSTEM\n\n1. encode\n2. decode" << "\n";
		do
		{
			cin >> x;
		}while (x < 1 || x > 2);
		system ("cls");
		if (x == 1)//encode
		{
			cout << "How would you like to input the string you would like to encode?\n\n1. Terminal\n2. File" << endl;
			do
			{
				cin >> y;
			}while (y < 1 || y > 2);

			if (y == 1)//input string from cin
			{
				cout << "Please enter your string." << endl;
				cin >> input_string;
			}

			if (y == 2)//input string from fstream
			{
				(*in) >> input_string;
			}
		}

		if (x == 2)//decode
		{
			cout << "How would you like to input the string you would like to encode?\n\n1. Terminal\n2. File" << endl;
			do
			{
				cin >> y;
			}while (y < 1 || y > 2);

			if (y == 1)//input string from cin
			{
				cout << "Please enter your string." << endl;
				cin >> input_string;
			}

			if (y == 2)//input string from fstream
			{
				(*in) >> input_string;
			}
		}
		submode (x, in, out, input_string);
	}

	//pause and clear screen for next option
	system("pause");
	system("cls");
}

void ceasarmode (int mode, ifstream *in, ofstream *out, string message)
{
	caesarCipher *tmp = new caesarCipher (message);
	char has_key = '\0';
	int key = 0;

	if (mode == 1)
	{
		tmp->Encrypt ();
	}
	else
	{
		cout << "do you have a key? (Y/N)" << endl;
		do
		{
			cin >> has_key;
		}while (has_key != 'y' && has_key != 'Y' && has_key != 'n' && has_key != 'N');
		system ("cls");
		if (has_key == 'y' || has_key == 'Y')
		{
			cout << "What is your key?" << endl;
			cin >> key;

			tmp->decrypt (key);
		}
		else
		{
			tmp->decrypt ();
		}
	}
	cout << "**ENCODED MESSAGE ADDED TO FILE**" << endl << endl;
	cout << "Encoded message: " << tmp->getMessage () << endl;
	tmp->printToFile (out);
}

void submode (int mode, ifstream *in, ofstream *out, string message)
{
	subCipher *tmp = new subCipher (message);

	if (mode == 1)
	{
		tmp->Encrypt ();
	}
	else
	{
		tmp->Decrypt ();
	}

	cout << "**ENCODED MESSAGE ADDED TO FILE**" << endl << endl;
	cout << "Encoded message: " << tmp->getMessage () << endl;
	tmp->printToFile (out);
}