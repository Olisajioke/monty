#include "monty.h"

/**
 * push_operation - function that runs the push operation
 * @stack: stack structure
 * @line_number: current line number
 *
 * Return: void
*/
void push_operation(stack_t **stack, __attribute((unused)) unsigned int line_number)
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
void pall_operation(stack_t **stack, __attribute((unused)) unsigned int line_number)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
