/*
 * File name:	monty_main.c
 * Authors:	Luis Miguel Vargas
 *		Robinson Montes
 */

#include "monty.h"

/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;

	if (ac != 2)
		usage_error(1);
	fd = fopen(av[1], "r");

	if (fd == NULL)
		open_error(av[1]);
	monty_run(fd);
	fclose(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
