#include "monty.h"

/**
 * add_operation - Adds the top two elements of the stack
 * @stack:      Pointer to the stack
 * @line_number: Line number in the input file
 */
void add_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_operation(stack, line_number);
}

/**
 * nop_operation - Doesn't perform any operation
 * @stack:       Pointer to the stack
 * @line_number: Line number in the input file
 */
void nop_operation(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number; /* These parameters are unused */
}

/**
 * sub_operation - Subtracts the top element of the stack from the
 * second top element
 * @stack:	Pointer to the stack
 * @line_number: Line number in the input file
 */
void sub_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_operation(stack, line_number);
}

/**
 * div_operation - Divides the second top
 * element of the stack by the top element
 * @stack:	Pointer to the stack
 * @line_number: Line number in the input file
 */
void div_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_operation(stack, line_number);
}

/**
 * mul_operation - Multiplies the second top
 * element of the stack with the top element
 * @stack:	Pointer to the stack
 * @line_number: Line number in the input file
 */
void mul_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop_operation(stack, line_number);
}
