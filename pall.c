#include "monty.h"

/**
 * pall - prints all values on the stack starting
 * from top of the stack
 * @stack: pointer to the stack
 * Return: Address of the first node
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

