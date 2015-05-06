#include "node.h"

sNode::sNode()
{
	//init data to zero
	this->classStanding ="";
	this->credits = 0;
	this->email = "";
	this->name = "";
	this->IDnum = 0;
	this->major = "";
	this->recNum = 0;
	this->numAbsences = 0;
	this->next = NULL;
	for(int i = 0; i < 500; i ++)
	{
		absentDates[i] = "";
	}
}

sNode::sNode(int recNum, int IDnum, string name, string email, int credits, string major, string classStanding){
	this->recNum = recNum;
	this->IDnum = IDnum;
	this->name = name;
	this->email = email;
	this->major = major;
	this->classStanding = classStanding;
	this->next = NULL;
	this->numAbsences = 0;

	//init absent string
	for(int i = 0; i < 500; i ++)
	{ 
		absentDates[i] = "";
	}
}

int sNode::getCredits()
{
	return this->credits;
}
int sNode::getRecNum()
{
	return this->recNum;
}
int sNode::getIDNum()
{
	return this->IDnum;
}
string sNode::getName()
{
	return this->name;
}
string sNode::getMajor()
{
	return this->major;
}
string sNode::getEmail()
{
	return this->email;
}
string sNode::getClassStanding()
{
	return this->classStanding;
}

sNode *sNode::getNext()
{
	if(this->next == nullptr) //Checks for null
		return nullptr;
	return this->next;
}

void sNode::setName(string name)
{
	this->name = name;
}

void sNode::setEmail(string email)
{
	this->email = email;
}

void sNode::setMajor(string major)
{
	this->major = major;
}

void sNode::setClassStanding(string classStanding)
{
	this->classStanding = classStanding;
}

void sNode::setRecNum(int recNum)
{
	this->recNum = recNum;
}

void sNode::setCredits(int credits)
{
	this->credits = credits;
}

void sNode::setNext(sNode *next)
{
	this->next = next;
}

void sNode::addAbsence(string date)
{
	this->numAbsences ++;
	int i = 0;
	while(absentDates[i] != "")//Find the closest empty array index
	{
		i ++; 
	} 
	absentDates[i] = date;
}

int sNode::getNumAbsences()
{
	return this->numAbsences;
}

string sNode::getAbsentDate(int i)
{
	return this->absentDates[i];
}

string *sNode::getAbsentDates()
{
	return this->absentDates;
}