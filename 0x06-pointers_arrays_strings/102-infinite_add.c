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
	char *n1_end = n1;
	char *n2_end = n2;
	int i;
	int j;

	do {
		++n1_end;
	} while (*n1_end);

	do {
		++n2_end;
	} while (*n2_end);

	for (i = 0; n1 < n1_end || n2 < n2_end; ++i)
	{
		if (size_r - 1 <= i)
			return 0;

		sum[i] = 0;

		if (n1 < n1_end)
			sum[i] += *(--n1_end) - '0';

		if (n2 < n2_end)
			sum[i] += *(--n2_end) - '0';

		if (i && sum[i - 1] > 9)
		{
			sum[i] += sum[i - 1] / 10;
			sum[i - 1] %=  10;
		}
	}

	if (sum[i - 1] > 9)
	{
		if (size_r - 1 <= i)
			return 0;
		sum[i] = sum[i - 1] / 10;
		sum[i - 1] %=  10;
		++i;
	}

	for (j = 0; i; ++j)
		r[j] = sum[--i] + '0';

	r[j] = '\0';

	return (r);
}
