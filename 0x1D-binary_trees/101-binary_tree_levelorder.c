#include "binary_trees.h"

/**
 * pqueue_insert - insert an element into a priority queue
 * @front: a double pointer to a queue
 * @data: a pointer to the element to queue
 * @pri: the priority of the element
 *
 * Return: If front is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
pqueue_t *pqueue_insert(pqueue_t **front, const bt_t *data, size_t pri)
{
	pqueue_t *temp = NULL;

	if (front)
	{
		if (*front && pri >= (*front)->pri)
			return (pqueue_insert(&((*front)->next), data, pri));

		temp = malloc(sizeof(*temp));
		if (temp)
		{
			temp->data = (bt_t *) data;
			temp->next = *front;
			temp->pri = pri;
			return ((*front = temp));
		}
	}
	return (NULL);
}

/**
 * bt_to_pqueue - queue binary tree nodes in ascending order by depth
 * @tree: a tree from which to construct the queue
 * @front: a double pointer to the front of the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *bt_to_pqueue(pqueue_t **front, const bt_t *tree)
{
	static size_t depth;

	if (front)
	{
		depth += 1;
		if (tree)
		{
			bt_to_pqueue(front, tree->left);
			bt_to_pqueue(front, tree->right);
			pqueue_insert(front, tree, depth);
		}
		depth -= 1;
		return (*front);
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
	const bt_t *data = NULL;
	pqueue_t *front = NULL;
	pqueue_t *temp = NULL;

	if (tree && func)
	{
		bt_to_pqueue(&front, tree);
		while ((temp = front))
		{
			data = front->data;
			func(data->n);
			front = front->next;
			free(temp);
		}
	}
}
