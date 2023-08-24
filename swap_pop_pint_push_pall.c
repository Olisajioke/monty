#include "monty.h"

/**
 * push_operation - Pushes an element to the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void push_operation(stack_t **stack, unsigned int line_number)
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
		{
			(*stack)->prev = new_node;
		}
		*stack = new_node;
}

/**
 * pall_operation - Prints all elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void pall_operation(stack_t **stack, unsigned int line_number)
{
		stack_t *stack_val;

		stack_val = *stack;

	while (stack_val)
	{
		printf("%d\n", stack_val->n);
		stack_val = stack_val->next;
	}
}

/**
 * pint_operation - Prints the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
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
 * pop_operation - Removes the top element from the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
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
 * swap_operation - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void swap_operation(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
