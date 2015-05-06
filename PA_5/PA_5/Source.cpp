#include "Header.h"

BankAccount::BankAccount()
{
	balance = 0;
	accountNum = 0;
	custName = "";
	startDate = "";
}

BankAccount::BankAccount(double balance, int accountNum, string custName, string startDate)
{ 
	if(balance >= 0)
	{
		this->balance = balance;
	}
	else
	{
		this->balance = 0;
		cout << "Error: Could not initialize Account Balance: Input below zero" << endl;
	}
	this->accountNum = accountNum;
	this->custName = custName;
	this->startDate = startDate;
}

double BankAccount::getBalance()
{
	return balance;
}

int BankAccount::getAccountNum()
{ 
	return accountNum;
}

string BankAccount::getCustName()
{ 
	return custName;
}

string BankAccount::getStartDate()
{ 
	return startDate; 
}

void BankAccount::setBalance(double balance)
{ 

	if(balance >= 0)
		this->balance = 0;
	else{
		cout << "Error: Incorrect input for BALANCE" << endl;
	}
}

void BankAccount::setAccountNum(int accountNum)
{ 
	this->accountNum = accountNum;
}

void BankAccount::setCustName(string custName)
{ 
	this->custName = custName;
}

void BankAccount::setStartDate(string startDate)
{ 
	this->startDate = startDate;
}

void BankAccount::debit(int withdrawal)
{
	if(withdrawal <= this->balance)
	{ 
		this->balance -= withdrawal;
		cout << "Withdrawal successful, your new account balance is: $" << this->balance <<endl;
	}
	else
	{
		cout << "Insufficient funds" << endl;
	}
}

void BankAccount::printAccountInfo()
{
	cout << "Customer Name: " << getCustName() << endl;
	cout << "Account Number: " << getAccountNum() << endl;
	cout << "Date of account creation: " << getStartDate() << endl;
	cout << "Account Balance: $" << getBalance() << endl;
}

void BankAccount::deposit(int amount)
{
	this->balance += amount;
	cout << "Deposit successful. New account balance is: $" << this->balance <<endl;
}