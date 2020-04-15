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
 *_strcpy - function to copy string from source
 *@dest: pointer to destination of string
 *@src: pointer to source of string
 * Return: return the value at dest
 */

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
	return (dest);
}


/**
 *_strcat - concatenate two string
 *@dest: destination concatenate
 *@src: source concatenate
 *Return: concatenate two string
 */

char *_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strfind - find a character in a string
 * @c: character to find
 * @s: string to seach
 *
 * Return: 1 if found, 0 otherwise
 */
int _strfind(char c, char *s)
{
	if (s == NULL)
		return (0);

	if (*s == c)
	{
		for (s = 0; *s != '\0'; s++)
		{
			return (1);
		}
	}
	return (0);
}

