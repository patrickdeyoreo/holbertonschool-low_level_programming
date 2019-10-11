#include "hash_tables.h"

/**
 * hash_djb2 - compute a hash using the djb2 algorithm
 * @str: a pointer to the string to hash
 *
 * Return: hash of str
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}
