#include <stdio.h>
#include <unistd.h>

/*
 * Prints a string to stderr using the write function
 * main - entry point
 * returns 1
 */
int main(void)
{
	const char s[] =
		"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(STDERR_FILENO, (const void *) s, sizeof(s) * sizeof(char) - 1);
	return (1);
}
