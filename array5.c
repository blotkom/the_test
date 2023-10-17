#include "mhead.h"

/**
 * arrayfree - freetheallaray
 * @args: freeallarray
 *
 * Return: TTRHUEE
 */
int arrayfree(char **args)
{
	char **ptr = args;

	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}

	free(args);

	return (TTRHUEE);
}
