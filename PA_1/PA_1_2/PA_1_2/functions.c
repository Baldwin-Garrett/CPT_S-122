#include "Header.h"

int is_palindrome (char *string, int front, int back)
{
	int kitty = 1;

	if (front > back)
	{
		return (kitty);
	}

	if (string[front] != string[back])
	{
		kitty = 0;
	}
	else
	{
		front = front + 1;
		back = back - 1;
		kitty = is_palindrome (string, front, back);
	}
	return (kitty);
}

void remove_punctuation (char *string)
{
	int i = 0;

	char copystring [40] = {'\0'};

	for (i = 0; *(string + i) != '\0'; i++)
	{
		if (isalpha (*(string + i)))
		{
			*(copystring + i) = *(string + i);
		}
	}
	strcpy (string, copystring);
}