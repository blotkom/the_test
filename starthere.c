#include "mhead.h"

int thestatus = 0;

int numberoflines = 1;

char *the_name_of_shell = NULL;

/**
 * main - the first code
 * @ac: the umber if inouts
 * @av: array if intout
 *
 * Return: 0 ot 1
 */
int main(__attribute__((unused))int ac, char **av)
{
	int thebytesss;
	int separretedorno = FTAHLSHE;
	int i;
	size_t buf_size = 1;
	char *buf = NULL;
	char *buf_ptr;
	char *buf_tmp;
	char **args = NULL;

	the_name_of_shell = _stingduplicaing(*av);

	environ = copyofarray(environ, lengthiflist(environ, NULL));

	signal(SIGINT, SIG_IGN);

	buf = malloc(1);
	if (buf == NULL)
		exit(EXIT_FAILURE);

	while (1)
	{
		if (separretedorno == FTAHLSHE)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "my_shell$ ", 10);

			thebytesss = getline(&buf, &buf_size, stdin);

			if (thebytesss == -1)
				break;
			if (thebytesss == 1)
			{
				numberoflines++;
				continue;
			}
			buf[thebytesss - 1] = '\0';
			buf = theinpuutscaan(buf, &buf_size);
			if (buf_size == 0)
			{
				numberoflines++;
				continue;
			}
			buf_ptr = buf;
		}
		else
			buf_ptr = buf_tmp;

		buf_tmp = NULL;
		args = arraymaker(buf_ptr, ' ', &buf_tmp);
		if (buf_tmp != NULL)
			separretedorno = TTRHUEE;
		else
			separretedorno = FTAHLSHE;

		i = moondmang_gerfunct(args);

		free(args);

		if (separretedorno == FTAHLSHE)
			numberoflines++;

		if (i == EXITCCODE)
			break;
	}
	free(buf);
	aliasfun(NULL, TTRHUEE);
	arrayfree(environ);
	free(the_name_of_shell);

	return (thestatus % 256);
}
