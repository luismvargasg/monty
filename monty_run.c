/*
 * File name:	monty_run.c
 * Authors:	Luis Miguel Vargas
 *		Robinson Montes
 */

#include "monty.h"

/**
 * monty_run - A function that runs a Monty bytecodes script.
 * @fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
void monty_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token;
	size_t len = 0, line_num = 0;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		token = strtok(line, " \n\t\a\b");
		if (token == NULL)
		{
			free(stack);
			usage_error(0);
		}
		else if (token[0][0] == '#')
		{
			free(token);
			continue;
		}
		execute(token, stack, line_num);
	}
	free(stack);

	if (line && *line == 0)
	{
		free(line);
		usage_error(0);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
