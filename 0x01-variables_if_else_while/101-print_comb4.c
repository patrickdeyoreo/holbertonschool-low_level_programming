#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Print all possible different combinations of two digits
 * Return: 0
 */
int main(void)
{
	int i;
	int j;
	int k;

	for (i = 0; i < 10; ++i)
	{
		for (j = i + 1; j < 10; ++j)
		{
			for (k = j + 1; k < 10; ++k)
			{
				putchar('0' + i);
				putchar('0' + j);
				putchar('0' + k);

				if (i != 7 || j != 8 || k != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
