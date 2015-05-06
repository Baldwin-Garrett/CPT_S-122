#ifndef menu
#define menu

#include "List.h"

class pMenu
{
public:
	pMenu();
	void displayMainMenu();
	void runMainMenu(nList *list, int choice, ifstream *in, ofstream *out); 
	void displaySubMenu(); 
	void runSubMenu(nList *list, int choice);
	int getChoice();
	void setChoice(int choice); 
	~pMenu(); 
private:
	int choice;
};

#endif