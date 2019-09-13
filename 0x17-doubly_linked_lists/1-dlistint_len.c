#include "lists.h"

/**
 * dlistint_len - get the length of a double-linked list
 * @h: pointer to the head of the list
 *
 * Return: list length
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	for ( ; h; h = h->next)
		++len;

	return (len);
}
