#include <stdio.h>

/**
 * main - entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long int a = 1;
	unsigned long int b = 2;

	for (i = 0; i < 98; ++i)
	{
		printf("%lu", a);
		if (i < 97)
		{
			b += a;
			a = b - a;
			printf(", ");
		}
	}

	putchar('\n');

	return (0);
}
