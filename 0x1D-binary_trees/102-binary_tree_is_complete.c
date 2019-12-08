#include "binary_trees.h"

/**
 * pqueue_pop - pop an item from a priority queue
 * @front: a pointer to the front of the queue
 *
 * Return: a pointer to the popped element
 */
const void *pqueue_pop(pqueue_t **front)
{
	const void *item = NULL;
	pqueue_t *temp = NULL;

	if (front)
	{
		temp = *front;
		if (temp)
		{
			*front = temp->next;
			item = temp->item;
			free(temp);
			return (item);
		}
	}
	return (NULL);
}

/**
 * pqueue_delete - delete a priority queue
 * @front: a pointer to the front of a queue
 */
void pqueue_delete(pqueue_t *front)
{
	pqueue_t *temp = NULL;

	while ((temp = front))
	{
		front = front->next;
		free(temp);
	}
}

/**
 * pqueue_insert - insert an item into a priority queue
 * @front: a double pointer to the front of a queue
 * @item: a pointer to the item to queue
 * @priority: the item's priority
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *pqueue_insert(pqueue_t **front, const void *item, size_t priority)
{
	pqueue_t *temp = NULL;

	if (front)
	{
		if (*front && priority >= (*front)->priority)
			return (pqueue_insert(&((*front)->next), item, priority));

		temp = malloc(sizeof(*temp));
		if (temp)
		{
			temp->item = item;
			temp->next = *front;
			temp->priority = priority;
			return ((*front = temp));
		}
	}
	return (NULL);
}

/**
 * binary_tree_to_pqueue - queue binary tree nodes in ascending order by depth
 * @tree: a tree from which to construct the queue
 * @front: a double pointer to the front of the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *binary_tree_to_pqueue(pqueue_t **front, const binary_tree_t *tree)
{
	static size_t priority;

	if (front)
	{
		priority += 1;
		if (tree)
		{
			binary_tree_to_pqueue(front, tree->left);
			binary_tree_to_pqueue(front, tree->right);
			pqueue_insert(front, tree, priority);
		}
		priority -= 1;
		return (*front);
	}
	return (NULL);
}

/**
 * binary_tree_is_complete - determine if a binary tree is complete
 * @tree: a pointer to the root of the tree to examine
 *
 * Return: If tree is NULL or the tree is not complete, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_complete(const bt_t *tree)
{
	const bt_t *bt = NULL;
	pqueue_t *front = NULL;
	int full = 1;

	if (binary_tree_to_pqueue(&front, tree))
	{
		while ((bt = pqueue_pop(&front)))
		{
			if (full)
			{
				full = bt->left && bt->right;
				if (!full && bt->right)
				{
					pqueue_delete(front);
					return (0);
				}
			}
			else
			{
				if (bt->left || bt->right)
				{
					pqueue_delete(front);
					return (0);
				}
			}
		}
		return (1);
	}
	return (0);
}
