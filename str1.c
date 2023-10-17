#include "mhead.h"

/**
 * _stingduplicaing - get pace in memory for new string
 * @src: string cppied
 *
 * Return: a pinter to cioou or return null
 */
char *_stingduplicaing(char *src)
{
	int len = _lengthofstr(src);
	char *dest = malloc(len + 1);
	char *ptr;

	if (dest == NULL)
		exit(EXIT_FAILURE);

	ptr = dest;

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
