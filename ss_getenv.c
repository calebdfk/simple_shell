#include "shell.h"


/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int d, c;
	char *value;

	if (!name)
		return (NULL);
	for (d = 0; environ[d]; d++)
	{
		c = 0;
		if (name[c] == environ[d][c])
		{
			while (name[c])
			{
				if (name[c] != environ[d][c])
					break;

				c++;
			}
			if (name[c] == '\0')
			{
				value = (environ[d] + c + 1);
				return (value);
			}
		}
	}
	return (0);
}
