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
		token = tokening(line, " \n\t\a\b");
		if (token == NULL)
		{
			free_dp(stack, NULL);
			usage_error(0);
		}
		else if (token[0][0] == '#')
		{
			free_dp(token, NULL);
			continue;
		}
		else if (token[0] == "push")
			monty_push(stack, token, line_num);
		else
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

/**
 * tokening - A function that split the line.
 * @line: The pointer to bytecode line.
 * Return: The pointer to tokens.
 */
char **tokening(char *line)
{
	char *tokens = NULL, **command = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (line == NULL)
		return (NULL);

	bufsize = strlen(line);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		free(line);
		free_dp(commands, NULL);
		usage_error(0);
	}

	tokens = strtok(line, " \n\t\a\b");
	while (tokens != NULL)
	{
		commands[i] = malloc(strlen(tokens) + 1);
		if (commands[i] == NULL)
		{
			free_dp(commands);
			usage_error(0);
			return (NULL);
		}
		strcpy(commands[i], tokens);
		token = strtok(NULL, " \n\t\a\b");
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
