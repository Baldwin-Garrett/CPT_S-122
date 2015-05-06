#ifndef List
#define List

#include "Node.h"
#include <time.h>

//List used to store the students
class nList
{
	friend sNode;
public:
	nList();//Constructor
	nList(sNode *head);//Copy constructor
	void insertNewStudent(sNode *node);//Method for inserting a new sNode
	void importFromFile(ifstream *in);//Used to import from list.csv, and master.txt
	void printList();//Function used to print all nodes in the list to the screen
	void exportList(ofstream *out);//Used for exporting data to master.txt, and report123.txt
	sNode *getHead();//getter
	void markAbsences(string date);//Used to mark absences by traversing student by student
	void generateReport(nList *list, int reportType);//Used to generate output data to files report123.txt
private:
	sNode *head;//pointer to head of the list
};
int contains(string str, string arr[]);//Used in generateReport() to save on method space.
#endif