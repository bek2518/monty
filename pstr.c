#include "monty.h"


/**
 * pstr - prints string starting at the top
 * @stack: pointer to the stack
 * @line_number: line_number
 * Return: pointer to stack
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		if (head->n < 32 || head->n > 127)
			break;
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');
}
