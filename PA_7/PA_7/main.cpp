#include "Header.h"
#include "menu.h"

using std::cout;
using std::cin;

int main (void)
{
	srand(time_t(NULL));

	pMenu *newMenu = new pMenu ();

	ifstream *in = new ifstream();	
	in->open("Input.txt", std::ifstream::in);

	ofstream *out = new ofstream();
	out->open("Output.txt", std::ofstream::app);

	int x = 0;

	while (x != 3)
	{
		newMenu->displayMainMenu ();

		cin >> x;

		newMenu->runMainMenu (x, in, out);


	}
	return (0);
}