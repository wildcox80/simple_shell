#include "shell.h"

/**
 * _getenv - gets value environment variable
 * @name: name of env variable to get
 *
 * Return: pointer to environment variable
 */

char *_getenv(const char *name)
{
	char *env;
	int i, j;

	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] != *env)
				break;
			env++;
		}
		if (name[j] == '\0' && *env == '=')
		{
			env++;
			return (env);
		}
	}
	/* no match */
	return (NULL);
}
