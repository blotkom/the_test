#include "mhead.h"

/**
 * copyofarray - how to the array to coppy
 * @old_array: the aray
 * @new_size: the size
 *
 * Return: pointer
 */
char **copyofarray(char **old_array, int new_size)
{
	char **new_array = NULL;
	char **ptr_array;

	new_array = malloc(sizeof(char **) * new_size);

	ptr_array = new_array;
	while (*old_array != NULL)
	{
		*ptr_array = _stingduplicaing(*old_array);
		ptr_array++;
		old_array++;
	}
	*ptr_array = NULL;

	return (new_array);
}
