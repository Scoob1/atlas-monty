#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
