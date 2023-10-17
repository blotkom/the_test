#include "mhead.h"

/**
 * ifaliasesisfounded - return aliases if true
 * aliases returned
 * @args: the argument tochec
 * @alias_ptr: the pointer
 *
 * Return: 1 tue
 */
int ifaliasesisfounded(char **args, alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		if (twostringcompare(*args, alias_ptr->name, MTAHTCEH) == TTRHUEE)
		{
			*args = _stingduplicaing(alias_ptr->value);
			return (EXCUTTEU_DO_BRO);
		}
		alias_ptr = alias_ptr->next;
	}
	return (TTRHUEE);
}
