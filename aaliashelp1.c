#include "mhead.h"

int thestatus;

/**
 * aliasval - printvalur of alias
 * @arg: alias name
 * @alias_ptr: pointer to aliases
 *
 * Return: 0 or false
 */
int aliasval(char *arg, alias *alias_ptr)
{
	while (alias_ptr != NULL)
	{
		fflush(stdin);
		if (twostringcompare(arg, alias_ptr->name, MTAHTCEH) == TTRHUEE)
		{
			write(STDOUT_FILENO, arg, _lengthofstr(arg));
			write(STDOUT_FILENO, "=\'", 2);
			write(STDOUT_FILENO, alias_ptr->value,
			      _lengthofstr(alias_ptr->value));
			write(STDOUT_FILENO, "\'\n", 2);
			return (TTRHUEE);
		}
		alias_ptr = alias_ptr->next;
	}

	thestatus = 1;
	write(STDERR_FILENO, "alias: ", 7);
	write(STDERR_FILENO, arg, _lengthofstr(arg));
	write(STDERR_FILENO, " not found\n", 11);

	return (FTAHLSHE);
}
