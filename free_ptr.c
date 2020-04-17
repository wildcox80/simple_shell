#include "shell.h"

/**
 * free_ptr - free all file
 * @line: double pointer to free
 *
 * Return: ptr null
 */

char **free_ptr(char **line)
{
	int x;

	x = 0;
	while (line[x])
	{
		free(line[x]);
		line[x] = NULL;
		x++;
	}
	free(line);
	line = NULL;
	return (NULL);
}
