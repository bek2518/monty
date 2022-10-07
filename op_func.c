#include "monty.h"

/**
 * op_func - selects correct opcode to run
 * @s: operation passed as argument
 * @stack: pointer to the stack
 * @line_number: line number in the file
 * Return: Pointer to the opcode
 */
void (*op_func(char *opc))(stack_t **stack, unsigned int line_number)
{
        instruction_t instruct[] = {
                {"push", push},
                {"pall", pall},
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"queue", queue},
                {"stack", stack},
                {"add", add},
                {"nop", nop},
                {"sub", sub},
                {"mul", mul},
                {"div", div},
                {"mod", mod},
                {"pchar", pchar},
                {"pstr", pstr},
                {"rotl", rotl},
                {"rotr", rotr},
                {NULL, NULL}
        };
        int i;

        for (i = 0; instruct[i].opcode; i++)
        {
                if (strcmp(instruct[i].opcode, opc) == 0)
                        break;
        }

        return (instruct[i].f);
}

