#define _CRT_SECURE_NO_WARNINGS

//test cases
#define CASE_1 "9*(5-4+2/6)"


//system includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	char data;
	struct node *next;
}Node;

void process_infix (char *infix, char *postfix);

void init_stack (Node **node);
int isEmpty (Node *head);
void printStack (Node *Head);
int push (Node **Head, char data);
Node *makeNode (char newData);
void pop (Node **Head);
char peek (Node *Head);

int precedence (char op1, char op2);
int isOperator (char c);
int calculate(int op1, int op2, char operator1);

int evaluatePostfix (char *postfix);