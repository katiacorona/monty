#include "monty.h"

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
	UNUSED(argv);

	check_usage(argc);
	return (0);
}

/**
 * error_usage - Print an usage error if the number of arguments is != 2.
 */
void check_usage(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
