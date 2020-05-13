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
	char *line = NULL;
	size_t len = 0, line_count = 0;

	while (getline(&line, &len, fd) != -1)
	{
		line_count++;
		tokens = strtow(line, " \n\t\a\b");
		if (tokens == NULL)
		{
			free(stack);
			malloc_error();
		}
		else if (tokens[0][0] == '#')
		{
			free(tokens);
			continue;
		}
	}
	free(stack);

	if (line && *line == 0)
	{
		free(line);
		malloc_error();
	}
	free(line);
	exit(EXIT_SUCCESS);
}
