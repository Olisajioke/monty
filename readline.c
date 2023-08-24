#include "monty.h"

/**
 * get_opcode_arg - Parses the opcode and arguments from a line of input.
 * @stack:    Pointer to the stack.
 * @current_line: The current line of input.
 * @line_number:   The current line number.
 */
void get_opcode_arg(stack_t **stack,
char *current_line, unsigned int line_number)
{
	char *opcode = strtok(current_line, " \t$\n");

	if (opcode != NULL)
	{
		while (*opcode == ' ' || *opcode == '\t')
			opcode++;
		get_arguments(stack, opcode, line_number);
	}
}

/**
 * get_arguments - Parses the arguments from the opcode line.
 * @stack:    Pointer to the stack.
 * @opcode:   The opcode to be processed.
 * @line_number:   The current line number.
 */
void get_arguments(stack_t **stack, char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		char *argument = strtok(NULL, " \t$\n");

		if (argument != NULL)
		{
			char *end = argument + strlen(argument) - 1;

			while (*end == ' ' || *end == '\t' || *end == '\n')
			{
				*end = '\0';
				end--;
			}
			if (*argument == '0')
				arg = atoi(argument);
			else
			{
				char *endptr;
				long val = strtol(argument, &endptr, 10);

				if (*endptr != '\0')
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				else
					arg = (int) val;
			}
			process_opcode(stack, opcode, argument, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
		process_opcode(stack, opcode, NULL, line_number);
}

/**
 * process_opcode - Executes the appropriate operation based on opcode.
 * @stack:    Pointer to the stack.
 * @argument: argument to push
 * @opcode:   The opcode to be processed.
 * @line_number:   The current line number.
 *
 * Return: void
 */
void process_opcode(stack_t **stack,
char *opcode,  __attribute((unused)) char *argument, unsigned int line_number)
{
	instruction_t operations[] = {
		{"push", push_operation},
		{"pall", pall_operation},
		{"pint", pint_operation},
		{"pop", pop_operation},
		{"swap", swap_operation},
	};
	size_t i = 0;
	int found_opcode = 0;
	size_t num_of_operations = sizeof(operations) / sizeof(instruction_t);

	while (i < num_of_operations)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line_number);
			i++;
			found_opcode++;
			break;
		}
		i++;
	}
	if (!found_opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
