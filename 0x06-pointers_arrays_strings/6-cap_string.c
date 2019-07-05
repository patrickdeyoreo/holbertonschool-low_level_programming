#include "holberton.h"

/**
 * cap_string - capitalize the words in a strings
 * @s: the string to capitalize
 *
 * Description: The following characters are considered word separators:
 * "<space> <tab> <newline> , ; . ! ? \" ( ) { }"
 *
 * Return: pointer to the capitalized string
 */
char *cap_string(char *s)
{
	char *ws = " \t\n,;.!?\"(){}";
	int i;
	int j;

	for (i = 0, j = 0; s[i]; ++i)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			if (i)
			{
				for (j = 0; ws[j] && ws[j] != s[i - 1]; ++j)
					;
			}

			if (ws[j])
				s[i] -= ('a' - 'A');
		}
	}

	return (s);
}
