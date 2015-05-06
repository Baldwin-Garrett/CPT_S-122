#include "Header.h"

int getExpressTime (void)
{
	int t = 0;

	t = rand () % 5 + 1;

	return t;
}

int getServiceTime (void)
{
	int t = 0;

	t = rand () & 5 + 3;

	return t;
}

Node *makeNode (int customer_id, int serviceTime, int totalTime)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc (sizeof (Node));

	if (pMem == NULL)
	{
		perror ("Node creation failed!\n");
		exit (-1);
	}

	pMem->customer_id = customer_id;
	pMem->serviceTime = serviceTime;
	pMem->totalTime = totalTime;

	pMem->pNext = NULL;

	return pMem;
}

void init_queue (Queue *pQ)
{
	pQ->pHead = NULL;
	pQ->pTail = NULL;
}

void enqueue (Queue *pQ, int customer_id, int serviceTime)
{
	Node *pMem = NULL;

	int totalTime = 0;
	if (pQ->pTail != NULL)
	{
		totalTime = pQ->pTail->totalTime + serviceTime;
	}
	//empty line
	else
	{
		totalTime = serviceTime;
	}

	pMem = makeNode (customer_id, serviceTime, totalTime);

	if (pQ->pHead == NULL)
	{
		pQ->pHead = pMem;
		pQ->pTail = pMem;
	}
	else
	{
		pQ->pTail->pNext = pMem;
		pQ->pTail = pMem;
	}
}

void dequeue (Queue *pQ)
{
	Node *pTemp = NULL;

	if (pQ->pHead != NULL)
	{
		if (pQ->pTail != pQ->pHead)
		{
			Node *temp = NULL;
			temp = pQ->pHead;
			pQ->pHead = pQ->pHead->pNext;
			free (temp);
		}
		//only one node in queue
		else
		{
			free (pQ->pHead);
			pQ->pHead = NULL;
			pQ->pTail = NULL;
		}
	}
}

void printQueue (Queue *pQ)
{
	printQueue_rec (pQ->pHead);
}

void printQueue_rec (Node *Head)
{
	if (Head != NULL)
	{
		printf ("ID: %d\n", Head->customer_id);
		printf ("Service Time: %d\n", Head->serviceTime);
		printf ("Total Time: %d\n", Head->totalTime);

		printQueue_rec (Head->pNext);
	}
	else
	{
		putchar ('\n');
	}
}