#include "caesarCipher.h"

caesarCipher::caesarCipher()
{
	this->message = "";
	this->key = -1;
	this->status = false;
}
caesarCipher::caesarCipher (string message)
{
	this->message = message;
	this->key = -1;
	this->status = false;
}
void caesarCipher::Encrypt()
{
	if(this->key == -1)
	{
		cout << "Please select a key (0-25)\n";
		int key;
		cin >> key;
		this->key = key;
		this->Encrypt();
	}
	else
	{
		int len = this->message.length();
		for(int i = 0; i < len; i++)
		{
			this->message[i] = toupper(this->message[i]);
			if(this->message[i] >= 65 && this->message[i] <= 90)
			{
				if((this->message[i] + this->key) > 90)
				{
					int sum = this->message[i] + this->key;
					this->message[i] = 64 + (sum - 90);
				}
				else
				{
					this->message[i] += this->key;
				}
			}
		}
	}
	this->status = true;
}
void caesarCipher::decrypt(int key)
{
	this->key = key;
	for(int i = 0 ; i < this->message.length(); i++)
	{
		if(isalpha (this->message [i]))
		{
			if((this->message[i] - key) < 'A')
			{
				int difference = 'A' - (this->message[i] - key);
				this->message[i] = 'Z' + 1 - difference;
			}
			else
			{
				this->message [i] = this->message [i] - key;
			}
		}
	}
}
void caesarCipher::decrypt()
{
	string tmp_string = this->message;
	for(int keys = 0; keys < 25; keys++)
	{
		for(int i = 0 ; i < this->message.length(); i++)
		{
			if(tmp_string[i] >= 65 && tmp_string[i] <= 90)
			{
				if((tmp_string[i] - keys) < 65)
				{
					int difference = 65 - (tmp_string[i] - keys);
					tmp_string[i] = 91 - difference;
				}
				else
				{
					tmp_string[i] = tmp_string[i] - keys;
				}
			}
		}
		cout << "Key = " << keys << " Message = " << tmp_string << endl;
		tmp_string = this->message;
	}
	cout << "Enter the correct key from the list above\n";
	int correctKey;
	cin >> correctKey;
	for(int i = 0 ; i < this->message.length(); i++)
	{
		if(toupper(this->message[i]) >= 65 && toupper(this->message[i]) <= 90)
		{
			if((this->message[i] - correctKey) < 65)
			{
				int difference = 65 - (this->message[i] - correctKey);
				this->message[i] = 91 - difference;
			}
			else
			{
				this->message[i] -= correctKey;
			}
		}
	}
	this->key = correctKey;
}
void caesarCipher::printToFile(ofstream *out)
{
	*out << this->message << endl;

	out->close();
}
