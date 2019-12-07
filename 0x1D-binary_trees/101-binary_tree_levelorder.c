#include "binary_trees.h"

/**
 * pqueue_create - dynamically allocate and initialize a new queue node
 * @item: the binary tree node to insert
 * @pri: the priority of the item
 *
 * Return: a pointer to the new node
 */
pqueue_t *pqueue_create(const bt_t *item, size_t pri)
{
	pqueue_t *node = calloc(1, sizeof(*node));

	if (node)
	{
		node->item = item;
		node->pri = pri;
	}
	return (node);
}

/**
 * pqueue_delete - delete an entire priority queue
 * @head: a pointer to the head of the queue
 */
void pqueue_delete(pqueue_t **head)
{
	pqueue_t *temp = NULL;

	while ((temp = *head))
	{
		*head = (*head)->next;
		free(temp);
	}
}
/**
 * pqueue_insert_sorted - insert an item into a sorted priority queue
 * @head: a double pointer to the head of a queue
 * @node: a pointer to the node to be added to the queue
 *
 * Return: a pointer to the head of the queue
 */
pqueue_t *pqueue_insert_sorted(pqueue_t **head, pqueue_t *node)
{
	if (head)
	{
		if (*head)
		{
			if (node->pri >= (*head)->pri)
			{
				pqueue_insert_sorted(&((*head)->next), node);
				return (*head);
			}
			node->next = *head;
		}
		return ((*head = node));
	}
	return (NULL);
}

/**
 * bt_to_pqueue - build the priority queue
 * @tree: the tree from which to construct a priority queue
 * @head: a double pointer to the head of the queue
 * @depth: current depth of recursion within this function
 *
 * Return: a pointer to the head of the queue
 */
pqueue_t *bt_to_pqueue(const bt_t *tree, pqueue_t **head, size_t depth)
{
	pqueue_t *temp = NULL;

	if (head)
	{
		if (tree)
		{
			bt_to_pqueue(tree->left, head, depth + 1);
			bt_to_pqueue(tree->right, head, depth + 1);
			temp = pqueue_create(tree, depth);
			if (temp)
				pqueue_insert_sorted(head, temp);
			else
				pqueue_delete(head);
		}
		return (*head);
	}
	return (NULL);
}

/**
 * binary_tree_levelorder - perform level-order traversal on a binary tree
 * @tree: the tree to traverse
 * @func: the function to apply
 */
void binary_tree_levelorder(const bt_t *tree, void (*func)(int))
{
	pqueue_t *head = NULL;
	pqueue_t *temp = NULL;

	if (tree && func)
	{
		bt_to_pqueue(tree, &head, 0);
		if (head)
		{
			while ((temp = head))
			{
				func(head->item->n);
				head = head->next;
				free(temp);
			}

		}
	}
}
