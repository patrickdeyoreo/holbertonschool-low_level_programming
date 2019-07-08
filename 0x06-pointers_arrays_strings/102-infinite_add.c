#include "holberton.h"

/**
 * infinite_add - adds two numbers
 * @n1: the first number to add
 * @n2: the other number to add
 * @r: the buffer to store the result
 * @size_r: the size of the buffer
 *
 * Return: a pointer to the buffer r, unless the result does not fit into r,
 * in which case return 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char r_temp[size_r];
	char *n1_end;
	char *n2_end;
	int i, j;

	for ( ; n1[1] && *n1 == '0'; ++n1)
		;
	for ( ; n2[1] && *n2 == '0'; ++n2)
		;
	for (n1_end = n1; *n1_end; ++n1_end)
		;
	for (n2_end = n2; *n2_end; ++n2_end)
		;
	for (i = 0; n1 < n1_end || n2 < n2_end; ++i)
	{
		if (i + 1 >= size_r)
			return (0);
		r_temp[i] = 0;
		if (i && r_temp[i - 1] > 9)
		{
			r_temp[i] = r_temp[i - 1] / 10;
			r_temp[i - 1] %= 10;
		}
		if (n1 < n1_end)
			r_temp[i] += *(--n1_end) - '0';
		if (n2 < n2_end)
			r_temp[i] += *(--n2_end) - '0';
	}
	if (r_temp[i - 1] > 9)
	{
		if (i + 1 >= size_r)
			return (0);
		r_temp[i] = r_temp[i - 1] / 10;
		r_temp[i - 1] %= 10;
		++i;
	}
	for (j = 0; i > 0; ++j)
		r[j] = r_temp[--i] + '0';
	r[j] = '\0';
	return (r);
}
