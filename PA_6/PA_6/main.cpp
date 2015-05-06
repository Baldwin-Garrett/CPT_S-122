#include "List.h"
#include "menu.h"

using std::cout;
using std::cin;

int main()
{
	ifstream *in = new ifstream();	
	in->open("list.csv", std::ifstream::in);

	ofstream *out = new ofstream();

	nList *list = new nList();

	//check input stream
	if(!in)
	{
		return 0;
	}

	cout << "Welcome to my classroom attendance system!" << '\n';
	cout << "Please choose from the following options: " << '\n';

	sNode *newerNode = new sNode();

	int y = 0;

	pMenu *newMenu = new pMenu();

	while(y != 7)
	{
		
		newMenu->displayMainMenu();

		cin >> y;

		newMenu->runMainMenu(list, y, in, out);
		
	}
}