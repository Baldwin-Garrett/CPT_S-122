#include "Cipher.h"

cipher::cipher()
{
	this->message = "";
	this->status = false;
}

cipher::cipher(string message)
{
	this->message = message;
	this->status = false;
}

void cipher::setMessage(string message)
{
	this->message = message;
}

string cipher::getMessage ()
{
	return this->message;
}

cipher::~cipher()
{
	delete this;
}
