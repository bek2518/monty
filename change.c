#include "monty.h"

/**
 * push_stack - changes mode of push to stack
 * @stack: pinter to stack
 * @line_number: line number
 */
void push_stack(stack_t **stack __attribute__ ((unused)), unsigned int line_number __attribute__ ((unused)))
{
	arg.flag = 0;
}

/**
 * push_queue - changes mode of push to stack
 * @stack: pinter to stack
 * @line_number: line number
 */
void push_queue(stack_t **stack __attribute__ ((unused)), unsigned int line_number __attribute__ ((unused)))
{
        arg.flag = 1;
}

