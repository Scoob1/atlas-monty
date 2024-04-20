#include "monty.h"
#include <stdio.h>

/**
 * pint - prints value
 * @stack: pointer tto the top of the stack
 * @line_number: instructions appear
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
