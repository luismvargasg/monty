#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define STACK 0
#define QUEUE 1

/*==========================================================================*/
/*==========================     DATA STRUCTURES    ========================*/
/*==========================================================================*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*=========================================================================*/
/*=========================   OPCODE FUNCTIONS  ===========================*/
/*=========================================================================*/

int main(int ac, char **av);
void monty_run(FILE *fd);
char **tokening(char *line, char *delim);
void execute(char **token, stack_t **stack, unsigned int line_num);
void monty_push(stack_t **stack, char **token, unsigned int line_num);
void free_dp(char **token, stack_t **stack);
int empty_line(char *line, char *delims);
void monty_pall(const stack_t *stack);
int init_stack(stack_t **stack);

/*=========================================================================*/
/*=========================        ERRORS       ===========================*/
/*=========================================================================*/

void usage_error(int flag);
void open_error(char *filename);
void f_errors(int flag, unsigned int line_num);

#endif /* __MONTY_H__ */
