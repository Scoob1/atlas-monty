#include "monty.h"
#include <stdio.h>

/**
 * pall- prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where instruction appears
 * Return: Nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
