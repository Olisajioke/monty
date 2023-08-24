#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

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

extern int arg;
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

void get_opcode_arg(stack_t **stack,
char *current_line, unsigned int line_number);
void get_arguments(stack_t **stack, char *opcode, unsigned int line_number);
void process_opcode(stack_t **stack, char *opcode, char *argument,
		unsigned int line_number);
void push_operation(stack_t **stack, unsigned int line_number);
void pall_operation(stack_t **stack, unsigned int line_number);
void pint_operation(stack_t **stack, unsigned int line_number);
void pop_operation(stack_t **stack, unsigned int line_number);
void swap_operation(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H */
