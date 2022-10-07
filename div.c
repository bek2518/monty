#include "monty.h"

/**
 * div_op - This function divides the second top nodes of the stack by the top
 * @stack: The stack list
 * @line_number: The line number of the file
 * Return: The edited stack
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (head->next->n) / (head->n);
	head->next->n = result;
	head->prev = NULL;
	pop(stack, 0);
}
