#include "Header.h"


void init_stack (Node **node)
{
	*node = NULL;
}

void printStack (Node *Head)
{
	if (Head != NULL)
	{
		putchar (Head->data);

		printStack (Head->next);
	}
	else
	{
		putchar ('\n');
	}
}

Node *makeNode (char newData)
{
	Node *node = NULL;

	node = (Node *)malloc (sizeof (Node));

	if (node == NULL)
	{
		perror ("Node creation failed!\n");
		exit (-1);
	}

	node->data = newData;

	return (node);
}

int push (Node **Head, char data)
{
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode (data);

	if (pMem != NULL)
	{
		success = 1;

		pMem->next = *Head;
		*Head = pMem;
	}

	return success;
}

void pop (Node **Head)
{
	Node *pTemp = NULL;

	pTemp = *Head;

	if (pTemp != NULL)
	{
		*Head = (*Head)->next;
		free (pTemp);
	}
}

char peek (Node *Head)
{
	return (Head->data);
}

int precedence(char op1, char op2)
{
	if(op1 == '+'){ //Check precedence for +
		if(op2 == '-' || op2 == '+') //+ and - have equal precedence to +
			return 0;
		else //Any other viable operator has greater precedence
			return 1;
	}
	else if(op1 == '-'){ //Check precedence for -
		if(op2 == '+' || op2 == '-') //+ and - have equal precedence to -
			return 0;
		else //Any other viable operator has greater precedence
			return 1;
	}
	else if(op1 == '*'){ //Check precedence for *
		if(op2 == '-' || op2 == '+') //+ and - have lesser precedence to *
			return -1;
		else if(op2 == '/' || op2 == '%' || op2 == '*') //*, /, and % have equal precedence to *
			return 0;
		else //The ^ operator still has greater precedence
			return 1;
	}
	else if(op1 == '/'){ //Check precedence for /
		if(op2 == '-' || op2 == '+') //+ and - have lesser precedence to /
			return -1;
		else if(op2 == '*' || op2 == '%' || op2 == '/') //*, /, and % have equal precedence to /
			return 0;
		else //The ^ operator still has greater precedence
			return 1;
	}
	else if(op1 == '%'){ //Check precedence for %
		if(op2 == '-' || op2 == '+') //+ and - have lesser precedence to %
			return -1;
		else if(op2 == '*' || op2 == '/' || op2 == '%') //*, /, and % have equal precedence to %
			return 0;
		else //The ^ operator still has greater precedence
			return 1;
	}
	else{ //Check precedence for ^
		if(op2 == '^') //THe only operator with equal precedence to ^ is ^
			return 0;
		else //All other operators have lesser precedence
			return -1;
	}
}

void process_infix (char *infix, char *postfix)
{
	Node *infix_stack = NULL;

	char ch = '\0', element = '\0';

	int i = 0,
		length = strlen (infix);

	init_stack (&infix_stack);

	if (!push (&infix_stack, '('))
	{
		printf ("Push Failed!\n");
		exit (-1);
	}
	strcat (infix, ")");

	while (*infix != '\0')
	{
		if (isalnum (*infix))
		{
			postfix [i] = *infix;
			i++;
		}
		else if (*infix == '(')
		{
			if (!push (&infix_stack, *infix))
			{
				printf ("Push Failed!\n");
				exit (-1);
			}
		}
		else if (isOperator (*infix))
		{
			if (isOperator (peek (infix_stack)))
			{
				if (infix_stack == NULL)
				{
					if (!push (&infix_stack, *infix))
					{
						printf ("Push Failed!\n");
						exit (-1);
					}
				}
				else
				{
					if (infix_stack)
					{
						if (precedence (*infix, peek (infix_stack)) >= 0)
						{
							while (!isEmpty (infix_stack) && precedence (*infix, peek (infix_stack)) >= 0)
							{
								if (peek (infix_stack) == '(')
								{
									pop (&infix_stack);
								}
								else
								{
									postfix [i] = peek (infix_stack);
									pop (&infix_stack);
									i++;
								}
							}
							if (!push (&infix_stack, *infix))
							{
								printf ("Push Failed!\n");
								exit (-1);
							}
						}
						else
						{
							if (!push (&infix_stack, *infix))
							{
								printf ("Push Failed!\n");
								exit (-1);
							}
						}
					}
					else
					{
						if (!push (&infix_stack, *infix))
						{
							printf ("Push Failed!\n");
							exit (-1);
						}
					}
				}
			}
			else
			{
				if (!push (&infix_stack, *infix))
				{
					printf ("Push Failed!\n");
					exit (-1);
				}
			}
		}
		else if (*infix == ')')
		{
			while (!isEmpty (infix_stack) && peek (infix_stack) != '(')
			{
				postfix [i] = peek (infix_stack);
				pop (&infix_stack);
				i++;
			}
			pop (&infix_stack);
		}
		infix++;
	}
	postfix [i] = '\0';
}

int isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
		return 1;
	return 0;
}

int isEmpty (Node *head)
{
	if(head == NULL)
		return 1;
	return 0;
}   

int evaluatePostfix (char *postfix)
{
	int n = 0, x = 0, y = 0;

	Node *Head = NULL;
	init_stack (&Head);

	while (*postfix != '\0')
	{
		if (isalnum (*postfix))
		{
			if (!push (&Head, *postfix - '0'))
			{
				printf ("Push Failed!\n");
				exit (-1);
			}
		}
		else if (isOperator (*postfix))
		{
			x = peek (Head);
			pop (&Head);
			y = peek (Head);
			pop (&Head);

			if (!push (&Head, calculate (y, x, *postfix)))
			{
				printf ("Push Failed!\n");
				exit (-1);
			}
		}
		postfix ++;
	}
	n = peek (Head);
	pop (&Head);

	return (n);
}

int calculate(int op1, int op2, char operator1)
{
	if(operator1 == '+')
		return op1 + op2;
	else if(operator1 == '-')
		return op1 - op2;
	else if(operator1 == '*')
		return op1  * op2;
	else if(operator1 == '/')
		return op1 / op2;
	else if(operator1 == '%')
		return op1 % op2;
	else
		return (int)pow((double)op1, (double)op2);
}