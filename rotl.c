#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
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

	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}
