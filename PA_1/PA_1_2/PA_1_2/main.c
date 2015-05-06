#include "Header.h"

int main (void)
{
	char string1 [100];
	int palindrome_ans = 0;

	printf ("Enter a string to test if it's a palindrome: ");
	scanf ("%s", string1);
	remove_punctuation (string1);
	palindrome_ans = is_palindrome (string1, 0, strlen (string1) - 1);
	if (palindrome_ans)
	{
		printf ("The string is a palindrome\n");
	}
	else
	{
		printf ("The string is not a palindrome\n");
	}
}