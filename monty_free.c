/*
 * File name:   monty_free.c
 * Authors:     Luis Miguel Vargas
 *              Robinson Montes
 */

#include "monty.h"

/**
 * free_dp - Function that frees the memory allocated by the program.
 * @token: Double pointer to tokens.
 * @stack: Pointer to the doubly linked list representation of a stack.
 *
 * Return: Nothing.
 */

void free_dp(char **token, stack_t **stack)
{
	stack_t *tmp = *stack;
	size_t i = 0;

	if (token == NULL)
		return;
	for (i = 0; token[i]; i++)
		free(token[i]);
	free(token);

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
