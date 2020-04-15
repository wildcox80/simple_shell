#include "shell.h"
/**
 * split_lines - breaks a line up into tokens
 * @line: line to break up
 * @delim: delimiter to use to break up
 *
 * Return: pointer to an array of strings (tokens)
 */
char **split_lines(char *line, char *delim)
{
	char **args;
	char *token;
	unsigned int index = 0;

	if (line == NULL)
	{
		fprintf(stderr, "Print Error\n");
		exit(EXIT_FAILURE);
	}
	args = malloc(sizeof(char *) * ARG_SIZE);
	if (args == NULL)
	{
		fprintf(stderr, "Error to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		args[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	args[index] = NULL;
	return (args);
}

