#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *last, *temp;

	if (stack == NULL || (*stack) == NULL || ((*stack)->next) == NULL)
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}
