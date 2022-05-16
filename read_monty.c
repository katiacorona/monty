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
	unsigned int line_number = 1;

	while (getline(&line, &line_len, scr) != -1)
	{
		printf("Line #%i: %s", line_number, line);
		get_instruction(line, line_number);
		line_number++;
	}
}

/**
 * get_instruction - Takes a line as input and separates it into words.
 * @l: A pointer to the line to be tokenized.
 * @line_number: The number of the line to be tokenized.
 * Return: A 2D array of pointers to the newly created tokens.
 */
void get_instruction(char *l, unsigned int line_number)
{
	char *instruction, *n;
	int i = 0;
	UNUSED(line_number);

	instruction = strtok(l, " ");
	if (strcmp(instruction, "push") == 0)
		n = strtok(NULL, "\n");
	else
	{
		while (instruction[i] != '\n')
			i++;
                instruction[i] = '\0';
		n = "none";
	}
	printf("Opcode: %s(%lu) / Opcode->n: %s(%lu)\n", instruction, strlen(instruction), n, strlen(n));
}
