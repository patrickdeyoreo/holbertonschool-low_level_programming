#include "lists.h"

/**
 * add_nodeint - add an element at the beginning of a linked list
 * @head: a pointer to a pointer to the first node
 * @n: the element to add
 *
 * Return: If memory allocation fails or head is NULL, return NULL.
 * Otherwise, return the address of the new node.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * print_listint_safe - print all elements in a linked list
 * @head: a pointer to the first node
 *
 * Description: This function will print the elements in a linked list.
 * It will stop upon encountering a loop. In order to identify a loop,
 * this function constructs it's own list. If memory allocation fails
 * while this list is being constructed, this function will causee the
 * process to terminate with the status 98
 *
 * Return: the number of list elements
 */
size_t print_listint_safe(const listint_t *head)
{
}



