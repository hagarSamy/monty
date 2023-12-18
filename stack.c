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
		fprintf(stderr, "L%d: useage: push integer\n", linecounter);
		exit(EXIT_FAILURE);
	}
	while (expectedint[i] != '\0')
	{
		if (expectedint[i] != '-' && !isdigit(expectedint[i]))
		{
			fprintf(stderr, "L%d: useage: push integer\n", linecounter);
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
