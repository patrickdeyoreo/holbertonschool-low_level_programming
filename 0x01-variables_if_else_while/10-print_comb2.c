#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Write a program that prints the numbers from 00 to 99
 * Return: 0
 */
int main(void)
{
	int digits[2] = { 0, 0 };
	int sep[2] = { ',', ' ' };
	int i = 0;

	for (digits[0] = 0; digits[0] < 10; ++(digits[0]))
	{
		for (digits[1] = 0; digits[1] < 10; ++(digits[1]))
		{
			for (i = 0; i < 2; ++i)
				putchar('0' + digits[i]);

			if (digits[0] != 9 || digits[1] != 9)
			{
				for (i = 0; i < 2; ++i)
					putchar(sep[i]);
			}
		}
	}

	putchar('\n');

	return (0);
}
