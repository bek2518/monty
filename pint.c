#include "monty.h"

/**
 * pint - Prints the integer of the head
 * @stack: pointer to the stack
 * @line number: line number
 * Return: pointer to the stack
 */
stack_t *pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
	return (*stack);
}
