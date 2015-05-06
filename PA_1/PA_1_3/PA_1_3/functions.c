#include "Header.h"

void caesar_encode (char *cipher, int shift)
{
	int i = 0;

	for (i = 0; *(cipher + i) != '\0'; i++)
	{
		if ((cipher[i] + shift) >= 'A' && (cipher[i] + shift) <= 'Z') 
		{
			cipher[i] += (shift);
		} 
		else if ((cipher [i] + shift) < 'A')
		{
			cipher[i] += (shift + ('Z' - 'A')); 
		}
		else 
		{
			cipher[i] += (shift - ('Z' - 'A')); 
		}
	}
}

void caesar_decode (char* cipher, int shift)
{
	int i = 0;

	for (i = 0; *(cipher + i) != '\0'; i++)
	{
		if ((cipher[i] - shift) >= 'A' && (cipher[i] - shift) <= 'Z') 
		{
			cipher[i] -= (shift);
		} 
		else if ((cipher [i] + shift) < 'A')
		{
			cipher[i] -= (shift + ('Z'-'A')); 
		}
		else 
		{
			cipher[i] -= (shift - ('Z' - 'A')); 
		}
	}
}