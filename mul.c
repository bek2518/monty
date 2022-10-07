#include "monty.h"

/**
 * mul - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to new stack 
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (head->n) * (head->next->n);
	head->next->n = result;
	pop(stack, 0);
}
