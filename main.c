#include "monty.h"

int arg = 0;

/**
 * main - an Interpreter program
 * @argc: count of arguments
 * @argv: arguments
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char current_line[BUFFER_SIZE];
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(current_line, sizeof(current_line), file) != NULL)
	{
		get_opcode_arg(&stack, current_line, line_number);
		line_number++;
	}
	free(stack);
	fclose(file);
	return (0);
}

