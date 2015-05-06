#ifndef CaesarCipher
#define CaesarCipher

#include "Cipher.h"

class caesarCipher: public cipher
{
public:
	caesarCipher();
	caesarCipher (string message);
	void Encrypt();
	void decrypt(int key);
	void decrypt();
	void printToFile(ofstream *out);
private:
	int key;
};

#endif