#include "monty.h"
#include <ctype.h>

/**
 * push - adds an element to the stack
 * @head: double pointer to head of the stack to add to
 * @linecounter: counter to keep track of lines scanned
 * Return: none
*/

void push(stack_t **head, unsigned int linecounter)
{
	char *expectedint;
	stack_t *newnode;
	int i = 0;

	expectedint = strtok(NULL, " \t\n");
	if (expectedint == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecounter);
		exit(EXIT_FAILURE);
	}
	while (expectedint[i] != '\0')
	{
		if (expectedint[i] != '-' && !isdigit(expectedint[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", linecounter);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	newnode = (stack_t *)malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (expectedint != NULL)
		newnode->n = atoi(expectedint);
	newnode->next = *head;
	if (*head != NULL)
		(*head)->prev = newnode;
	newnode->prev = NULL;
	(*head) = newnode;
}

/**
 * pall - prints elements of a stack
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void pall(stack_t **head, unsigned int linecounter)
{
	stack_t *temp;
	(void)linecounter;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints top element of the stack
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void pint(stack_t **head, unsigned int linecounter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", linecounter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes top element of the stack
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void pop(stack_t **head, unsigned int linecounter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linecounter);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free (temp);
}

/**
 * swap - swaps top and last before top elements
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void swap(stack_t **head, unsigned int linecounter)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}


/**
 * add - adds last and last before top element 
 * and removes head assigning sum data to last before head
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void add(stack_t **head, unsigned int linecounter)
{
	int sum;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	temp = *head;
	(*head) = (*head)->next;
	(*head)->n = sum;
	free (temp);
}


/**
 * nop - doesn't do anything
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void nop(stack_t **head, unsigned int linecounter)
{
	(void)head;
	(void)linecounter;
}

/**
 * sub - subtracts last and last before top element 
 * and removes head assigning sum data to last before head
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void sub(stack_t **head, unsigned int linecounter)
{
	int subt;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	subt = (*head)->next->n - (*head)->n;
	temp = *head;
	(*head) = (*head)->next;
	(*head)->n = subt;
	free (temp);
}

/**
 * div - divides the second top element of the stack by the top element of the stack
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void div(stack_t **head, unsigned int linecounter)
{
	int divs;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linecounter);
		exit(EXIT_FAILURE);
	}
	divs = (*head)->next->n / (*head)->n;
	temp = *head;
	(*head) = (*head)->next;
	(*head)->n = divs;
	free (temp);
}


/**
 * mul - multiplies the second top element of the stack with the top element of the stack
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void mul(stack_t **head, unsigned int linecounter)
{
	int mult;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	mult = (*head)->next->n * (*head)->n;
	temp = *head;
	(*head) = (*head)->next;
	(*head)->n = mult;
	free (temp);
}
/**
 *mod - computes the rest of the division of the second top element of the stack by the top element of the stack.
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
*/
void mod(stack_t **head, unsigned int linecounter)
{
	int modu;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", linecounter);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linecounter);
		exit(EXIT_FAILURE);
	}
	modu = (*head)->next->n % (*head)->n;
	temp = *head;
	(*head) = (*head)->next;
	(*head)->n = modu;
	free (temp);
}

/**
 * pchar - prints char at top of stack using n as ascii code
 * @head: double pointer to head
 * @linecounter: number of line
 * Return: none
 */
void pchar(stack_t **head, unsigned int linecounter)
{
	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", linecounter);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", linecounter);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
