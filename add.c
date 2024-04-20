#include "monty.h"
#include <stdio.h>

/**
 * add - adds to the top two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: where instructions appear
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
