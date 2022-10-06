#include "monty.h"

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

