#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number - line number
 * Return: pointer to the stack
 */
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(head);
	if (*stack)
		(*stack)->prev = NULL;
}
