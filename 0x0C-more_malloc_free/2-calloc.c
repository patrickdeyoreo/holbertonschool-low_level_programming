#include "holberton.h"

/**
 * _calloc - dynamically allocate memory for an array and initialize it to zero
 * @nmemb: the number of array members
 * @size: the size of each array member
 *
 * Return: If memory allocation fails or either argument is zero, return NULL.
 * Otherwise, return a pointer to the newly allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	char *b;
	unsigned int i, j;

	if (!(nmemb && size))
		return (NULL);

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);

	for (b = p, i = 0; i < nmemb; ++i)
	{
		for (j = 0; j < size / sizeof(char); ++j)
			b[i + j] = 0;
		for (j = 0; j < size % sizeof(char); ++j)
			b[i + j * size / sizeof(char)] = 0;
	}

	return (p);
}
