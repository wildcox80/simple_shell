#include "shell.h"

/**
 * get_char - reads an input of a character
 *
 * Return: the contents of the buffer one character
 */

int get_char(void)
{
	static char buffer[MAX];
	static int start;
	static int end;
	int c = 0;

	if (start == end)
	{
		c = read(0, buffer, MAX);
		if (c == 0)
			return (EOF);
		start = 0;
		end = c;
	}
	if (c >= 0)
		return (buffer[start++]);
	return (EOF);
}

