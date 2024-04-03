#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: line number in the monty bytecode file.
 */

void push(stack_t **stack, insigned int line_number)
{
	char *argument = strtok(NULL, " \n");
	int num;

	if (!argument)
	{
		fprintf(stderr,
