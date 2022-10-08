#include "monty.h"

/**
 * op_func - selects correct opcode to run
 * @line: contents of line and number
 * @meta: contains all allocated memory
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void (*op_func(line_t line, meta_t *meta))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", push_stack},
		{"queue", push_queue},
		{NULL, NULL}
	};

	if (comment_check(line))
		return (nop);

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line, meta, ops[i].opcode);
			if (arg.flag == 1 &&
			strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (qpush);
			}
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free(line.content);
	free(meta->buf);
	free_stack(&(meta->stack));
	fclose(meta->file);
	free(meta);
	exit(EXIT_FAILURE);
}
