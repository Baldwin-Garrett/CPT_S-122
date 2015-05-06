#include "Header.h"

void Display (Node *Head)
{
	int option = 0;
	printf ("What would you like to display?\n");
	printf ("1. All records\n");
	printf ("2. Search and display\n");
	printf ("Enter your choice (1,2): ");

	do
	{
		scanf ("%d", &option);
	} while ((option < 1) || (option > 2));

	system ("cls");

	switch (option)
	{
	case 1:
		printListRec (Head);
		break;
	case 2:
		searchDisplay (Head);
		break;
	}
	system ("pause");
}

void searchDisplay (Node *Head)
{
	int option = 0;

	char search [25];

	printf ("What would you like your search field to be?\n");
	printf ("1. Artist\n");
	printf ("2. Album\n");
	printf ("3. Song\n");
	printf ("4. Genre\n");

	printf ("Enter your choice (1,2,3,4): ");

	do
	{
		scanf ("%d", &option);
	} while ((option < 1) || (option > 4));

	printf ("Enter your search: \n");
	scanf ("%s", search);

	searchDisplay_rec (Head, option, search);
}

void searchDisplay_rec (Node *Head, int field, char *search)
{
	int found = 0;

	if (Head != NULL)
	{
		switch (field)
		{
		case ARTIST + 1:
			if (strcmp (search, Head->artist) == 0)
			{
				found = 1;
			}
			break;

		case ALBUM + 1:
			if (strcmp (search, Head->album) == 0)
			{
				found = 1;
			}
			break;

		case SONG + 1:
			if (strcmp (search, Head->song) == 0)
			{
				found = 1;
			}
			break;

		case GENRE + 1:
			if (strcmp (search, Head->genre) == 0)
			{
				found = 1;
			}
			break;
		}
		if (found == 0)
		{
			searchDisplay_rec (Head->next, field, search);
		}
		else
		{
			printf ("\n\nArtist: %s\n", Head->artist);
			printf ("Album: %s\n", Head->album);
			printf ("Song: %s\n", Head->song);
			printf ("Genre: %s\n", Head->genre);
			printf ("Minutes runtime: %d\nSeconds runtime: %d\n", *Head->length.minutes, *Head->length.seconds);
			printf ("Number of times listned: %d\n", *Head->times);
			printf ("Rating: %d\n\n", *Head->rating);
		}
	}
	else
	{
		printf ("Article not found!\n");
	}
}

void printListRec (Node *Head)
{
	if (Head != NULL)
	{
		//print all info in CONTACT
		printf ("Artist: %s\n", Head->artist);
		printf ("Album: %s\n", Head->album);
		printf ("Song: %s\n", Head->song);
		printf ("Genre: %s\n", Head->genre);
		printf ("Minutes runtime: %d\nSeconds runtime: %d\n", *Head->length.minutes, *Head->length.seconds);
		printf ("Number of times listned: %d\n", *Head->times);
		printf ("Rating: %d\n\n", *Head->rating);

		//increment list
		printListRec (Head->next);
	}
	else
	{
		putchar ('\n');
	}
}

void save_list (Node *pHead)
{
	FILE *output_file = NULL;

	output_file = fopen ("Songs.txt", "w");
	if (output_file == NULL)
	{
		printf ("Output file failed to open!\n");
		exit (-1);
	}

	save_list_rec (pHead, output_file);
}

void save_list_rec (Node *pHead, FILE *output_file)
{
	if (pHead != NULL)
	{
		fprintf (output_file, "%s\n", pHead->artist);
		fprintf (output_file, "%s\n", pHead->album);
		fprintf (output_file, "%s\n", pHead->song);
		fprintf (output_file, "%s\n", pHead->genre);
		fprintf (output_file, "%d\n", *pHead->length.minutes);
		fprintf (output_file, "%d\n", *pHead->length.seconds);
		fprintf (output_file, "%d\n", *pHead->times);d
		fprintf (output_file, "%d\n", *pHead->rating);

		save_list_rec (pHead->next, output_file);
	}
	else
	{
		fclose (output_file);
	}
}

void load_list (Node **pHead)
{
	FILE *input_file = NULL;

	Node *pMem = NULL, *pCur = NULL;

	int data_type = 0;

	char *pArtist = NULL,
		*pAlbum = NULL,
		*pSong = NULL,
		*pGenre = NULL;

	int *pSeconds = NULL,
		*pMinutes = NULL,
		*pTimes = NULL,
		*pRating = NULL;

	//init pCur to pHead
	pCur = *(pHead);

	//open file
	input_file = fopen ("Songs.txt", "r");
	if (input_file == NULL)
	{
		printf ("File wasn't found!\n");
		exit (-1);
	}

	//input from file

	while (!feof (input_file))
	{

		//fill info
		switch (data_type)
		{
		case ARTIST:
			pArtist = makeString ();
			fscanf (input_file, "%s", pArtist);
			break;

		case ALBUM:
			pAlbum = makeString ();
			fscanf (input_file, "%s", pAlbum);
			break;

		case SONG:
			pSong = makeString ();
			fscanf (input_file, "%s", pSong);
			break;

		case GENRE:
			pGenre = makeString ();
			fscanf (input_file, "%s", pGenre);
			break;

		case LENGTH:
			pMinutes = makeInt ();
			fscanf (input_file, "%d", pMinutes);

			pSeconds = makeInt ();
			fscanf (input_file, "%d", pSeconds);
			break;

		case TIMES:
			pTimes = makeInt ();
			fscanf (input_file, "%d", pTimes);
			break;

		case RATING:
			pRating = makeInt ();
			fscanf (input_file, "%d", pRating);
			break;

		default:
			printf ("\nERROR\n");
			exit (-1);
			break;
		}
		//reset for the next data point
		if (data_type == RATING)
		{
			//reset data type
			data_type = ARTIST;

			//make new node
			pMem = makeNode ();

			//copy data to node
			pMem->album = pAlbum;
			pMem->artist = pArtist;
			pMem->genre = pGenre;
			pMem->length.minutes = pMinutes;
			pMem->length.seconds = pSeconds;
			pMem->rating = pRating;
			pMem->song = pSong;
			pMem->times = pTimes;

			//insert node into list
			//list is empty
			if (*pHead == NULL)
			{
				*pHead = pMem;
			}

			//list has only one node
			else if (((*pHead)->next) == NULL)
			{
				(*pHead)->next = pMem;
				pCur = pMem;
				pMem->prev = *pHead;

			}
			//list is not empty
			else
			{
				pCur->next = pMem;
				pMem->prev = pCur;
			}

		}
		else
		{
			data_type++;
		}
	}

	//close file
	fclose (input_file);
}

Node *makeNode (void)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc (sizeof (Node));
	pMem->prev = NULL;
	pMem->next = NULL;

	return (pMem);
}

char *makeString (void)
{
	char *pointer = NULL;
	pointer = (char *)malloc ((sizeof (char)) * 25);
	return (pointer);
}

int *makeInt (void)
{
	int *pointer = NULL;
	pointer = (int *)malloc (sizeof (int));
	return (pointer);
}

void sort_list (Node *pHead)
{
	int option = 0, size = 0;

	Node *cur = pHead;

	getchar ();

	printf ("What field would you like to sort by?\n");
	printf ("1. Artist\n");
	printf ("2. Genre\n");
	printf ("3. Rating\n");

	do
	{
		scanf ("%d", &option);
	} while ((option < 1) || (option > 3));

	for (size = 1; cur->next != NULL; size++)
	{
		cur = cur->next;
	}


	bubble_sort (pHead, size, option);
}

void bubble_sort (Node *pHead, int size, int field)
{
	int i = 0,
		passes = 1;

	Node *cur = NULL;

	char *str_cur = NULL, *str_next = NULL,
		*temp = NULL;

	int *temp_i = NULL;

	cur = pHead;

	for (passes = 1; passes >= 100; passes++)
	{
		//reset cur to head
		while (pHead != cur)
		{
			cur = cur->prev;
		}

		while (cur->next != NULL)
		{
			switch (field)
			{
			case 1:
				str_cur = cur->album;
				str_next = cur->next->album;
				break;

			case 2:
				str_cur = cur->genre;
				str_next = cur->next->genre;
				break;

			case 3:
				itoa (*cur->rating, str_cur, 10);
				itoa (*cur->next->rating, str_next, 10);
				break;
			}

			if (strcmp (str_cur, str_next) > 0)
			{
				temp = cur->album;
				cur->album = cur->next->album;
				cur->next->album = temp;

				temp = cur->artist;
				cur->artist = cur->next->artist;
				cur->next->artist = temp;

				temp = cur->song;
				cur->song = cur->next->song;
				cur->next->song = temp;

				temp = cur->genre;
				cur->genre = cur->next->genre;
				cur->next->genre = temp;

				temp_i = cur->rating;
				cur->rating = cur->next->rating;
				cur->next->rating = temp_i;

				temp_i = cur->length.minutes;
				cur->length.minutes = cur->next->length.minutes;
				cur->next->length.minutes = temp_i;

				temp_i = cur->length.seconds;
				cur->length.seconds = cur->next->length.seconds;
				cur->next->length.seconds = temp_i;
			}
			cur = cur->next;
		}
	}
}

void insert (Node **pHead)
{
	char *buffer = NULL;
	Node *node = NULL;
	int *n = 0;

	node = makeNode ();

	printf ("Enter article information: \n");
	printf ("Enter artist: ");
	buffer = makeString ();
	scanf ("%s", buffer);
	node->artist = buffer;

	printf ("Enter song: ");
	buffer = makeString ();
	scanf ("%s", buffer);
	node->song = buffer;

	printf ("Enter album: ");
	buffer = makeString ();
	scanf ("%s", buffer);
	node->album = buffer;

	printf ("Enter genre: ");
	buffer = makeString ();
	scanf ("%s", buffer);
	node->genre = buffer;

	printf ("Enter times: ");
	n = makeInt ();
	scanf ("%d", n);
	node->times = n;

	printf ("Enter rating: ");
	n = makeInt ();
	scanf ("%d", n);
	node->rating = n;

	printf ("Enter minutes: ");
	n = makeInt ();
	scanf ("%d", n);
	node->length.minutes = n;

	printf ("Enter seconds: ");
	n = makeInt ();
	scanf ("%d", n);
	node->length.seconds = n;

	node->next = *pHead;
	*pHead = node;

}