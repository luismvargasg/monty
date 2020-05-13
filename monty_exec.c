/*
 * File name:   monty_exec.c
 * Authors:     Luis Miguel Vargas
 *              Robinson Montes
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

void execute(char **token, stack_t *stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
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

/**
  * monty_push - A function that pushes an element to stack.
  * @stack: The pointer to the stck struct.
  * @token: The pointer to command.
  * @line_num: The number of the line.
  * Return: Nothing.
  */
void monty_push(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *temp = NULL;
	int i = 0;

	while (token[1][i++])
	{
		if (token[1][i] <= '0' || token[1][i] >= '9')
		{
			free_dp(token, stack);
			f_error(0);
		}
	}
	temp->prev = NULL;
	temp->n = atoi(token[1]);
	if (stack || *stack)
		temp->next = NULL;
	else
	{
		temp->next = *stack;
		(*stack)->prev = temp;
	}
	free_dp(token, NULL);
}
