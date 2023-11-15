#include "shell.h"

/**
 * exitd - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void exitd(char **arv)
{
	int d, n;

	if (arv[1])
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		freearv(arv);
		exit(n);
	}
	for (d = 0; arv[d]; d++)
		free(arv[d]);
	free(arv);
	exit(0);
}

/**
 * _atoi - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(char *s)
{
	int d, integer, sign = 1;

	d = 0;
	integer = 0;
	while (!((s[d] >= '0') && (s[d] <= '9')) && (s[d] != '\0'))
	{
		if (s[d] == '-')
		{
			sign = sign * (-1);
		}
		d++;
	}
	while ((s[d] >= '0') && (s[d] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[d] - '0'));
		d++;
	}
	return (integer);
}
