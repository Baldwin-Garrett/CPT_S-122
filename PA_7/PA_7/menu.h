#ifndef menu
#define menu

#include <iostream>
#include <fstream>

#include "Cipher.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

class pMenu
{
public:
	pMenu();
	void displayMainMenu();
	void runMainMenu(int choice, ifstream *in, ofstream *out); 
	~pMenu(); 
private:
	int choice;
};

void ceasarmode (int mode, ifstream *in, ofstream *out, string messge); 
void submode (int mode, ifstream *in, ofstream *out, string message);

#endif