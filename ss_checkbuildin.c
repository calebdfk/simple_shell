#include "shell.h"

/**
* checkbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkbuild(char **arv))(char **arv)
{
	int d, c;
	mybuild T[] = {
		{"exit", exitt},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (d = 0; T[d].name; d++)
	{
		c = 0;
		if (T[d].name[c] == arv[0][c])
		{
			for (c = 0; arv[0][c]; c++)
			{
				if (T[d].name[c] != arv[0][c])
					break;
			}
			if (!arv[0][c])
				return (T[d].func);
		}
	}
	return (0);
}
