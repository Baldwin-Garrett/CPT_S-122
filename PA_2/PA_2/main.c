#include "Header.h"

#ifndef HEADER_H
#define HEADER_H


int main (void)
{
	static int option;
	
	Node *Head = NULL;

	printf ("Welcome to Garrett J. Baldwin's digital music manager!\n");

	while (1)
	{ 
		system ("cls");
		printf ("What would you like to do?\n");
		printf ("1. Load\n");
		printf ("2. Store\n");
		printf ("3. Display\n");
		printf ("4. Insert\n");
		printf ("5. Delete\n");
		printf ("6. Edit\n");
		printf ("7. Sort\n");
		printf ("8. Rate\n");
		printf ("9. Exit\n");
		printf ("Enter your choice (1,2,3,4,5,6,7,8,9): ");

		do
		{
			scanf ("%d", &option);
		} while ((option < 1) || (option > 9));

		system ("cls");

		switch (option)
		{
		case LOAD: 
			load_list (&Head);
			break;
		case STORE: 
			save_list (Head);
			break;
		case DISPLAY: 
			Display (Head);
			break;
		case INSERT: 
			insert (&Head);
			break;
		case DELETE: 

			break;
		case EDIT: 

			break;
		case SORT: 
			sort_list (Head);
			break;
		case RATE: 

			break;
		case EXIT:
			save_list (Head);
			exit (-1);
		}
	}

	return (0);
}

#endif