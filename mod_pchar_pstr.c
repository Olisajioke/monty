#include "monty.h"

/**
 * mod_operation - Computes the remainder of division of the second top element
 *              of the stack by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void mod_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop_operation(stack, line_number);
}

/**
 * pchar_operation - Prints the char at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void pchar_operation(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * pstr_operation - Prints the string starting from the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void pstr_operation(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL && temp->n != 0 &&
			(temp->n >= 0 && temp->n <= CHAR_VALUE_LIMIT))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
}
