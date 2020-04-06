#include"holberton.h"

/**
 * _atoi - converts a string to an int
 *@s: accepted string pointer
 *Return: int
 */

int _atoi(char *s)
{
	int i, n, p, r;
	char h;

	n = 0;
	p = 0;
	h = '0';
	r = 0;
	for (i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] == '-')
			n++;
		if (s[i] == '+')
			p++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			h = s[i];
			if (h >= '0' && h <= '9')
			{
				r = (r * 10) + (h - '0');
			}
		}
		if ((s[i] < '0' || s[i] > '9') && (r != 0))
			break;
	}
	if (r == 0)
		return (0);
	if (n % 2 != 0)
	{
		if ((r - 1) > r)
			return (0);
		return (r * -1);
	}
	else
	{
		if ((r + 1) < r)
			return (0);
		return (r);
	}
}
