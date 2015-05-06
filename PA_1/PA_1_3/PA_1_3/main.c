#include "Header.h"

int main (void)
{
	char cipher [50];
	int shift  = 0, i = 0, state = 0;

	printf ("Would you like to encode or decode? (0-encode, 1-decode)\n");
	do
	{
		scanf ("%d", &state);
	}while (state < 0 || state > 1);


	if (state == 0)
	{
		printf ("Enter text to be encrypted (will be transformed to all caps):");
		scanf ("%s", cipher);
		printf ("Enter your desired shift value (-10 - 10):");
		scanf ("%d", &shift);

		for (i = 0; *(cipher + i) != '\0'; i++)
		{
			*(cipher + i) = toupper (*(cipher + i));
		}

		printf ("\nUnciphered string: %s\n", cipher);

		caesar_encode (cipher, shift);

		printf("Ciphered string: %s\n", cipher);
	}
	else
	{
		printf ("Enter text to be decrypted (will be transformed to all caps):");
		scanf ("%s", cipher);
		printf ("Enter the shift value (-10 - 10):");
		scanf ("%d", &shift);

		for (i = 0; *(cipher + i) != '\0'; i++)
		{
			*(cipher + i) = toupper (*(cipher + i));
		}

		caesar_decode (cipher, shift);

		printf ("Unciphered string: %s\n", cipher);
	}
}