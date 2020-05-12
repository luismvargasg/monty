/*
 * File name: 	monty_main.c
 * Authors:	Robinson Montes
 * 		Luis Miguel Vargas
 */
#include "monty.h"

/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Nothing.
 */
void main(int ac, char **av)
{
	FILE *fd = NULL;

	if (ac != 2)
		usage_error();
	fd = fopen(av[1], "r");

	if (fd == NULL)
		open_error(argv[1]);
	monty_run(fd);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
