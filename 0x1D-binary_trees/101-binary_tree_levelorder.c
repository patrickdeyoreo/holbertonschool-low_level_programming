#include "binary_trees.h"

/**
 * pqueue_insert - insert an item into a priority queue
 * @front: a double pointer to a queue
 * @item: a pointer to the item to queue
 * @priority: the item's priority
 *
 * Return: If front is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
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
 * binary_tree_levelorder - perform level-order traversal on a binary tree
 * @tree: the tree to traverse
 * @func: the function to apply
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *item = NULL;
	pqueue_t *front = NULL;
	pqueue_t *temp = NULL;

	if (tree && func && binary_tree_to_pqueue(&front, tree))
	{
		while ((temp = front))
		{
			item = temp->item;
			func(item->n);
			front = front->next;
			free(temp);
		}
	}
}
