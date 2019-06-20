#include <unistd.h>

/**
 * main - entry point
 * Description: Print a string to stderr using the write function
 * Return: 1
*/
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
			59);
	return (1);
}
