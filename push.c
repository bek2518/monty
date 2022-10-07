#include "monty.h"

/**
 * push - pushes an elemet to the stack
 * @stack: pointer to the stack (head)
 * Return: address of new node
 */

stack_t *push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t * new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit (EXIT_FAILURE);
	}
	new_node->n = token;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}

/**
 * pall - prints all values on the stack starting
 * from top of the stack
 * @stack: pointer to the stack
 * Return: Address of the first node
 */

stack_t *pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
	{
		return (NULL);
	}
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	return (*stack);
}
