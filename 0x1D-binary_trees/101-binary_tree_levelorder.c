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
 * @front: a pointer to the front of the queue
 */
void pqueue_delete(pqueue_t **front)
{
	pqueue_t *temp = NULL;

	while ((temp = *front))
	{
		*front = (*front)->next;
		free(temp);
	}
}
/**
 * queue_insert_sorted - insert an item into a sorted priority queue
 * @front: a double pointer to the front of a queue
 * @node: a pointer to the node to be added to the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *pqueue_insert_sorted(pqueue_t **front, pqueue_t *node)
{
	if (front)
	{
		if (*front)
		{
			if (node->pri >= (*front)->pri)
			{
				pqueue_insert_sorted(&((*front)->next), node);
				return (*front);
			}
			node->next = *front;
		}
		return ((*front = node));
	}
	return (NULL);
}

/**
 * binary_tree_to_queue - build the priority queue
 * @tree: the tree from which to construct a priority queue
 * @front: a double pointer to the front of the queue
 * @depth: current depth of recursion within this function
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *binary_tree_to_queue(const bt_t *tree, pqueue_t **front, size_t depth)
{
	pqueue_t *temp = NULL;

	if (front)
	{
		if (tree)
		{
			binary_tree_to_queue(tree->left, front, depth + 1);
			binary_tree_to_queue(tree->right, front, depth + 1);
			temp = pqueue_create(tree, depth);
			if (temp)
				pqueue_insert_sorted(front, temp);
			else
				pqueue_delete(front);
		}
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
	pqueue_t *front = NULL, *temp = NULL;

	if (tree && func)
	{
		binary_tree_to_queue(tree, &front, 0);
		if (front)
		{
			while ((temp = front))
			{
				func(front->item->n);
				front = front->next;
				free(temp);
			}

		}
	}
}
