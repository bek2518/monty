#include "monty.h"

/**
 * pchar - prints char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line_number
 * Return: pointer to the stack
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0|| head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(head->n);
	putchar('\n');
}
