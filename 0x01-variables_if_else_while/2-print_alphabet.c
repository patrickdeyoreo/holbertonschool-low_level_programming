#include <stdio.h>
/**
 * main - entry point
 *
 * Description: Print the lowercase alphabet
 * Return: 0
 */
int main(void)
{
	for (int c = 0; c < 26; ++c)
		putchar(c);

	putchar('\n');

	return (0);
}
