#include "holberton.h"

/**
 * argstostr - concatenate all arguments into a new string
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: NULL memory allocation fails, ac is 0 or av is NULL,
 * otherwise return a pointer to the new string
 */
char *argstostr(int ac, char **av)
{
	char *cat, *chr;
	int arg, size;

	if (!ac || !av)
		return (NULL);

	for (arg = 0, size = 1; arg < ac; ++arg, ++size)
	{
		for (chr = av[arg]; *chr; ++chr, ++size)
			;
	}

	cat = (char *) malloc(sizeof(char) * size);

	if (!cat)
		return (NULL);

	for (arg = 0, size = 0; arg < ac; ++arg, ++size)
	{
		for (chr = av[arg]; *chr; ++chr, ++size)
			cat[size] = *chr;
		cat[size] = '\n';
	}

	cat[size] = '\0';

	return (cat);
}
