#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sort.h"

#define ITERATIONS 5
#define MAX_SIZE 13
#define MAX_VALUE 100
#define SEPARATOR "---"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int *array = NULL, *position = NULL;
	size_t n = MAX_SIZE;
	unsigned int i = 0;

	srandom((unsigned int) time(NULL));

	while (i++ < ITERATIONS)
	{
		array = malloc(sizeof(*array) * n);
		if (!array)
		{
			fprintf(stderr, "Could not allocate %lu bytes\n", n);
			exit(1);
		}
		for (position = array; position < array + n; ++position)
			*position = random() % MAX_VALUE;

		print_array(array, n);
		sleep(1);
		bubble_sort(array, n);
		free(array);
		if (i < ITERATIONS)
		{
			puts(SEPARATOR);
			sleep(1);
		}
	}
	return (0);
}
