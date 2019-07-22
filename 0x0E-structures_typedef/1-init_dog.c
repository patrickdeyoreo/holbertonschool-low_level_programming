#include "dog.h"


/**
 * _strdup - create a new array containing a copy of the given string
 * @str: a pointer to the string to copy
 *
 * Return: If str is NULL or memory allocation fails, return NULL.
 * Otherwise return a pointer to the new copy.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len = 0;

	if (!str)
		return (NULL);

	while (str[len])
		++len;

	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);

	do {
		dup[len] = str[len];
	} while (len--);

	return (dup);
}


/**
 * init_dog  - initialize a variable of type struct dog
 * @d: a pointer to the struct dog variable
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the name of the owner of the dog
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = _strdup(name);
	d->age = age;
	d->owner = _strdup(owner);
}
