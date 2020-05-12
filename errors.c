/*
 * File name: errors.c
 * Authors:	Luis Miguel Vargas
 *		Robinson Montes
 */

#include "monty.h"

/**
 * usage_error - Afunction that prints usage error message.
 * Return: Nothing
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - A function that prints malloc error message.
 * Return: Nothing.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - A function that prints file open error message.
 * @filename: Name of file failed to open.
 * Return: Nothing.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
