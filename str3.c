#include "mhead.h"

/**
 * strinone - this function make two stringinto one
 * @s1: first
 * @s2: the second
 *
 * Return: pointer or null
 */
char *strinone(char *s1, char *s2)
{
	int len = _lengthofstr(s1) + _lengthofstr(s2);
	char *dest = malloc(len + 1);
	char *ptr = dest;

	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr = *s1;
			ptr++;
			s1++;
		}
	}

	if (s2 != NULL)
	{
		while (*s2 != '\0')
		{
			*ptr = *s2;
			ptr++;
			s2++;
		}
	}

	*ptr = '\0';

	return (dest);
}
