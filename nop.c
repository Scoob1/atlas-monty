#include "monty.h"

/**
 * _nop - doesn't do anything
 * @stack: the stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
