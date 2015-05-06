#ifndef Cipher
#define Cipher

#include<iostream>
#include<fstream>
#include <string>

using namespace std;
using std::ofstream;

class cipher{
public:
	cipher();
	cipher(string message);
	cipher(const cipher &b);
	~cipher();
	string getMessage();
	bool getStatus();
	void setMessage(string message);
	void setStatus(bool status);
protected:
	string message;
	bool status;
};

#endif