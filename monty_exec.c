/*
 * File name:   monty_main.c
 * Authors:     Robinson Montes
 *              Luis Miguel Vargas
 */

#include "monty.h"

/**
 * execute - Function that checks for a command "opcode" and execute the
 * function if there's a match.
 * @token: Tokane containing the opcode to execute.
 * @stack: Doubly linked list representation of a stack.
 * @line_num: Line number where the opcode was found.
 *
 * Return: Nothing.
 */

void execute(char **token, stack_t *stack, int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"null", NULL},
	};
	while (op[i].opcode != NULL)
	{
		if (*(op[i].opcode) == *token)
		{
			op[i].f(&stack, line_num)
				break;
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token);
		exit(EXIT_FAILURE);
	}
}
