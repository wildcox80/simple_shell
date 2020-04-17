#include "shell.h"
/**
 * main - simple shell program that takes user input and interprets it as unix
 * commands
 * @argc: number of command line arguments
 * @av: list of command line arguments
 * @env: environment
 * Return: 0 (success)
 */


int main(int argc __attribute__((unused)), char **av, char **env)
{
	char *string = NULL, **line = NULL;
	int _num_prompt = 0, val_isatty = 0;

	while (1)
	{
		val_isatty = isatty(STDIN_FILENO);
		string = get_line(val_isatty);

		if (_strcmp(string, "exit\n") == 0)
		{
			free(string);
			exit(0);
		}

		if (string != NULL)
		{
			_num_prompt++;
			line = _strtok(string);
			_execev(line, av[0], _num_prompt, val_isatty, env);
			free(string);
			free(line);
		}
		val_isatty = 0;
	}
	return (0);
}

