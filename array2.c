#include "mhead.h"

/**
 * arraymaker - make array fromlist
 * @str: the string
 * @delim: deleimter os string
 * @if_sep: if there semicolon
 * sem col on
 *
 * Return: pointer
 */
char **arraymaker(char *str, char delim, char **if_sep)
{
	char *str_ptr = str;
	unsigned int i = 2;
	char **array = NULL;

	while (*str_ptr != '\0')
	{
		if (*str_ptr == ';')
			break;
		if (*str_ptr == delim && *(str_ptr + 1) != '\0')
			i++;

		str_ptr++;
	}

	array = malloc(i * sizeof(char **));
	if (array == NULL)
		exit(EXIT_FAILURE);

	array[0] = str;
	str_ptr = str;
	i = 1;

	while (*str_ptr != '\0')
	{
		if (*str_ptr == delim)
		{
			*str_ptr = '\0';
			str_ptr++;
			if (*str_ptr == ';')
			{
				array[i] = NULL;
				if (*(str_ptr + 1) != '\0' && *(str_ptr + 2) != '\0')
					*if_sep = str_ptr + 2;
				break;
			}
			if (*str_ptr != '\0')
			{
				array[i] = str_ptr;
				i++;
			}
		}
		str_ptr++;
	}
	array[i] = NULL;

	return (array);
}
