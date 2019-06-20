#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Prints a number and whether it is positive, negative or zero.
 *
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("%d is %s\n", n, (n > 0) ? "positive"
					: ((n < 0) ? "negative" : "zero"));
	return (0);
}
