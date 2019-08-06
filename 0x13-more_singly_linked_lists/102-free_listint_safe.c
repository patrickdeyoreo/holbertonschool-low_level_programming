#include "lists.h"

/**
 * free_listint_safe - free all elements in a linked list
 * @head: a pointer to the first node
 *
 * Description: This function frees each node in a linked list, stopping if
 * it encounters a loop. To identify a loop, it constructs it's own list,
 * and if memory allocation fails, it causes the process to terminate with
 * the status value 98
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **head)
{
	listptr_t *listptr_head = NULL;
	listint_t *next;
	size_t size;

	if (!head)
		return (0);

	for (size = 0; *head; ++size)
	{
		if (listptr_contains(listptr_head, *head))
		{
			*head = NULL;
			break;
		}

		if (!add_nodeptr(&listptr_head, *head))
		{
			free_listptr(listptr_head);
			exit(98);
		}

		next = (*head)->next;
		free(*head);
		*head = next;
	}

	free_listptr(listptr_head);

	return (size);
}
