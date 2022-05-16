#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

#define UNUSED(x) (void)(x)
#define DELIM " \n\t"

/* Shared variables */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */

void check_usage(int n);
void script_error(char *scriptname);
void read_script(FILE *scr);
void get_instruction(char *l, unsigned int line_number);
/* void (*get_opcode_func(char *opcode))(stack_t ****, unsigned int ****); */

#endif /* MONTY_H */
