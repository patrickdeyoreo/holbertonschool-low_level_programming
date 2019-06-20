#include <unistd.h>

/*
 * Prints a string to stderr using the write function
 * main - entry point
 * returns 1
 */

int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
			59);
	return (1);
}
