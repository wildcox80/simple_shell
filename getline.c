#include "shell.h"

/**
 * get_line - Prints "jw_shell/user@root$"  and wait for a command
 * @isatty_val: no_interactive
 * Return: The read command (line)
 **/

char *get_line(int isatty)
{
	ssize_t read = 0;
	size_t bufer_len = 0;
	char *line = NULL;

	if (isatty == 1)
	{
		write(STDOUT, "\033[1;31mjw_shell/user@root$ ", 32);
		write(STDOUT, "\033[0m", 4);
	}

	read = getline(&line, &bufer_len, stdin);

	if (read == EOF)
	{
		if (isatty == 1)
		{
			printf("\n");
		}
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

