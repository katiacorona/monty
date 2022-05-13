#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
