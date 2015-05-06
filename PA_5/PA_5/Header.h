#ifndef Header
#define Header

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <new>

using namespace std;

class BankAccount{
public:
	//constructors
	BankAccount(); 
	BankAccount(double balance, int accountNum, string custName, string startDate); 

	//display method
	void printAccountInfo(); 

	//withdrawl method
	void debit(int withdrawal); 

	//getters
	double getBalance(); 
	int getAccountNum(); 
	string getCustName(); 
	string getStartDate(); 

	//setters
	void setBalance(double balance);
	void setAccountNum(int accountNum);
	void setCustName(string custName); 
	void setStartDate(string startDate); 

	//deposit method
	void deposit(int amount);

private:
	//data
	double balance;
	int accountNum;
	string custName;
	string startDate;

};

#endif