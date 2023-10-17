#include "mhead.h"

int thestatus;

char *the_name_of_shell;

/**
 * coomdodexucutes - get cooomnd and excutes
 * @args: thecooomds and argumments
 *
 * Return: TTRHUEE or EXITCCODE
 */
int coomdodexucutes(char **args)
{
	char *buf_ptr = *args;
	char *command_name;
	pid_t pid;
	int what_do = thebuilti_nfunctons(args);

	if (what_do == EXCUTTEU_DO_BRO)
	{
		command_name = comondschecker(args);
		if (command_name == NULL)
			return (FTAHLSHE);

		pid = fork();
		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execve(command_name, args, environ);
			exit(EXIT_FAILURE);
		}
		wait(&thestatus);
		free(command_name);
		fflush(stdin);
		if (thestatus != 0)
		thestatus = 2;
	}

	if (twostringcompare("false", *args, MTAHTCEH) == TTRHUEE)
		thestatus = 1;

	if (*args != buf_ptr)
		free(*args);
	args++;

	while (*args != NULL)
	{
		while (*buf_ptr != '\0')
		{
			buf_ptr++;
		}
		buf_ptr++;

		if (*args != buf_ptr)
			free(*args);

		args++;
	}

	if (what_do == EXITCCODE)
		return (EXITCCODE);

	if (thestatus != 0)
		return (FTAHLSHE);

	return (TTRHUEE);
}

/**
 * thebuilti_nfunctons - chheck commond are in buidlt
 * @args: the coomond and argummentsf
 *
 * Return: Rreturn zerio and onr for each
 * exit not exist or not exit to exit
 */
int thebuilti_nfunctons(char **args)
{
	char **args_ptr = args;
	int i;

	while (*args_ptr != NULL)
	{
		if (**args_ptr == '#')
		{
			*args_ptr = NULL;
			break;
		}
		if (twostringcompare("~", *args_ptr, MTAHTCEH) == TTRHUEE
		    && findaallarrayelemnt(environ, "HOME=") != NULL)
		{
			*args_ptr = _stingduplicaing(findaallarrayelemnt
					(environ, "HOME=") + 5);
			continue;
		}
		if (twostringcompare("~/", *args_ptr, PTRGEPFXIX) == TTRHUEE
		    && findaallarrayelemnt(environ, "HOME=") != NULL)
		{
			*args_ptr = strinone(findaallarrayelemnt
					       (environ, "HOME=")
					       + 5, *args_ptr + 1);
		}
		*args_ptr = checkvarrs(*args_ptr);

		args_ptr++;
	}
	if (*args == NULL)
		return (FORKSKIIP);

	i = aliasfun(args, FTAHLSHE);
	if (i == EXCUTTEU_DO_BRO || i == FORKSKIIP)
		return (i);

	if (twostringcompare("exit", *args, MTAHTCEH) == TTRHUEE && args[1] != NULL)
	{
		thestatus = _tato(args[1]);
		if (thestatus < 0)
		{
			thestatus = 2;
			theerrormessage(args[0], args[1]);
			return (FORKSKIIP);
		}
	}
	if (twostringcompare("exit", *args, MTAHTCEH) == TTRHUEE)
		return (EXITCCODE);
	else if (twostringcompare("setenv", *args, MTAHTCEH) == TTRHUEE && args[1] != NULL)
		return (envaset(args[1], args[2]));
	else if (twostringcompare("unsetenv", *args, MTAHTCEH) == TTRHUEE
		 && args[1] != NULL)
		return (_varunse(args[1]));
	else if (twostringcompare("cd", *args, MTAHTCEH) == TTRHUEE)
		return (dirchan(args[1]));
	else if (twostringcompare("env", *args, MTAHTCEH) == TTRHUEE)
		return (envpriiint());

	return (EXCUTTEU_DO_BRO);
}

/**
 * theandoorfunct - this ficntion for logivcal operator
 * @args: the argumebnt
 * @operator: firstt charlogicaloperator
 * @last_compare: if the last is zero or not
 *
 * Return: return zero one depend on the result
 */
int theandoorfunct(char **args, char operator, int last_compare)
{
	int i;

	if (last_compare == NOTTHATANDTHAT)
	{
		i = coomdodexucutes(args);
		if (i == EXITCCODE)
			return (EXITCCODE);
		if (i == TTRHUEE)
			return (TTRHUEE);

		return (FTAHLSHE);
	}
	if (last_compare == TTRHUEE && operator == '&')
	{
		i = coomdodexucutes(args);
		if (i == EXITCCODE)
			return (EXITCCODE);
		if (i == TTRHUEE)
			return (TTRHUEE);

		return (FTAHLSHE);
	}

	if (last_compare == FTAHLSHE && operator == '|')
	{
		i = coomdodexucutes(args);
		if (i == EXITCCODE)
			return (EXITCCODE);
		if (i == TTRHUEE)
			return (TTRHUEE);

		return (FTAHLSHE);
	}

	if (last_compare == TTRHUEE && operator == '|')
		return (TTRHUEE);

	return (FTAHLSHE);
}

/**
 * moondmang_gerfunct - this function manamge process egt
 * @args: arggumnnent and coomnonds
 *
 * Return: TTRHUEE if success, FTAHLSHE if failure
 */
int moondmang_gerfunct(char **args)
{
	char **args_ptr = args;
	int prev_eval = NOTTHATANDTHAT;
	int no_err = TTRHUEE;
	char prev_op = 'c';
	char next_op = 'c';
	int what_do;

	while (*args != NULL && prev_eval != EXITCCODE)
	{
		while (*args_ptr != NULL && **args_ptr != '&'
		       && **args_ptr != '|')
			args_ptr++;

		if (twostringcompare(*args_ptr, "||", MTAHTCEH) == TTRHUEE)
		{
			*args_ptr = NULL;
			args_ptr++;
			next_op = '|';
		}
		if (twostringcompare(*args_ptr, "&&", MTAHTCEH) == TTRHUEE)
		{
			*args_ptr = NULL;
			args_ptr++;
			next_op = '&';
		}
		if (next_op == 'c')
			break;

		prev_eval = theandoorfunct(args, prev_op, prev_eval);
		if (prev_eval == FTAHLSHE)
			no_err = FTAHLSHE;
		prev_op = next_op;
		args = args_ptr;
	}

	if (next_op == 'c')
	{
		what_do = coomdodexucutes(args);

		if (what_do == EXITCCODE)
			return (EXITCCODE);
	}

	if (no_err == FTAHLSHE || what_do == FTAHLSHE)
		return (FTAHLSHE);

	return (TTRHUEE);
}

/**
 * comondschecker - nonbuilt check if not excutes
 * @args: theall argimemtn
 *
 * Return: return zeo or one for vf
 */
char *comondschecker(char **args)
{
	char *command_buf;
	char *full_buf;
	char *path_str = NULL;
	char *path_ptr;
	char *path_tmp;
	char **path_var = NULL;
	char **path_var_ptr;

	if (access(*args, X_OK) == 0)
		return (_stingduplicaing(*args));

	if (findaallarrayelemnt(environ, "PATH=") != NULL)
		path_str = _stingduplicaing(findaallarrayelemnt(environ, "PATH=") + 5);

	path_ptr = path_str;

	if (path_str != NULL)
	{
		if (*path_str == ':')
		{
			command_buf = strinone("./", *args);
			if (access(command_buf, X_OK) == 0)
			{
				free(path_str);
				return (command_buf);
			}
			else
			{
				free(command_buf);
				path_ptr = _stingduplicaing(path_str + 1);
				free(path_str);
				path_str = path_ptr;
			}
		}
		while (*path_ptr != '\0')
		{
			if (*path_ptr == ':' && *(path_ptr + 1) == ':')
			{
				*(path_ptr + 1) = '\0';
				path_tmp = (strinone(path_str, ".:"));
				path_ptr = strinone(path_tmp, path_ptr + 2);
				free(path_str);
				free(path_tmp);
				path_str = path_ptr;
			}
			path_ptr++;
		}
	}
	if (path_str != NULL)
		path_var = arraymaker(path_str, ':', NULL);

	path_var_ptr = path_var;

	command_buf = strinone("/", *args);

	full_buf = _stingduplicaing(command_buf);

	if (path_var != NULL)
	{
		while (*path_var_ptr != NULL && access(full_buf, X_OK) != 0)
		{
			free(full_buf);
			full_buf = strinone(*path_var_ptr, command_buf);
			path_var_ptr++;
		}
	}

	free(command_buf);
	free(path_str);
	free(path_var);

	if (access(full_buf, X_OK) != 0)
	{
		theerrormessage(args[0], NULL);
		free(full_buf);
		return (NULL);
	}

	return (full_buf);
}
