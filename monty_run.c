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
int monty_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = "\n\0";
	size_t len = 0;
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		token = tokening(line, delim);
		if (token == NULL)
		{
			if (empty_line(line, delim))
				continue;
			free_stack(&stack);
			return (usage_error(0));
		}
		else if (token[0][0] == '#')
		{
			free(token);
			continue;
		}
		else if (strncmp(token[0], "push", 4) == 0)
<<<<<<< HEAD
			exit_status = monty_push(&stack, token, line_num);
=======
			monty_push(&stack, token, line_num);
>>>>>>> 12c4e77fecc5630e46f7e63305e6b4f70e69cd31
		else
			exit_status = execute(token, &stack, line_num);
	}
<<<<<<< HEAD
	free_stack(&stack);
	free(token);
=======
	free_dp(token, &stack);
	fclose(fd);
>>>>>>> 12c4e77fecc5630e46f7e63305e6b4f70e69cd31
	if (line && *line == 0)
	{
		free(line);
		return (usage_error(0));
	}
	free(line);
	return (exit_status);
}

/**
 * tokening - A function that split the line.
 * @line: The pointer to bytecode line.
 * @delim: Array with 5 delimiters " \n\t\a\b".
 * Return: The pointer to tokens.
 */
char **tokening(char *line, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (line == NULL || !*line)
		return (NULL);

	bufsize = strlen(line);
	if (bufsize == 0)
		return (NULL);
	token = malloc(bufsize * sizeof(char *));
	if (token == NULL)
	{
		free(line);
<<<<<<< HEAD
		free(token);
		exit(usage_error(0));
=======
		free(command);
		usage_error(0);
>>>>>>> 12c4e77fecc5630e46f7e63305e6b4f70e69cd31
	}
	tokens = strtok(line, delim);
	if (tokens == NULL)
	{
		free(token);
		free(line);
		return (NULL);
	}
	while (tokens != NULL)
	{
<<<<<<< HEAD
		token[i] = tokens;
=======
		command[i] = malloc(strlen(tokens) + 1);
		if (command[i] == NULL)
		{
			free(line);
			free_dp(command, NULL);
			usage_error(0);
		}
		strcpy(command[i], tokens);
		tokens = strtok(NULL, delim);
>>>>>>> 12c4e77fecc5630e46f7e63305e6b4f70e69cd31
		i++;
		tokens = strtok(NULL, delim);
	}
	token[i] = '\0';
	return (token);
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
