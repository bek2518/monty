#include "monty.h"

/**
 * op_func - selects correct opcode to run
 * @s: operation passed as argument
 * @stack: pointer to the stack
 * @line_number: line number in the file
 * Return: Pointer to the opcode
 */
stack_t *(*op_func(char *s, stack_t **stack, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall}
	};
	char *opcode;
	int i = 0;

	while (i < 2)
	{
		opcode = (ops[i].opcode);
		if (strcmp(s, opcode) == 0)
		{
			return (*ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
	free(stack);
	exit(EXIT_FAILURE);
}
