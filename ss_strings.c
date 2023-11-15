#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int d, p;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (p = 0; str[p] != '\0';)
	{
		p++;
	}
	new = malloc(sizeof(char) * p + 1);
	if (!new)
	{
		return (NULL);
	}
	for (d = 0; d < p; d++)
	{
		new[d] = str[d];
	}
	new[p] = str[p];
	return (new);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result;
	int d, p, a, k;

	p = _strlen(name);
	d = _strlen(sep);
	a = _strlen(value);

	result = malloc(p + d + a + 1);
	if (!result)
		return (NULL);

	for (k = 0; name[k]; k++)
		result[k] = name[k];
	a = k;

	for (d = 0; sep[d]; d++)
		result[a + d] = sep[d];
	a = a + d;

	for (p = 0; value[p]; p++)
		result[a + p] = value[p];
	a = a + p;

	result[a] = '\0';

	return (result);
}

/**
 * _strlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int _strlen(char *s)
{
	int d = 0;

	while (*(s + d) != '\0')
	{
		d++;
	}
	return (d);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: pointer to string
 */
void _puts(char *str)
{
	int d = 0;

	while (str[d])
	{
		_putchar(str[d]);
		d++;
	}
}
