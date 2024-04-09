#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

#define DELIMITERS " \n\t\a\b"
#define MAX_LINE_LENGTH 80

void execute_instruction(stack_t **stack,
		char *line,
		unsigned int line_number);


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		execute_instruction(&stack, line, line_number);
		free(line);
		line = NULL;
		len = 0;
		free(line);
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

void execute_instruction(stack_t **stack,
		char *line,
		unsigned int line_number)
{
	char *opcode = strtok(line, DELIMITERS);

	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		char *arg = strtok(NULL, DELIMITERS);

		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		int value = atoi(arg);

		if (value == 0 && *arg != '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
}
