#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define div stdlib_div
#include <stdlib.h>
#undef div
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *opcodeline, unsigned int linecounter, stack_t **firstnode);
void push(stack_t **head, unsigned int linecounter);
void pall(stack_t **head, unsigned int linecounter);
void free_stack(stack_t **firstnode);
void pint(stack_t **head, unsigned int linecounter);
void pop(stack_t **head, unsigned int linecounter);
void swap(stack_t **head, unsigned int linecounter);
void add(stack_t **head, unsigned int linecounter);
void nop(stack_t **head, unsigned int linecounter);
void sub(stack_t **head, unsigned int linecounter);
void div(stack_t **head, unsigned int linecounter);
void mul(stack_t **head, unsigned int linecounter);
void mod(stack_t **head, unsigned int linecounter);
void pchar(stack_t **head, unsigned int linecounter);

#endif
