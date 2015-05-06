#include "Header.h"

int main (void)
{
	BankAccount account = BankAccount ();
	vector<BankAccount> accounts;

	BankAccount *test = new BankAccount;

	int num_accounts = 0;
	int menu_option = 0;
	int second_pass_flag = 0;

	//generates date string
	time_t date;
	struct tm * sTime;
	char content [128];

	time (&date);
	sTime = localtime (&date);
	strftime (content, 80, "%m/%d/%Y", sTime);
	string str (content);

	//main program loop
	while (1)
	{
		system ("cls");

		//get menu option
		if (second_pass_flag == 0)
		{
			cout << "Welcome to Garrett J. Baldwin's PA_5! Please select an option" << endl;
		}
		else
		{
			cout << "Want do do anything else?" << endl;
		}

		cout << "1-New account" << endl << "2-View account" << endl << "3-Make a withdrawal" << endl << "4-Make a deposit" << endl << "5- Exit" <<  endl;
		cin >> menu_option;

		//New Account
		if(menu_option == 1)
		{ 
			cout << "Name :" << endl;
			string newCustName;
			cin >> newCustName;
			cout << "Enter your starting balance: " << endl;
			int accntbalance;
			cin >> accntbalance;
			BankAccount tmp = BankAccount(accntbalance, num_accounts, newCustName, str);
			accounts.insert(accounts.begin()+num_accounts , tmp);
			num_accounts++;
			cout << "Complete! Your account number is: " << tmp.getAccountNum() << endl;
		}
		//View Account
		else if(menu_option == 2)
		{ 
			cout << "Please enter your account number" << endl;
			int tmp;
			cin >> tmp;
			accounts[tmp].printAccountInfo();
		}
		//Withdrawl
		else if(menu_option == 3)
		{
			cout << "First, please enter your account number" << endl;
			int accntNum;
			cin >>accntNum;
			if(accntNum >= accounts.size())
			{
				cout << "Error: ACCOUNT NOT FOUND" << endl;
			}
			else
			{
				cout << "How much will you be withdrawing?" << endl;
				int debitAmount;
				cin >> debitAmount;
				accounts[accntNum].debit(debitAmount);
			}
		}
		//Deposit
		else if(menu_option == 4)
		{ 
			cout << "Please enter your account number: " << endl;
			int accntNum;
			cin >>accntNum;
			if(accntNum >= accounts.size())
			{
				cout << "Error: ACCOUNT NOT FOUND" << endl;
			}
			else
			{
				int depositAmt;
				cout << "Enter your starting balance: " << endl;
				cin >> depositAmt;
				accounts[accntNum].deposit(depositAmt);
			}
		}
		//Exit
		else if (menu_option == 5)
		{
			exit (-1);
		}
		second_pass_flag++;
		system ("pause");
	}
}