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
	char s_min[max_digits + 2];
	char s_max[max_digits + 2];
	sprintf(s_min, "%d", INT_MIN);
	sprintf(s_max, "%d", INT_MAX);

	printf("%s: ", "98");
	n = _atoi("98");
	printf("Converting %s\n", "98");
	printf("%d\n", n);
	n = _atoi("-402");
	printf("Converting %s\n", "-402");
	printf("%d\n", n);
	n = _atoi("          ------++++++-----+++++--98");
	printf("Converting %s\n", "          ------++++++-----+++++--98");
	printf("%d\n", n);
	n = _atoi("214748364");
	printf("Converting %s\n", "214748364");
	printf("%d\n", n);
	n = _atoi("0");
	printf("Converting %s\n", "0");
	printf("%d\n", n);
	n = _atoi("Suite 402");
	printf("Converting %s\n", "Suite 402");
	printf("%d\n", n);
	n = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
	printf("Converting %s\n", "         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
	printf("%d\n", n);
	n = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
	printf("Converting %s\n", "---++++ -++ Sui - te -   402 #cisfun :)");
	printf("%d\n", n);
	n = _atoi(s_min);
	printf("Converting %s\n", s_min);
	printf("%d\n", n);
	n = _atoi(s_max);
	printf("Converting %s\n", s_max);
	printf("%d\n", n);
	return (0);
}
