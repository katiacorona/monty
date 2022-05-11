#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)

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
	size_t bufsize = 0;
	char *line = NULL;
	UNUSED(argv);

	check_usage(argc);
	script = fopen(argv[1], "r");
	if (script == NULL)
		return (script_error(argv[1]));

	getline(&line, &bufsize, script);
	printf("%s\n", line);

	fclose(script);
	return (0);
}

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
 */
void script_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
