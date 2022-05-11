#include "monty.h"

void error_usage(int argc);

/**
 * main - Entry Point. The very first version of Monty.
 * @argc: the number of arguments passed to the function.
 * @argv: a pointer to the array of arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	return (0);
}

/**
 * error_usage - Print an usage error if the number of arguments is != 2.
 */
void error_usage(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
