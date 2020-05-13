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
	stack_t **stack = NULL;
	char *line = NULL, **token, delim[] = " \n\t\a\b";
	size_t len = 0, line_num = 0;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		token = tokening(line);
		if (token == NULL)
		{
			if (empty_line(line, delim))
				continue;
			free_dp(NULL, stack);
			usage_error(0);
		}
		else if (token[0][0] == '#')
		{
			free_dp(token, NULL);
			continue;
		}
		else if (strcmp(token[0], "push") != 0)
			monty_push(stack, token, line_num);
		else
			execute(token, stack, line_num);
	}
	free_dp(NULL, stack);

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
	command = malloc((bufsize + 1) * sizeof(char *));
	if (command == NULL)
	{
		free(line);
		free_dp(command, NULL);
		usage_error(0);
	}

	tokens = strtok(line, " \n\t\a\b");
	while (tokens != NULL)
	{
		command[i] = malloc(strlen(tokens) + 1);
		if (command[i] == NULL)
		{
			free_dp(command, NULL);
			usage_error(0);
			return (NULL);
		}
		strcpy(command[i], tokens);
		tokens = strtok(NULL, " \n\t\a\b");
		i++;
	}
	command[i] = NULL;
	return (command);
}

/**
 * empty_line - A function that checks if line only contains delimiters.
 * @line: The pointer to the line.
 * @delims: The string with delimiter characters.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
