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

	p = malloc(size * nmemb);
	if (!p)
		return (NULL);

	for (b = p, j = 0; j < nmemb; ++j)
	{
		for (i = 0; i < size / sizeof(char); ++i)
			b[i + j] = '\0';
	}

	return (p);
}
