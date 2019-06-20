#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point
 *
 * Returns: 0
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is %s\n", n % 10,
		(n > 5) ? "and is greater than 5"
			: ((n == 0) ? "and is 0"
				    : "and is less than 6 and not 0"));

	return (0);
}
