#include "Header.h"

int main (void)
{
	char *arr_ptr_str [100];
	int number_strings = 0, i = 0;

	printf ("Enter the number of strings (0-100) that you want to randomly generate: ");
	scanf ("%d", &number_strings);
	for (i = 0; i < number_strings; i++)
	{
		arr_ptr_str [i] = (char *)malloc (sizeof ("AFDASFASDFASDFADFASDFAS"));
		random_string (arr_ptr_str [i]);
	}

	printf ("The list of unsorted random strings:\n");
	for (i = 0; i < number_strings; i++)
	{
		printf ("%s\n", arr_ptr_str [i]);
	}

	bubble_sort (arr_ptr_str, number_strings);

	printf ("The list of sorted random strings:\n");
	for (i = 0; i < number_strings; i++)
	{
		printf ("%s\n", arr_ptr_str [i]);
		free (arr_ptr_str [i]);
	}
}