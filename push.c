#include "monty.h"

/**
 * push - pushes an elemet to the stack
 * @stack: pointer to the stack (head)
 * Return: address of new node
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t * new_node = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit (EXIT_FAILURE);
	}
	new_node->n = arg.arg;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
