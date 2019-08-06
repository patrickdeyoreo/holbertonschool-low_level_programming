#include "lists.h"

/**
 * is_linked - check if a node is already in a linked list
 * @head: a pointer to the first node in a list
 * @node: the address of to the node to find
 *
 * Return: 1 if the node in the list, 0 otherwise
 */
int is_linked(const listint_t *head, const listint_t *node)
{
	if (!head)
		return (0);

	return (head == node || is_linked(head->next, node));
}

/**
 * _find_listint_loop - find the beginning of a loop (helper function)
 * @head: a pointer to a pointer to the first node
 * @link: a pointer to a pointer to the current node
 *
 * Return: a pointer to first node in the loop, or NULL if no loop exists
 */
listint_t *_find_listint_loop(listint_t *head, listint_t **link)
{
	listint_t *current = *link;

	if (!current)
		return (NULL);

	*link = NULL;

	if (is_linked(head, current))
	{
		*link = current;
		return (current);
	}

	*link = current;
	return (_find_listint_loop(head, &current->next));
}

/**
 * find_listint_loop - find the beginning of a loop in a linked list
 * @head: a pointer to the first node
 *
 * Return: a pointer to first node in the loop, or NULL if no loop exists
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (!head)
		return (NULL);

	return (_find_listint_loop(head, &head->next));
}
