#define _CRT_SECURE_NO_WARNINGS

//defines
#define LOAD 1
#define STORE 2
#define DISPLAY 3
#define INSERT 4
#define DELETE 5
#define EDIT 6
#define SORT 7
#define RATE 8
#define EXIT 9

#define ARTIST 0
#define ALBUM 1
#define SONG 2
#define GENRE 3
#define LENGTH 4
#define TIMES 5
#define RATING 6

//system includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//typedefs
typedef struct length
{
	int *minutes;
	int *seconds;
}Length;

typedef struct node
{
	char *artist;
	char *album;
	char *song;
	char *genre;
	Length length;
	int *times;
	int *rating;

	struct node *next;
	struct node *prev;
}Node;

//function prototypes
void Display (Node *Head);
void printListRec (Node *Head);
void searchDisplay (Node *Head);
void searchDisplay_rec (Node *Head, int field, char *search);

void load_list (Node **pHead);
void save_list (Node *pHead);
void save_list_rec (Node *pHead, FILE *output_file);

void sort_list (Node *pHead);
void bubble_sort (Node *pHead, int size, int field);

void insert (Node **pHead);

Node *makeNode (void);
char *makeString (void);
int *makeInt (void);