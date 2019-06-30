#include <limits.h>
#include <math.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	int j;
	long a_lo = 1;
	long b_lo = 2;
	long a_hi = 0;
	long b_hi = 0;
	int limit_len = floor(log10(LONG_MAX / 2));
	long limit = pow(10, limit_len);

	for (i = 0; i < 98; ++i)
	{
		if (a_hi)
		{
			printf("%ld", a_hi);
			for (j = floor(log10(a_lo)) + 1; j < limit_len; ++j)
				putchar('0');
		}
		printf("%ld", a_lo);
		b_lo = b_lo + a_lo;
		a_lo = b_lo - a_lo;
		a_hi = b_hi - a_hi;
		b_hi = b_hi + a_hi;
		if (b_lo >= limit)
		{
			b_hi += b_lo / limit;
			b_lo %= limit;
			a_hi += a_lo / limit;
			a_lo %= limit;
		}
		if (i < 97)
			printf(", ");
	}
	putchar('\n');

	return (0);
}
