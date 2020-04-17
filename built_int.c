#include "shell.h"
/**
 * built_int - command environment
 * @line: wherever
 * @environ: add envi
 * Return: if pointers is success.
 */

int built_int(char **line, char **environ)
{
	int dir_val = 0, i;

	if (_strcmp(line[0], "exit") == 0 && !line[1])
	{
		line = free_ptr(line);
		_exit_function();
	}

	if (_strcmp(line[0], "cd") == 0)
	{
		if (!line[1])
		{
			dir_val = chdir("..");
			if (dir_val != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		dir_val = chdir(line[1]);

		if (dir_val != 0)
		{
			printf("Error changing directory to: %s\n", line[1]);
			return (1);
		}
		return (1);
	}

	if (_strcmp(line[0], "env") == 0 && !(line[1]))
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (1);
	}
	return (EXIT_SUCCESS);
}

