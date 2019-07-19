#include "holberton.h"

/**
 * malloc_checked - allocate dynamic memory using malloc
 * @b: the number of bytes to allocate
 *
 * Description: If memory allocation fails, cause normal process termination
 * with a status value of 98.
 *
 * Return: Upon success, return a pointer to the newly allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p)
		return (p);
	exit(98);
}
