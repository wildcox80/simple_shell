#include "shell.h"
/**
 * getpath - gets the full pathname of given command
 * @name: name of command
 *
 * Return: full pathname of command on PATH, NULL if not found
 */
char *getpath(char *name)
{
	char *path;
	static char temp[BUF_SIZE];
	char **tokens;
	int i;
	struct stat st;

	if (name == NULL)
		return (NULL);
	if (_strfind('/', name) || _strfind('.', name))
		return (name);
	path = malloc(BUF_SIZE);
	if (path == NULL)
		return (NULL);
	_strcpy(path, getenv("PATH"));
	if (path[0] == ':')
	{
		_strcpy(temp, "./");
		_strcat(temp, name);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
	}
	tokens = split_lines(path, ":");
	for (i = 0; tokens[i] != NULL; i++)
	{
		_strcpy(temp, tokens[i]);
		_strcat(temp, "/");
		_strcat(temp, name);
		if (stat(temp, &st) == 0)
		{
			name = temp;
			return (name);
		}
	}
	/* not found */
	free(path);
	free(tokens);
	return (NULL);
}

