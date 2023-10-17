#include "mhead.h"

/**
 * _tato - how to convert the string inton umb
 * @s: the string
 *
 * Return: the umber
 */
int _tato(char *s)
{
	int n = 0;
	int sign = 1;
	int s_int;

	if (*s == '=' && *(s + 1) >= '0' && *(s + 1) <= '9')
	{
		sign = -1;
		s++;
	}

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			s_int = *s - 48;
			if (sign == 1)
				n = (n * 10) + s_int;
			else
				n = (n * 10) - s_int;
		}
		else
			return (-1);
		s++;
	}

	return (n);
}
