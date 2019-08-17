#include <unistd.h>
#include <stdio.h>

int main(int argc __attribute__((unused)), const char *argv[])
{
	unsigned int i = 0;

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		++i;
	}
	return (0);
}
