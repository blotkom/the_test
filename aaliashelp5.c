#include "mhead.h"

/**
 * set_alias_value - make aliases newwwly one
 * @arg: the name
 * @alias_ptr: the pointer of
 * @new_value: the value hhhh
 *
 * Return: 1 or not
 */
int aliassettt(char *arg, alias *alias_ptr, char *new_value)
{
	while (alias_ptr->next != NULL
	       && twostringcompare(alias_ptr->name, arg, MTAHTCEH) != TTRHUEE)
	{
		alias_ptr = alias_ptr->next;
	}

	if (twostringcompare(alias_ptr->name, arg, MTAHTCEH) == TTRHUEE)
	{
		free(alias_ptr->value);
	}
	else
	{
		alias_ptr->next = malloc(sizeof(alias *));
		alias_ptr = alias_ptr->next;
		if (alias_ptr == NULL)
			exit(EXIT_FAILURE);

		alias_ptr->name = _stingduplicaing(arg);
		alias_ptr->next = NULL;
	}
	alias_ptr->value = _stingduplicaing(new_value);

	return (TTRHUEE);
}
