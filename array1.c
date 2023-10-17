#include "mhead.h"

/**
 * findaallarrayelemnt - find and get elements of an array full
 * @array: the array to be used
 * @element_name: the elemnts name to befounded
 *
 * Return: return array elemnt or return null
 */
char *findaallarrayelemnt(char **array, char *element_name)
{
	while (*array != NULL)
	{
		if (twostringcompare(*array, element_name, PTRGEPFXIX) == TTRHUEE)
			return (*array);

		array++;
	}

	return (NULL);
}
