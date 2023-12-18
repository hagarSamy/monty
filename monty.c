#define _GNU_SOURCE
#include "monty.h"

/**
 * main -entry point
 * @argc: number of arguments
 * @argv: the value strings of the args
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
	FILE *fileptr;
	char *line = NULL;
	size_t charsread, len = 0;
	int ctr = 0;
	stack_t *firstnode = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((charsread = getline(&line, &len, fileptr)) != (size_t) -1)
	{
		ctr++;
		if (execute(line, ctr, &firstnode) == 0)
			continue;
	}
	free_stack(&firstnode);
	free(line);
	fclose(fileptr);
	exit(EXIT_SUCCESS);
	return (0);
}
