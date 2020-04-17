#include "shell.h"

/**
 * _strtok - Split to token of strok
 * @line_msg: recieved to user
 * Return: the chit(s)
 */
char **_strtok(char *line_msg)
{
	char *delim = " ,!¡¿?'\"\n\t";
	char *token = NULL, **array = NULL;
	int i = 0;

	if (line_msg == NULL)
	{
		return (NULL);
	}

	array = malloc(_strlen(line_msg) + MAX);

	token = strtok(line_msg, delim);
	array[i] = token;

	while (token)
	{
		i++;
		token = strtok(NULL, delim);
		array[i] = token;
	}
	i++;
	array[i] = NULL;
	return (array);
}
