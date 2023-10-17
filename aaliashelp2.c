#include "mhead.h"

/**
 * makealiasfree - remove all aliasess
 * @alias_ptr: pointer of head
 *
 * Return: 2
 */
int makealiasfree(alias *alias_ptr)
{
	alias *tmp;

	while (alias_ptr != NULL)
	{
		tmp = alias_ptr;
		alias_ptr = alias_ptr->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}

	return (TTRHUEE);
}
