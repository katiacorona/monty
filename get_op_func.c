#include "monty.h"
#include <string.h>

/**
 * get_opcode_func - Get the correct opcode function.
 * @opcode: The opcode to match with a function.
 */
void (*get_opcode_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_s opcode_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{NULL, NULL}
	};
	int i = 0;

	while (opcode_funcs[i].opcode)
	{
		if (strcmp(opcode, opcode_funcs[i].opcode) == 0)
			return (opcode_funcs[i].f);
		i++;
	}
	return (NULL);
}
