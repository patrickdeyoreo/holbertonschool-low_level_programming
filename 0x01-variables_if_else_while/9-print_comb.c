#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Print all possible combinations of single-digit numbers
 * Return: 0
 */
int main(void)
{
	int i = 0;

	for (i = 0; i < 10; ++i)
	{
		putchar('0' + i);

		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
