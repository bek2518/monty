#include "monty.h"

/**
 * pint - Prints the integer of the head
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}
