#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to new stack
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (head->n) + (head->next->n);
	head->next->n = sum;
	pop(stack, 0);
}
