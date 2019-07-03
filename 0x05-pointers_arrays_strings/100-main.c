#include "holberton.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int max_digits = floor(log10(INT_MAX)) + 2;
	char s_lt_min[max_digits + 2];
	char s_gt_max[max_digits + 2];
	sprintf(s_lt_min, "%ld", (long) INT_MIN - 1);
	sprintf(s_gt_max, "%ld", (long) INT_MAX + 1);

	printf("Converting %s\n", "98");
	n = _atoi("98");
	printf("%d\n", n);

	printf("Converting %s\n", "-402");
	n = _atoi("-402");
	printf("%d\n", n);

	printf("Converting %s\n", "          ------++++++-----+++++--98");
	n = _atoi("          ------++++++-----+++++--98");
	printf("%d\n", n);

	printf("Converting %s\n", "214748364");
	n = _atoi("214748364");
	printf("%d\n", n);

	printf("Converting %s\n", "0");
	n = _atoi("0");
	printf("%d\n", n);

	printf("Converting %s\n", "Suite 402");
	n = _atoi("Suite 402");
	printf("%d\n", n);

	printf("Converting %s\n", "         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
	n = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
	printf("%d\n", n);

	printf("Converting %s\n", "---++++ -++ Sui - te -   402 #cisfun :)");
	n = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
	printf("%d\n", n);

	printf("Converting %s\n", s_lt_min);
	n = _atoi(s_lt_min);
	printf("%d\n", n);

	printf("Converting %s\n", s_gt_max);
	n = _atoi(s_gt_max);
	printf("%d\n", n);

	printf("Converting %s\n", "-4500000000");
	n = _atoi("-4500000000");
	printf("%d\n", n);

	printf("Converting %s\n", "4500000000");
	n = _atoi("4500000000");
	printf("%d\n", n);

	printf("Converting %s\n", "0 - 1");
	n = _atoi("0 - 1");
	printf("%d\n", n);

	return (0);
}
