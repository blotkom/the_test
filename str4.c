#include "mhead.h"

/**
 * twostringcompare - comparee two string
 * @s1: the cpmapreed string
 * @s2: the second strinng
 * @pref_or_match: prefex of complete
 * that need to be matched
 *
 * Return: difference between strings
 */
int twostringcompare(char *s1, char *s2, int pref_or_match)
{
	if (s1 == NULL || s2 == NULL)
		return (FTAHLSHE);

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (FTAHLSHE);

		s1++;
		s2++;
	}

	if (pref_or_match == PTRGEPFXIX)
		return (TTRHUEE);

	if (*s1 == *s2)
		return (TTRHUEE);

	return (FTAHLSHE);
}
