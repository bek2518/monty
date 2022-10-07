#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
stack_t *rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (!head)
		head = head->next;
	head->prev->next = NULL;
	head->next = *stack;
	head->prev = NULL;
	(*stack)->prev = head;
	return (*stack);
}
