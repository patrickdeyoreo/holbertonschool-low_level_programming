#include "holberton.h"

/**
 * _isspace - check if a character is whitespace
 * @c: the character to check
 *
 * Return: 1 is c is a whitespace character, otherwise 0
 */
int _isspace(int c)
{
	if (c == 0x20 || (c >= 0x09 && c <= 0x0d))
		return (1);
	return (0);
}


/**
 * strtow - split a string into words
 * @str: a pointer to the string to split
 *
 * Return: NULL if memory allocation fails or if str is NULL or empty (""),
 * otherwise return a pointer to the array of words terminated by a NULL
 */
char **strtow(char *str)
{
	char **words, *pos = str;
	int w = 0, c = 0;

	if (!(str && *str))
		return (NULL);
	do {
		while (_isspace(*pos))
			++pos;
		if (!*pos)
			break;
		while (*pos && !_isspace(*pos))
			++pos;
	} while (++w, *pos);
	words = (char **) malloc(sizeof(char *) * (w + 1));
	if (!words)
		return (NULL);
	pos = str;
	w = 0;
	do {
		while (_isspace(*pos))
			++pos;
		if (!*pos)
			break;
		for (str = pos; *pos && !_isspace(*pos); ++pos)
			;
		words[w] = (char *) malloc(sizeof(char) * (pos - str + 1));
		if (!words[w])
		{
			while (--w > -1)
				free(words[w]);
			free(words);
			return (NULL);
		}
		for (c = 0; str < pos; ++c, ++str)
			words[w][c] = *str;
		words[w][c] = '\0';
	} while (++w, *pos);
	words[w] = NULL;
	return (words);
}
