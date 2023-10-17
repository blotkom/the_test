#include "mhead.h"

/**
 *  _lengthofstr - print the length  ofst
 * @str: thestring ti evalue
 *
 * Return: legthf of string
 */
int _lengthofstr(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		i++;
		str++;
	}

	return (i);
}
