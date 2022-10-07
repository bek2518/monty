#include "monty.h"

/**
 * main - interprets bytecode
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int token = 1;

int main(int argc, char **argv)
{
	const char *filename;
	char *string = NULL, *opcode, *num_str;
	size_t nbytes = 1;
	FILE *file;
	unsigned int line_number = 0, i = 0;
	ssize_t read_c = 0;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Erroe: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (read_c != EOF)
	{
		token = 1;
		i = 0;
		if (string != NULL)
			free(string);
		string = NULL;

		read_c = getline(&string, &nbytes, file);

		if (read_c == -1)
		{
			free(string);
			if (stack != NULL)
				free_stack(&stack);
			fclose(file);
			return (0);
		}
		line_number++;

		if (read_c == 0)
			continue;
		if (read_c == 1)
			continue;
		opcode = strtok(string, " \n");
		if (opcode == NULL)
			continue;
		if (opcode[0] == '#')
		{
			nop(&stack, line_number);
			continue;
		}

		if (strcmp(opcode, "push") == 0)
		{
			num_str = strtok(NULL, " \n");
			if (num_str == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(string);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (num_str[0] == '-' && num_str[1] != '\0')
				i = 1;
			for (; num_str[i] != '\0'; i++)
			{
				if (isdigit(num_str[i]) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(string);
					free_stack(&stack);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
			token = atoi(num_str);
		}
		op_func(opcode, &stack, line_number)(&stack, line_number);
	}
	free(string);
	free_stack(&stack);
	fclose(file);
	return (0);
}
