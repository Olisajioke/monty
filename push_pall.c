#include "monty.h"

/**
 * push_operation - function that runs the push operation
 * @stack: stack structure
 * @line_number: current line number
 *
 * Return: void
*/
void push_operation(stack_t **stack, __attribute((unused))
unsigned int line_number)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall_operation - function that runs the pall (print) operation
 * @stack: stack structure
 * @line_number: current line number
 *
 * Return: void
*/
void pall_operation(stack_t **stack, __attribute((unused))
unsigned int line_number)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * pint_operation - Prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void pint_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_operation - Removes the top element from the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void pop_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap_operation - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the input file
 */
void swap_operation(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
