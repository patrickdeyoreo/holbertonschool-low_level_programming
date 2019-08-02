#include "lists.h"

/**
 * list_len - get the length of a list
 * @h: address of the first node in the list
 *
 * Return: the length of list h
 */
size_t list_len(const list_t *h)
{
	return (h ? list_len(h->next) + 1 : 0);
}
