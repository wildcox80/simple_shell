#include "shell.h"
/**
 * main - simple shell program that takes user input and interprets it as unix
 * commands
 * @ac: number of command line arguments
 * @av: list of command line arguments
 * @env: environment
 * Return: 0 (success)
 */


int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *str = NULL;
	char **line = NULL;
	int prompt_num = 0;
	int isatty_val = 0;

	while (1)
	{
		isatty_val = isatty(STDIN_FILENO);
		str = get_line(isatty_val);

		if (_strcmp(str, "exit\n") == 0)
		{
			free(str);
			exit(0);
		}
		if (str != NULL)
		{
			prompt_num++;
			line = _strtok(str);
			_execev(line, av[0], prompt_num, isatty_val, env);
			free(str);
			free(line);
		}
		isatty_val = 0;
	}
	return (0);
}

