#include "shell.h"

/**
 * env - prints the current environ.
 * @arv: array of arguments
 */
void env(char **arv __attribute__ ((unused)))
{

	int d;

	for (d = 0; environ[d]; d++)
	{
		_puts(environ[d]);
		_puts("\n");
	}

}

/**
 * _setenv - Initialize a new environ. variable, or modify an existing one
 * @arv: array of indicated words
 */
void _setenv(char **arv)
{
	int d, c, f;

	if (!arv[1] || !arv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (d = 0; environ[d]; d++)
	{
		c = 0;
		if (arv[1][c] == environ[d][c])
		{
			while (arv[1][c])
			{
				if (arv[1][c] != environ[d][c])
					break;

				c++;
			}
			if (arv[1][c] == '\0')
			{
				f = 0;
				while (arv[2][f])
				{
					environ[d][c + 1 + f] = arv[2][f];
					f++;
				}
				environ[d][c + 1 + f] = '\0';
				return;
			}
		}
	}
	if (!environ[d])
	{

		environ[d] = concat_all(arv[1], "=", arv[2]);
		environ[d + 1] = '\0';

	}
}

/**
 * _unsetenv - Remove an environ variable
 * @arv: array of indicated words
 */
void _unsetenv(char **arv)
{
	int d, c;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (d = 0; environ[d]; d++)
	{
		c = 0;
		if (arv[1][c] == environ[d][c])
		{
			while (arv[1][c])
			{
				if (arv[1][c] != environ[d][c])
					break;

				c++;
			}
			if (arv[1][c] == '\0')
			{
				free(environ[d]);
				environ[d] = environ[d + 1];
				while (environ[d])
				{
					environ[d] = environ[d + 1];
					d++;
				}
				return;
			}
		}
	}
}
