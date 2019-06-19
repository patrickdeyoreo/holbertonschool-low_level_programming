#include <stdio.h>

#define PRINT_SIZE(TYPE) \
	printf("Size of a " #TYPE ": %zd byte(s)\n", sizeof(TYPE))

int main(int argc, const char *argv[])
{
	PRINT_SIZE(char);
	PRINT_SIZE(int);
	PRINT_SIZE(long int);
	PRINT_SIZE(long long int);
	PRINT_SIZE(float);
	return (0);
}
