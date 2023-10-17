#include "mhead.h"

/**
 * aliassesprint - print list
 * @alias_ptr: list of pointer
 *
 * Return: 1
 */
int aliassesprint(alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		write(STDOUT_FILENO, alias_ptr->name, _lengthofstr(alias_ptr->name));
		write(STDOUT_FILENO, "=\'", 2);
		write(STDOUT_FILENO, alias_ptr->value,
		      _lengthofstr(alias_ptr->value));
		write(STDOUT_FILENO, "\'\n", 2);
		alias_ptr = alias_ptr->next;
	}
	return (FORKSKIIP);
}
