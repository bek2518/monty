#include "monty.h"

/**
 * sub - subtracts the top two nodes of stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to new stack
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int difference;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	difference = (head->next->n) - (head->n);
	head->next->n = difference;
	head = head->next;
	head->prev = NULL;
	pop(stack, 0);
}

