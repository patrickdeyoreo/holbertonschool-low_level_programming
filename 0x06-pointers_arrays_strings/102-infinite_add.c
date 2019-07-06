#include "holberton.h"

/**
 * infinite_add - adds two numbers
 * @n1: the first number to add
 * @n2: the other number to add
 * @r: the buffer to store the result in
 * @size_r: the size of the buffer
 *
 * Return: a pointer to the buffer r, unless the result does not fit in the
 * buffer in which case return 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char sum[size_r];
	char *n1_end;
	char *n2_end;
	char *r_end;
	int i;

	for (n1_end = n1; *n1_end; ++n1_end)
		;
	for (n2_end = n2; *n2_end; ++n2_end)
		;

	for (i = 0; n1 < n1_end || n2 < n2_end; ++i)
	{
		if (i == size_r - 1)
			return (0);

		if (i && sum[i - 1] > 9)
		{
			sum[i] = sum[i - 1] / 10;
			sum[i - 1] %=  10;
		}
		else
		{
			sum[i] = 0;
		}

		if (n1 < n1_end)
			sum[i] += *(--n1_end) - '0';

		if (n2 < n2_end)
			sum[i] += *(--n2_end) - '0';

	}

	if (sum[i - 1] > 9)
	{
		if (i == size_r - 1)
			return (0);

		sum[i] = sum[i - 1] / 10;
		sum[i - 1] %=  10;
		++i;
	}

	for (r_end = r; i; ++r_end)
		*r_end = sum[--i] + '0';

	*r_end = '\0';

	return (r);
}
