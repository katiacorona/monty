#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry Point. The very first version of Monty.
 * @argc: the number of arguments passed to the function.
 * @argv: a pointer to the array of arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	FILE *script;

	/* 00 - Check usage and Monty script */
	check_usage(argc);
	script = fopen(argv[1], "r");
	if (script == NULL)
		script_error(argv[1]);

	/* 01 - Read Monty script */
	read_script(script);

	/* Close script and finalize */
	fclose(script);
	return (0);
}
