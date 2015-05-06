#include "subCipher.h"
#include <algorithm>
#include <queue>

subCipher::subCipher()
{
	this->message = "";
	this->cipherText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	this->status = false;
}
subCipher::subCipher(string message)
{
	this->message = message;
	this->cipherText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	this->status = false;
}
void subCipher::Encrypt()
{
	random_shuffle(cipherText.begin(), cipherText.end());//from <algorithm>

	for(int i = 0; i < this->message.length(); i ++)
	{
		this->message[i] = toupper(this->message[i]);
		if(this->message[i] >= 65 && this->message[i] <= 90)
		{
			this->message[i] -= 65;
			this->message[i] = this->cipherText[this->message[i]];
		}
	}
}
void subCipher::Decrypt()
{
	queue<char> alpha_priority;

	string prioritized_alphabet = "ETAOINSRHDLUCMFYWGPBVKXQJZ";

	//determines the frequency of each letter
	int freq[26];
	for(int i = 0; i < 26; i++)
	{
		freq[i] = 0;
	}
	for(int i = 0; i < this->message.length(); i ++)
	{
		freq[this->message[i] - 65]++;
	}


	//builds a lifo structure with the order of letter frequency, ready to build a key
	for (int i = 0; i < prioritized_alphabet.length (); i++)
	{
		alpha_priority.push (prioritized_alphabet [i]);
	}

	//determines which letter is the most frequent, and builds the key
	int max_location = 0, max = 0, k = 0;
	while (alpha_priority.empty ())
	{
		for (int i = 0; i < 26; i++)
		{
			if (freq [i] > max)
			{
				max = freq [i];
				max_location = i;
			}
		}
		freq [max_location] = -1;
		cipherText [max_location] = alpha_priority.front ();
		alpha_priority.pop ();
		k++;
	}

	//decodes message
	for(int i = 0; i < this->message.length(); i ++)
	{
		this->message[i] = toupper(this->message[i]);
		if(this->message[i] >= 65 && this->message[i] <= 90)
		{
			this->message[i] -= 65;
			this->message[i] = this->cipherText[this->message[i]];
		}
	}
}

void subCipher::printToFile (ofstream *out)
{
	*out << this->message << endl;

	out->close();
}