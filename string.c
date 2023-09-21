#include "main.h"

/**
 * strd_up - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */

char *strd_up(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * _concatall - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */

char *_concatall(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = str_len(name);
	l2 = str_len(sep);
	l3 = str_len(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * str_len - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */

int str_len(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * put_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts_ - prints a string
 * @str: pointer to string
 */

void _puts_(char *str)
{
	int i = 0;

	while (str[i])
	{
		put_char(str[i]);
		i++;
	}
}

