#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	int i, j;

	if (stack == NULL || *stack == NULL)
		nop(stack, line_number);

	temp = *stack;
	i = (*stack)->n;

	while (temp)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	j = temp->n;
	(*stack)->n = j;
	temp->n = i;

}
