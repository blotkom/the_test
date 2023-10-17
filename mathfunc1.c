#include "mhead.h"

/**
 * tiait - this func convert the int to the string
 * @n: the int code to be converted
 *
 * Return: the number that converted
 */
char *tiait(int n)
{
	char *buf = malloc(12);
	char *ptr = buf;
	int is_min = FTAHLSHE;
	int i_mask = 1000000000;
	int digit = 0;

	if (n == INT_MIN)
	{
		*ptr = '-';
		ptr++;
		n = INT_MAX;
		is_min = TTRHUEE;
	}

	if (n < 0)
	{
		*ptr = '-';
		ptr++;
		n = -n;
	}

	while (i_mask > 9 && digit == 0)
	{
		digit = n / i_mask;
		n %= i_mask;
		i_mask /= 10;
	}

	if (digit != 0)
	{
		*ptr = digit + '0';
		ptr++;
	}

	while (i_mask > 9)
	{
		digit = n / i_mask;
		*ptr = digit + '0';
		ptr++;
		n %= i_mask;
		i_mask /= 10;
	}

	if (is_min == TTRHUEE)
		n += 1;

	*ptr = n + '0';
	ptr++;
	*ptr = '\0';
	return (buf);
}
