#include "shell.h"

/**
 * pr_prompt - prints the prompt
 * @prompt: prompt style
 */
void printprompt(char *prompt)
{
	if (prompt == NULL)
		return;
	write(1, prompt, _strlen(prompt));
}

/**
 * builtins - runs builtins
 * @line: builtin to run
 *
 * Return: 0 if success, 1 otherwise
 */
int builtins(char *line)
{
	if (line == NULL)
		return (1);
	if (_strcmp(line, "env") == 0)
	{
		printenv();
		return (0);
	}
	return (1);
}

/**
 * execute - executes commands
 * @tokens: command and arguments
 * @st: pointer to status
 *
 * Return: 0 if success, 1 otherwise
 */
int execute(char **tokens, struct stat *st)
{
	char *path;

	path = getpath(tokens[0]);
	if (path != NULL && stat(path, st) == 0 && access(path, X_OK) == 0)
	{
		execv(path, tokens);
		return (0);
	}
	return (1);
}

/**
 * jw_sh - creates child
 * @prog: program name
 * @line: command line
 * @tokens: tokens
 * @loop_count: shell loop count
 *
 * Return: 0 for child, -1 for error, anything else for parent
 */
pid_t jw_sh(char *prog, char *line, char **tokens, int loop_count)
{
	pid_t child;
	int status;
	struct stat st;

	child = fork();
	if (child == -1)
	{
		errno = ECHILD, perror(prog);
		return (-1);
	}
	if (child == 0)
	{
		if (builtins(line) == 1)
			if (execute(tokens, &st) == 1)
				print_error(prog, loop_count, line);
	}
	else
		wait(&status);
	return (child);
}
/**
 * num_to_string - converts an integer to a string
 * @num: number
 *
 * Return: pointer to string
 */
char *num_to_string(int num)
{
	unsigned int i, div;
	int num_cp;
	char *buffer;

	buffer = malloc(sizeof(char) * 20);
	if (buffer == NULL)
		return (NULL);

	num_cp = num;
	div = 1;
	while (num_cp / 10)
	{
		div *= 10;
		num_cp /= 10;
	}

	for (i = 0; div > 1; i++)
	{
		buffer[i] = num / div + '0';
		num %= div;
		div /= 10;
	}
	buffer[i] = num % 10 + '0';
	i++;
	buffer[i] = '\0';
	return (buffer);
}

