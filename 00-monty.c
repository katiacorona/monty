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

/**
 * read_script - Read each line from the Monty script.
 * @scr: The script to be read.
 */
void read_script(FILE *scr)
{
        size_t line_len = 0;
        char *line = NULL;
        unsigned int line_number = 0;

	while (getline(&line, &line_len, scr) != -1)
	{
        	line_number++;
        	printf("Line: %s", line);
        	create_tokens(line, " ");
        	printf("Line: %u\n", line_number++);
	}
}

/**
 * create_tokens - Takes a line as input and separates it into words.
 * @s: A pointer to the string to be tokenized.
 * @delim: The delimiter character.
 * Return: A 2D array of pointers to the newly created tokens.
 */
char *create_tokens(char *s, char *delim)
{
	int buflen = 64;
	char *token = NULL;

	if (s == NULL)
		return (NULL);

	token = malloc(buflen * sizeof(char));
	if (!token)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(s, delim);
	printf("Token: %s, Len: %lu\n", token, strlen(token));
	return (token);
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
 * @scriptname: A pointer to the script name.
 */
void script_error(char *scriptname)
{
	fprintf(stderr, "Error: Can't open file %s\n", scriptname);
	exit(EXIT_FAILURE);
}
