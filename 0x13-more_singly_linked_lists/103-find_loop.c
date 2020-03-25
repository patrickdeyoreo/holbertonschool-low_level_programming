#include "lists.h"

/**
 * find_listint_loop - find the beginning of a loop in a linked list
 * @head: a pointer to the first node
 *
 * Return: a pointer to first node in the loop, or NULL if no loop exists
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head ? head->next : NULL, *fast = slow;

	if (fast)
	{
		fast = fast->next;
		while (fast && fast != slow && (fast = fast->next))
		{
			fast = fast->next;
			slow = slow->next;
		}
		if (fast)
		{
			while (fast != head)
			{
				fast = fast->next;
				head = head->next;
			}
		}
	}
	return (fast);
}

/**
 * _find_listint_loop - find the beginning of a loop (helper function)
 * @head: a pointer to a pointer to the first node
 * @link: a pointer to a pointer to the current node
 *
 * Return: a pointer to first node in the loop, or NULL if no loop exists
 *
 *listint_t *_find_listint_loop(listint_t *head, listint_t **link)
 *{
 *	listint_t *current = *link;
 *
 *	if (!current)
 *		return (NULL);
 *
 *	*link = NULL;
 *
 *	if (is_linked(head, current))
 *	{
 *		*link = current;
 *		return (current);
 *	}
 *
 *	*link = current;
 *	return (_find_listint_loop(head, &current->next));
 *}
 * find_listint_loop - find the beginning of a loop in a linked list
 * @head: a pointer to the first node
 *
 * return: a pointer to first node in the loop, or NULL if no loop exists
 *
 *listint_t *find_listint_loop(listint_t *head)
 *{
 *	if (!head)
 *		return (NULL);
 *
 *	return (_find_listint_loop(head, &head->next));
 *}
 */
