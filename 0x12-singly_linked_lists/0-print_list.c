#include "lists.h"

/**
 * print_list - print list items
 * @h: the list to print
 *
 * Description: Print each list item, prefixed by it's length, formatted using
 * "[%d] %s\n". If a list item is NULL, print it as "(nil)" with zero length.
 */
size_t print_list(const list_t *h)
{
	if (h)
	{
		printf("[%d] %s\n", h->len, h->str ? h->str : "(nil)");
		return(print_list(h->next) + 1);
	}
	return 0;
}
