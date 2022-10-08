#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: pointer to stack
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack)
		*stack = (*stack)->prev;
}
