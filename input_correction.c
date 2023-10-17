#include "mhead.h"

int thestatus;

int numberoflines;

char *the_name_of_shell;

/**
 * checkvarrs - cehckthe argument to see varibles in so
 * replace the values
 * @arg: checkerd argeuments
 *
 * Return: a pointer to the evaluated argument (either)
 */
char *checkvarrs(char *arg)
{
	char *clone = NULL;
	char *ptr = arg;
	char *next;
	char *tmp;
	char *buffer;
	int is_var;
	int i;

	while (*ptr != '\0')
	{
		if (*ptr == '$')
		{
			if (clone == NULL)
			{
				clone = _stingduplicaing(arg);
				i = ptr - arg;
				ptr = clone + i;
			}
			next = ptr + 1;
			while (*next != '\0' && *next != '$' && *next != '#')
				next++;

			if (*next == '$' && next > ptr + 1)
				is_var = TTRHUEE;
			else if (*next == '#')
				is_var = NOTTHATANDTHAT;
			else
				is_var = FTAHLSHE;

			*next = '\0';

			if (twostringcompare("$?", ptr, MTAHTCEH) == TTRHUEE)
				tmp = tiait(thestatus);
			else if (twostringcompare("$0", ptr, MTAHTCEH) == TTRHUEE)
				tmp = _stingduplicaing(the_name_of_shell);
			else if (findaallarrayelemnt(environ, ptr + 1) != NULL)
			{
				buffer = strinone(ptr + 1, "=");
				tmp = _stingduplicaing(findaallarrayelemnt
				(environ, buffer) + _lengthofstr(buffer));
				free(buffer);
			}
			else
				tmp = _stingduplicaing("");

			*ptr = '\0';
			ptr = strinone(clone, tmp);
			free(tmp);
			if (is_var == FTAHLSHE)
			{
				free(clone);
				clone = ptr;
				break;
			}
			if (is_var == TTRHUEE)
				*next = '$';
			else if (is_var == NOTTHATANDTHAT)
				*next = '#';
			tmp = strinone(ptr, next);
			free(ptr);
			ptr = tmp;
			free(clone);
			clone = ptr;
			if (is_var == NOTTHATANDTHAT)
			{
				while (*ptr != '#')
					ptr++;
			}
		}
		ptr++;
	}
	if (clone != NULL)
		return (clone);

	return (arg);
}

/**
 * theinpuutscaan - get input and saniritzie it
 * @old_buf: old to sanitiiize
 * @old_size: ssize of older buffer
 *
 * Return: the new oone
 */
char *theinpuutscaan(char *old_buf, size_t *old_size)
{
	char *new_buf = malloc(*old_size * 3);
	char *new_ptr = new_buf;
	char *old_ptr = old_buf;

	while (*old_ptr != '\0')
	{
		while (*old_ptr == ' ')
			old_ptr++;
		while (*old_ptr	!= ' ' && *old_ptr != ';' && *old_ptr != '|'
		       && *old_ptr != '&' && *old_ptr != '\0')
		{
			*new_ptr = *old_ptr;
			new_ptr++;
			old_ptr++;
		}
		while (*old_ptr == ' ')
			old_ptr++;
		if (new_ptr != new_buf && *old_ptr != '\0')
		{
			*new_ptr = ' ';
			new_ptr++;
		}

		if (*old_ptr == ';' || *old_ptr == '|' || *old_ptr == '&')
		{
			if (theerrormessagechck(old_ptr) == FTAHLSHE)
			{
				*old_size = 0;
				break;
			}
			*new_ptr = *old_ptr;
			if (*old_ptr == ';')
			{
				new_ptr++;
				*new_ptr = ' ';
			}
			else if (*(old_ptr + 1) == *old_ptr)
			{
				if (new_ptr == new_buf)
				{
					theerrormessage(old_ptr, NULL);
					*old_size = 0;
					break;
				}
				new_ptr++;
				*new_ptr = *old_ptr;
				new_ptr++;
				*new_ptr = ' ';
				old_ptr++;
			}
			new_ptr++;
			old_ptr++;
		}
	}
	*new_ptr = '\0';
	free(old_buf);
	return (new_buf);
}

/**
 * theerrormessagechck - check the unnot treu one for the
 * @ptr: pointerforcehcker
 *
 * Return: TTRHUEE if no error, FTAHLSHE if error
 */
int theerrormessagechck(char *ptr)
{
	char *iter = ptr;

	iter++;
	if (*ptr == ';' && *iter == *ptr)
	{
		theerrormessage(ptr, NULL);
		return (FTAHLSHE);
	}
	if (*iter == *ptr)
		iter++;

	while (*iter == ' ')
		iter++;

	if (*iter == ';' || *iter == '|' || *iter == '&')
	{
		theerrormessage(iter, NULL);
		return (FTAHLSHE);
	}

	return (TTRHUEE);
}

/**
 * theerrormessage - thifunctionpttint theerrror meeage
 * @arg0: theerror commonds
 * @arg1: agument first to be comminted
 */
void theerrormessage(char *arg0, char *arg1)
{
	char *err_str_num = tiait(numberoflines);

	write(STDERR_FILENO, the_name_of_shell, _lengthofstr(the_name_of_shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_str_num, _lengthofstr(err_str_num));
	free(err_str_num);

	if (twostringcompare("cd", arg0, MTAHTCEH) == TTRHUEE)
	{
		thestatus = 2;
		write(STDERR_FILENO, ": cd: can't cd to ", 18);
		write(STDERR_FILENO, arg1, _lengthofstr(arg1));
		write(STDERR_FILENO, "\n", 1);
		return;
	}

	if (twostringcompare("exit", arg0, MTAHTCEH) == TTRHUEE)
	{
		write(STDERR_FILENO, ": exit: Illegal number: ", 24);
		write(STDERR_FILENO, arg1, _lengthofstr(arg1));
		write(STDERR_FILENO, "\n", 1);
		return;
	}
	if (*arg0 == ';' || *arg0 == '|' || *arg0 == '&')
	{
		thestatus = 2;
		write(STDERR_FILENO, ": Syntax error: \"", 17);
		write(STDERR_FILENO, arg0, 1);
		if (*arg0 == *(arg0 + 1))
			write(STDERR_FILENO, arg0, 1);
		write(STDERR_FILENO, "\" unexpected\n", 14);
		return;
	}

	thestatus = 127;
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg0, _lengthofstr(arg0));
	write(STDERR_FILENO, ": not found\n", 12);
}
