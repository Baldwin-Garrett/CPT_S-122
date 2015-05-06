#include "Header.h"

void bubble_sort (char *strings [30], int n)
{
	int i = 0, passes = 0;
	char *temp_ptr = 0;

	for (passes = 1; passes < n - 1; passes++)
	{
		for (i = 0; i < n - passes; i++)
		{
			if (strcmp (strings [i], strings [i + 1]) > 0)
			{
				temp_ptr = strings [i];
				strings [i] = strings [i + 1];
				strings [i + 1] = temp_ptr;
			}
		}
	}
}

char *random_string (char *string)
{
	int i = 0;

	char strings [10] [20] = {"hello", "apple", "butthurt", "dank", "computer", "photons", "initiate", "vel'koz", "holocaust", "panel"};
	i = rand () % 10;
	strcpy (string, strings [i]);
}