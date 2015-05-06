#include "menu.h"

//Garrett J. Baldwin
//Worked with: Dave Hohl and Matthew Gower

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
	std::cout << "1- Import Records to Master List\n2- Load Master List\n3- Store Master List\n4- Mark Absences\n5- Generate Reports\n6- Print List\n7- Exit\n";
}

void pMenu::runMainMenu(nList *list, int choice, ifstream *in, ofstream *out)
{
	//format string with current date
	time_t date;
	struct tm * sTime;
	char content[128];
	time(&date);
	sTime = localtime(&date);
	strftime(content,80,"%m/%d/%Y",sTime);
	string str(content);

	//check menu option
	if(choice == 1)//Import from .csv
	{
		if(list->getHead())
		{
			delete list;
			list = new nList();
		}
		list->importFromFile(in);
	}

	else if(choice == 2)//Import from .txt
	{
		if(list->getHead())
		{
			delete list;
			list = new nList();
		}

		in->close();
		in->open("master.txt", std::ifstream::in);
		list->importFromFile(in);
		in->close();
		in->open("list.csv", std::ifstream::in);
	}

	else if(choice == 3)//Export to .txt
	{ 
		out->open("master.txt", std::ofstream::app);
		list->exportList(out);
		out->close();
	}

	else if(choice == 4)//Mark absences
	{
		list->markAbsences(str);
	}

	else if(choice == 5)//Sub menu for reports
	{
		int x = 0;
		while(x != 4)
		{
			std::cout << "Please select a report type\n"
				<< "1- Student info, # of absences, Dates of absences\n"
				<< "2- All students with more absences than you decide\n"
				<< "3- All students absent on a certain date\n"
				<< "4- Exit to Main Menu\n";
			std::cin >> x;
			list->generateReport(list, x);
		}
	}

	else if(choice == 6)//Print list
	{
		list->printList();
	}

	//pause and clear screen for next option
	system("pause");
	system("cls");
}
int pMenu::getChoice()
{
	return this->choice;
}
void pMenu::setChoice(int choice)
{
	this->choice = choice;
}