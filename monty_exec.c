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

void execute(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"null", NULL},
	};
	while (op[i].opcode != NULL)
	{
		if (strcmp(op[i].opcode, token[i]) == 0)
		{
			op[i].f(stack, line_num);
			break;
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{
		free_dp(NULL, stack);
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num,
				token[i]);
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
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		usage_error(0);
		return;
	}

	if (token[1] == NULL)
	{
		f_errors(0, line_num);
		return;
	}

	for (i = 0; token[1][i]; i++)
	{
		if (token[1][i] == '-' && i == 0)
			continue;
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_dp(token, stack);
			f_errors(0, line_num);
			return;
		}
	}
	new->n = atoi(token[1]);

	tmp = (*stack)->next;
	new->prev = *stack;
	new->next = tmp;
	if (tmp)
		tmp->prev = new;
	(*stack)->next = new;
}

/**
 * monty_pall - A function that prints the values of the stack_t.
 * @stack: The pointer to the top of a stack_t.
 */
void monty_pall(stack_t **stack)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
