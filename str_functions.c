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
}}

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

/**
 *_strstr - find
 *@haystack: initial segment
 *@needle: prefix
 *Return: Always char
 */

char *_strstr(char *haystack, char *needle)
{
	if (*haystack == '\0')
		return (0);

	if (haystack[0] != needle[0])
		return (NULL);

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		if ((*haystack == *needle) && _equal(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (0);
}
