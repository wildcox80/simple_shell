#include "shell.h"

/**
 *_strcmp -  compares two strings
 *@s1: A pointer to an char that will be updated
 *@s2: A pointer to an char that will be updated
 *Return: dest
 */

int _strcmp(char *s1, char *s2)
{
	/* pointer declaration*/
	char *p1 = s1;
	char *p2 = s2;

	/* Loop While*/
	while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
	{

		/* Pointer iteration*/
		p1++;
		p2++;

	}

	return (*p1 - *p2);
}

/**
 * _strlen  -returns the length of a string.
 * @s: pointer s.
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * *_strstr - find a string in another string
 * @haystack: pointer to array to be searched
 * @needle: pointer to array to search for
 * Return: return pointer to location of string
 */

char *_strstr(char *haystack, char *needle)
{
	const char *s, *t;

	if (!haystack || !needle)
		return (0);

	if (!*needle)
		return ((char *)haystack);
	for (; *haystack; haystack++)
	{
		if (*haystack == *needle)
		{
			t = haystack;
			s = needle;
			for (; *t; s++, t++)
			{
				if (*t != *s)
					break;
			}
			if (!*s)
				return ((char *)haystack);
		}
	}
	return (0);
}

/**
 *_strdup - back a pointer to array
 *@str: pointer to array
 *Return: Always an array dinamic
 */

char *_strdup(char *str)
{
	char *arr;
	unsigned int i, size;

	if (str == 0)
		return (NULL);

	size = _strlen(str) + 1;

	arr = (char *)malloc(size * sizeof(char));

	if (arr == 0)
		return (NULL);

	for (i = 0; *(str + i) != '\0'; i++)
		*(arr + i) = *(str + i);

	*(arr + i) = '\0';

	return (arr);
}

/**
 *_equal - find sames characters
 *@dest: initial segment
 *@src: prefix
 *Return: Always int
 */
int _equal(char *dest, char *src)
{
	int i;

	i = 0;

	while (*dest + i != '\0' && *src + i != '\0')
	{
		if (*dest != *src)
			return (0);
		dest++;
		src++;
	}

	return (*src == '\0');
}

