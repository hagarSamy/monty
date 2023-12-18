#include "monty.h"

/**
 * execute - executes an opcode
 * @opcodeline: a string holding the opcode
 * @linecounter: line numebr indicator
 * @firstnode: double pinter to top of the stack
 * Return: 1 on success and 0 on failure
*/

int execute(char *opcodeline, unsigned int linecounter, stack_t **firstnode)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	char *realopcode;
	int i = 0;
	int found = 0;

	realopcode = strtok(opcodeline, " \t\n");
	if (!realopcode || *realopcode == '#')
		return (0);
	while (opcodes[i].opcode != NULL && realopcode != NULL)
	{
		if (strcmp(realopcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(firstnode, linecounter);
			found = 1;
			break;
		}
		i++;
	}
	if (found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", linecounter, realopcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}
