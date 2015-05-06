#ifndef Node
#define Node

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

class sNode{
public:
	sNode(); //Constructor
	sNode(int recNum, int IDnum, string name, string email, int credits, string major, string classStanding); //Copy Constructor

	int getRecNum(); //Getters for your variables
	int getIDNum();
	string getName();
	string getEmail();
	int getCredits();
	string getMajor();
	string getClassStanding();
	sNode *getNext();
	int getNumAbsences();
	string getAbsentDate(int i);
	string *getAbsentDates();

	void setRecNum(int recNum); //Setters for your variables
	void setIDnum(int IDnum);
	void setName(string name);
	void setEmail(string email);
	void setCredits(int credits);
	void setMajor(string major);
	void setClassStanding(string classStanding);
	void setNext(sNode *next);

	void addAbsence(string date); //Used in the mark Absences function.
	int IDnum; //Used to fix a bug, that I later fixed entirely. Otherwise std variable

private:
	int recNum; //Variables
	string name;
	string email;
	int credits;
	string major;
	string classStanding;
	sNode *next;
	int numAbsences;
	string absentDates[500];
};

#endif