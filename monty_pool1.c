/**
  * File name:	func_pool1.c
  * Authors:	Luis Miguel Vargas
  *		Robinson Montes
  */

#include "monty.h"

/**
 * monty_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		f_errors(1, line_number);
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - A function that removes the top value in the stack.
 * @stack: The pointer to the stack_t list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		f_errors(2, line_number);
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - A function that waps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		f_errors(3, line_number);
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * monty_add - A function that dds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		f_errors(4,line_number);
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - A function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 *              from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		f_errors(5, line_number);
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}
