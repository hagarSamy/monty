#include "monty.h"
/**
* free_stack - frees all the nodes of a stack
* @firstnode: double pointer to top
* Return: none
*/
void free_stack(stack_t **firstnode)
{
	stack_t *current = *firstnode;
	stack_t *tmp = NULL; /* Initialize tmp to NULL */

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*firstnode = NULL; /*Set the top of the stack to NULL */
}
