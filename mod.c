#include "monty.h"

/**
 * mod - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to new stack 
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int modulus = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	modulus = (head->next->n) % (head->n);
	head->next->n = modulus;
	pop(stack, 0);
}
