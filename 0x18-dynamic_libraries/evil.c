#include <stdlib.h>
#include <time.h>


/**
 * atoi - atoi override
 * @nptr: string to convert
 *
 * Return: winning numbers at 98 seconds
 */
int atoi(const char *nptr __attribute__((unused)))
{
	static int i;

	switch (i++)
	{
	case 0:
		return (68);
	case 1:
		return (1);
	case 2:
		return (19);
	case 3:
		return (38);
	case 4:
		return (7);
	case 5:
		return (2);
	}
	return (0);
}


/**
 * time - time override
 * @tloc: time structure
 *
 * Return: Always 98
 */
time_t time(time_t *tloc __attribute__((unused)))
{
	return 98;
}
