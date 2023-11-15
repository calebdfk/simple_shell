#include "shell.h"

/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *str, const char *delim)
{
	int d, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	d = 0;
	while (str[d])
	{
		copy[d] = str[d];
		d++;
	}
	copy[d] = '\0';

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	d = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[d] = _strdup(token);
		d++;
		wn++;
	}
	free(copy);
	return (array);
}
