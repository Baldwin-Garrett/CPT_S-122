#include "List.h"

nList::nList(){
	this->head = NULL;
}

nList::nList(sNode *head)
{
	this->head = head;
}

void nList::insertNewStudent(sNode *newNode)
{
	if(!this->head)
	{ 
		this->head = newNode;
		this->head->setNext(nullptr);

	}
	else
	{ 
		sNode *tmp = this->head;
		this->head = newNode;
		newNode->setNext(tmp);
	}
}

void nList::importFromFile(ifstream *in)
{
	int csvSection = 0;

	int line = 0;
	bool inQuotes = 0; 
	string tmp = string(); 
	sNode *tmp_node;
	tmp_node = new sNode();
	while(!in->eof())
	{ 
		if(line  == 0)
		{ 
			int safety= 0;
			while(in->get() != '\n'){
				in->ignore();
				safety++; 
				if(safety > 150)
				{
					break;
				}
			}
			line ++;
		}
		if(line != 0)
		{ 
			if(in->peek() == ',' && inQuotes == false)
			{
				in->get();
				if(csvSection == 2)
				{
					tmp_node->setName(tmp);
					tmp = "";
				}
				else if(csvSection == 3)
				{
					tmp_node->setEmail(tmp);
					tmp = "";
				}
				else if(csvSection == 5)
				{
					tmp_node->setMajor(tmp);
					tmp = "";
				}
				else if(csvSection == 6)
				{
					tmp_node->setClassStanding(tmp);
					tmp = "";
				}
				csvSection++;
			}

			else if(in->peek() == ',' && inQuotes == true)
			{
				char n;
				(*in) >> n;
				tmp += n;
			}
			else if(in->peek() == '"' && inQuotes == false)
			{
				in->ignore();
				inQuotes = true;
			}
			else if(in->peek() == '"' && inQuotes == true)
			{
				in->ignore();
				inQuotes = false;
			}

			else if((char)in->peek() >= 48 && (char)in->peek() <= 57)
			{
				if(csvSection == 0){
					int n;
					(*in) >> n;
					tmp_node->setRecNum(n);
				}
				else if(csvSection == 3)
				{
					char n;
					(*in) >> n;
					tmp += n;
				}
				else if(csvSection == 1)
				{
					int n;
					(*in) >> n;
					tmp_node->IDnum = n;
				}
				else if(csvSection == 4)
				{
					int n;
					(*in) >> n;
					tmp_node->setCredits(n);
				}
			}

			else if(in->peek() == '@')
			{
				char n;
				(*in) >> n;
				tmp += n;
			}

			else if(in->peek() == '\n' && tmp != "")
			{
				tmp_node->setClassStanding(tmp);
				tmp_node->setRecNum(line);
				tmp = "";
				in->ignore();
				line++;
				csvSection = 0;
				this->insertNewStudent(tmp_node);
				tmp_node = new sNode();
			}

			else{
				char n;
				(*in) >> n;
				tmp += n;
			}
		}
	}
	tmp_node->setClassStanding(tmp);
	tmp_node->setRecNum(line);
	this->insertNewStudent(tmp_node);
}
void nList::printList(){
	if(this->head == nullptr)
	{
		std::cout << "The list is empty\n";
		return;
	}
	sNode *tmp = this->head;
	while(tmp->getNext() != nullptr){ 
		std::cout << tmp->getRecNum() << '\n'
			<< tmp->getName() << '\n'
			<< tmp->getEmail() << '\n'
			<< tmp->getCredits() << '\n'
			<< tmp->getMajor() << '\n'
			<< tmp->getClassStanding() << '\n';
		tmp = tmp->getNext();
		std::cout << '\n';
	}
	std::cout << tmp->getRecNum() << '\n'
		<< tmp->getName() << '\n'
		<< tmp->getEmail() << '\n'
		<< tmp->getCredits() << '\n'
		<< tmp->getMajor() << '\n'
		<< tmp->getClassStanding() << '\n';
	tmp = tmp->getNext();
	std::cout << '\n';
}
void nList::exportList(ofstream *out)
{
	if(this->head == nullptr)
	{ 
		std::cout << "Empty\n";
		return;
	}
	else
	{
		sNode *tmp = this->head;
		int i = 1;
		*out << ",ID,Name,Email,Units,Program,Level\n";
		while(tmp->getNext() != nullptr)
		{ 
			(*out) << i << "," << tmp->getIDNum() << ",\"" << tmp->getName() << "\"," << tmp->getEmail() << "," << tmp->getCredits() << "," << tmp->getMajor() << "," << tmp->getClassStanding() << "\n";
			tmp = tmp->getNext();
			i++;
		}
		(*out) << i << "," << tmp->getIDNum() << ",\"" << tmp->getName() << "\"," << tmp->getEmail() << "," << tmp->getCredits() << "," << tmp->getMajor() << "," << tmp->getClassStanding();
	}
}
sNode *nList::getHead()
{ 
	return this->head;
}
void nList::markAbsences(string date)
{
	sNode *tmp = this->head;
	while(tmp->getNext() != nullptr){
		std::cout << "Is " << tmp->getName() << " absent?(Y/N)\n";
		char choice;
		std::cin >> choice;
		if(tolower(choice) == 'y'){
			tmp->addAbsence(date);
			tmp = tmp->getNext();
		}
		else if(tolower(choice) == 'n'){
			tmp = tmp->getNext();
		}
		else{
			std::cout << "Invalid input, try again\n";
		}
	}
	std::cout << "Is " << tmp->getName() << " absent?(Y/N)\n";
	char choice;
	std::cin >> choice;
	if(tolower(choice) == 'y')
		tmp->addAbsence(date);
	else if(tolower(choice) == 'n')
		tmp = tmp->getNext();
}
void nList::generateReport(nList *list, int reportType)
{
	if(reportType == 1)
	{  
		ofstream *out = new ofstream();
		out->open("report1.txt", std::ofstream::app);

		sNode *tmp = list->head;
		while(tmp->getNext() != nullptr)
		{
			*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n"; 
			if(tmp->getNumAbsences() > 0)
			{
				*out << "Dates:\n";
				int i = 0;
				while(tmp->getAbsentDate(i) != "")
				{
					*out << tmp->getAbsentDate(i) << "\n";
					i++;
				}
			}
			*out << "\n";
			tmp = tmp->getNext();
		}
		*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n";
		if(tmp->getNumAbsences() > 0)
		{
			*out << "Dates:\n";
			int i = 0;
			while(tmp->getAbsentDate(i) != "")
			{
				*out << tmp->getAbsentDate(i) << "\n";
				i++;
			}
			*out << "\n";
			out->close();
		}
	}

	else if(reportType == 2)
	{
		ofstream *out = new ofstream();
		out->open("report2.txt", std::ofstream::app);

		std::cout << "Please enter the minimum threshold of absences\n";
		int threshold = 0;
		std::cin >> threshold;

		sNode *tmp = list->head;
		while(tmp->getNext() != nullptr)
		{
			if(tmp->getNumAbsences() > threshold)
			{
				*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n"; 
				if(tmp->getNumAbsences() > 0)
				{
					*out << "Dates:\n";
					int i = 0;
					while(tmp->getAbsentDate(i) != "")
					{
						*out << tmp->getAbsentDate(i) << "\n";
						i++;
					}
				}
				*out << "\n";
				tmp = tmp->getNext();
			}
			tmp = tmp->getNext();
		}
		if(tmp->getNumAbsences() > threshold)
		{
			*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n";
			if(tmp->getNumAbsences() > 0)
			{
				*out << "Dates:\n";
				int i = 0;
				while(tmp->getAbsentDate(i) != "")
				{
					*out << tmp->getAbsentDate(i) << "\n";
					i++;
				}
				*out << "\n";
				out->close();
			}

		}
	}

	else if(reportType == 3)
	{
		ofstream *out = new ofstream();
		out->open("report3.txt", std::ofstream::app);

		std::cout << "Please enter the desired date of absence, date must be entered in MM/DD/YYYY format.\n";
		string date;
		std::cin >> date;

		sNode *tmp = list->head;
		while(tmp->getNext() != nullptr){
			if(contains(date, tmp->getAbsentDates()))
			{
				*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n"; 
				if(tmp->getNumAbsences() > 0){
					*out << "Dates:\n";
					int i = 0;
					while(tmp->getAbsentDate(i) != "")
					{
						*out << tmp->getAbsentDate(i) << "\n";
						i++;
					}
				}
				*out << "\n";
				tmp = tmp->getNext();
			}
			tmp = tmp->getNext();
		}
		if(contains(date, tmp->getAbsentDates()))
		{
			*out << "Name: " << tmp->getName() << "\nID number: " << tmp->IDnum << "\nNumber of Absences: " << tmp->getNumAbsences() << "\n";
			if(tmp->getNumAbsences() > 0)
			{
				*out << "Dates:\n";
				int i = 0;
				while(tmp->getAbsentDate(i) != "")
				{
					*out << tmp->getAbsentDate(i) << "\n";
					i++;
				}
				*out << "\n";
				out->close();
			}
		}
	}
}

int contains(string str, string arr[])
{
	int len = arr->length();
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == str)
			return 1;
	}
	return 0;
}