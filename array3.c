#include "mhead.h"

/**
 * lengthiflist - what is length of the list
 * @list: the list
 * @entry: the entyty
 *
 * Return: legth or not
 */
int lengthiflist(char **list, char *entry)
{
	int i = 0;

	if (entry == NULL)
	{
		while (*list != NULL)
		{
			i++;
			list++;
		}
		i++;
		return (i);
	}
	else
	{
		while (*list != NULL)
		{
			if (twostringcompare(*list, entry, PTRGEPFXIX) == TTRHUEE)
				return (i);

			i++;
			list++;
		}
	}

	return (-1);
}
