#define _CRT_SECURE_NO_WARNINGS

//stystem defines


//system includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//typedefs
typedef struct node
{
	int customer_id;
	int serviceTime;
	int totalTime;

	struct node *pNext;
}Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
}Queue;

//queue functions
Node *makeNode (int customer_id, int serviceTime, int totalTime);
void init_queue (Queue *pQ);
void enqueue (Queue *pQ, int customer_id, int serviceTime);
void dequeue (Queue *pQ);
void printQueue (Queue *pQ);
void printQueue_rec (Node *Head);

int getExpressTime (void);
int getServiceTime (void);