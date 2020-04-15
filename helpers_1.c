#include"shell.h"

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


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: size of previously allocated memory block
 * @new_size: size of new memory block
 *
 * Return: pointer to allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *cptr = ptr;
	char *reptr = NULL;
	void *newptr = NULL;
	unsigned int i, min;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size > old_size)
		min = old_size;
	if (old_size > new_size)
		min = new_size;

	reptr = newptr;
	for (i = 0; i < min; i++)
		reptr[i] = cptr[i];

	free(ptr);