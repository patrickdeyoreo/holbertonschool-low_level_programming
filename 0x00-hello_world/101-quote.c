#include <stdio.h> 
#include <unistd.h> 

/* Prints a string to stderr using write() instead of printf() or puts() */
int main(void)
{
	const char str[] =
		"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(STDERR_FILENO, (const void *) str, sizeof(str) * sizeof(char) - 1);
	return (1);
}
