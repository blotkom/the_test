#include "mhead.h"

int thestatus;

/**
 * envpriiint - env print the new
 *
 * Return: 1 or zero
 */
int envpriiint(void)
{
	char **ptr = environ;

	while (*ptr != NULL)
	{
		write(STDOUT_FILENO, *ptr, _lengthofstr(*ptr));
		write(STDOUT_FILENO, "\n", 1);
		ptr++;
	}

	thestatus = 0;

	return (FORKSKIIP);
}

/**
 * _varunse - remove the env var
 * @name: var name
 *
 * Return: 0 or yes
 */
int _varunse(const char *name)
{
	char **env_ptr;
	char *buffer;
	int len;

	buffer = strinone((char *)name, "=");
	len = lengthiflist(environ, buffer);
	free(buffer);

	if (len == -1)
	{
		write(STDERR_FILENO, "unsetenv: variable not found\n", 29);
		thestatus = 2;
		return (FORKSKIIP);
	}

	env_ptr = environ + len;
	free(*env_ptr);
	while (*(env_ptr + 1) != NULL)
	{
		*env_ptr = *(env_ptr + 1);
		env_ptr++;
	}
	*env_ptr = NULL;
	thestatus = 0;

	return (FORKSKIIP);
}

/**
 * dirchan - chng path
 * @name: dircname
 *
 * Return: 0 good
 */
int dirchan(char *name)
{
	char *home;
	char *pwd;
	char old_path_buffer[PATH_MAX];
	char new_path_buffer[PATH_MAX];
	size_t buf_size = PATH_MAX;
	int i;

	getcwd(old_path_buffer, buf_size);

	if (name == NULL)
	{
		home = findaallarrayelemnt(environ, "HOME=");
		if (home == NULL)
		{
			thestatus = 2;
			theerrormessage("cd", name);
			return (FORKSKIIP);
		}

		home += 5;

		i = chdir((const char *)home);
		if (i != -1)
			envaset("PWD", (const char *)home);
	}
	else if (twostringcompare("-", name, MTAHTCEH) == TTRHUEE)
	{
		pwd = findaallarrayelemnt(environ, "OLDPWD=");
		if (pwd == NULL)
		{
			thestatus = 2;
			theerrormessage("cd", name);
			return (FORKSKIIP);
		}

		pwd += 7;

		i = chdir((const char *)pwd);
		if (i != -1)
		{
			write(STDOUT_FILENO, pwd, _lengthofstr(pwd));
			write(STDOUT_FILENO, "\n", 1);
			envaset("PWD", (const char *)pwd);
		}
	}
	else if (name != NULL)
	{
		i = chdir((const char *)name);
		if (i != -1)
			envaset("PWD", getcwd(new_path_buffer, buf_size));
	}
	if (i == -1)
	{
		thestatus = 2;
		theerrormessage("cd", name);
		return (FORKSKIIP);
	}

	thestatus = 0;
	envaset("OLDPWD", (const char *)old_path_buffer);

	return (FORKSKIIP);
}

/**
 * aliasfun - aliases deals
 * @args: the argument
 * @to_free: make it free
 *
 * Return: true , false
 * forscape suces
 */
int aliasfun(char **args, int to_free)
{
	static alias head = {NULL, NULL, NULL};
	char *char_ptr;
	int no_error = TTRHUEE;

	if (to_free == TTRHUEE)
		return (makealiasfree(head.next));

	if (twostringcompare("alias", *args, MTAHTCEH) != TTRHUEE)
		return (ifaliasesisfounded(args, head.next));

	args++;

	if (*args == NULL)
		return (aliassesprint(head.next));

	while (*args != NULL)
	{
		char_ptr = *args;
		while (*char_ptr != '\0' && *char_ptr != '=')
			char_ptr++;

		if (*char_ptr == '\0' || char_ptr == *args)
		{
			if (aliasval(*args, &head) == FTAHLSHE)
				no_error = FTAHLSHE;
		}
		else
		{
			*char_ptr = '\0';
			char_ptr++;
			aliassettt(*args, &head, char_ptr);
			*(char_ptr - 1) = '=';
		}
		args++;
	}

	if (no_error == FTAHLSHE)
		return (FORKSKIIP);

	thestatus = 0;
	return (FORKSKIIP);
}

/**
 * envaset - setenvirment
 * @name: name of var
 * @value: the value to seet
 *
 * Return: succesful or not
 */
int envaset(const char *name, const char *value)
{
	char **new_environ;
	char *buffer;
	char *buf_tmp;
	char *element_ptr;
	int len;

	if (value == NULL)
	{
		write(STDERR_FILENO, "setenv: no value given\n", 23);
		thestatus = 2;
		return (FORKSKIIP);
	}

	buffer = strinone((char *)name, "=");

	element_ptr = findaallarrayelemnt(environ, buffer);

	buf_tmp = strinone(buffer, (char *)value);
	free(buffer);
	buffer = buf_tmp;

	if (element_ptr == NULL)
	{
		len = lengthiflist(environ, NULL);
		new_environ = copyofarray(environ, len + 1);
		new_environ[len - 1] = buffer;
		new_environ[len] = NULL;
		arrayfree(environ);
		environ = new_environ;
		return (FORKSKIIP);
	}

	len = lengthiflist(environ, (char *)name);
	free(environ[len]);
	environ[len] = buffer;

	thestatus = 0;

	return (FORKSKIIP);
}
