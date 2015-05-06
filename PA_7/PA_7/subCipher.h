#include "Cipher.h"

class subCipher : public cipher{
public:
	subCipher();
	subCipher(string message);
	void Encrypt();
	void Decrypt();
	void printToFile(ofstream *out);
private:
	string cipherText;
};
