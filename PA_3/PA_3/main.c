#include "Header.h"

int main (void)
{
	char infix [50] = {'\n'};
	char postfix [50] = {'\n'};
	int n = 0, option = 0;

	printf ("Welcome to Garrett J. Baldwin's math solver!\n");

	while (1)
	{
		printf ("What would you like to do? \n");
		printf ("1. Evaluate infix string\n");
		printf ("2. Test infix evaluator with example infix string\n");
		printf ("3. Exit the program\n");

		do
		{
			scanf ("%d", &option);
		}while (option <= 0 || option >= 4);

		switch (option)
		{
		case 1:
			printf ("\nPlease enter the INFIX expression you want to evaluate: ");
			scanf ("%s", infix);
			break;

		case 2:
			strcpy (infix, "9*(5-4)+2/6)");
			break;
		case 3:
			exit (-1);
			break;
		}

		process_infix (infix, postfix);

		n = evaluatePostfix (postfix);

		printf ("Postfix expression: %s\n", postfix);

		printf ("Value: %d\n\n", n);

		printf ("Press any key to continue: ");

		system ("pause");

		system ("cls");
	}

	return (0);
}