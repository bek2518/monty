#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: address of the first node
 */
void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head;
	int temp;

	head = *stack;

	if (head != NULL && head->next != NULL)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
