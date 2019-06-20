#include <stdio.h>
/**
 * main - entry point
 *
 * Description: Print the lowercase alphabet
 * Return: 0
 */
int main(void)
{
	for (char alpha = 'a'; alpha <= 'z'; ++alpha)
	{
		putchar(alpha);
	}
	putchar('\n');
	return (0);
}
