#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_usage - Print an usage error if the number of arguments is != 2.
 * @n: The number of arguments passed to the program.
 */
void check_usage(int n)
{
	if (n != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * script_error - Print a message to the stderr if the script cannot be opened.
 * @scriptname: A pointer to the script name.
 */
void script_error(char *scriptname)
{
	fprintf(stderr, "Error: Can't open file %s\n", scriptname);
	exit(EXIT_FAILURE);
}
