#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (!head)
		return;
	while ((*stack)->next)
		*stack = (*stack)->next;

	head->next = (*stack)->prev;
	(*stack)->prev = NULL;
	head->next->prev = head;
	head = head->next;
	head->next = NULL;
}
