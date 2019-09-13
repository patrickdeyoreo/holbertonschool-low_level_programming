#include "lists.h"

/**
 * print_dlistint - print a doubly-linked list
 * @h: pointer to the head of the list
 *
 * Return: list length
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;

	for ( ; h; h = h->next)
	{
		printf("%d\n", h->n);
		++len;
	}
	return (len);
}
