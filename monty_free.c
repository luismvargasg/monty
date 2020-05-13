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
	stack_t temp;

	free(token);

	if (stack != NULL)
	{
		temp = *stack;
		*stack = stack->next;
		free(temp);
	}
}
