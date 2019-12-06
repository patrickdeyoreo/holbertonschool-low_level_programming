#include "binary_trees.h"

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
			temp = calloc(1, sizeof(*temp));
			if (temp)
			{
				temp->item = tree;
				temp->pri = depth;
				pqueue_insert_sorted(front, temp);
				return (*front);
			}
			while ((temp = *front));
			{
				front = &((*front)->next);
				free(temp);
			}
		}
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
int binary_tree_is_complete(const binary_tree_t *tree)
{
	pqueue_t *front = NULL, *temp = NULL;
	int isfull = 1;

	if (tree)
	{
		front = binary_tree_to_queue(tree, &front, 0);
		while ((temp = front))
		{
			if (isfull)
			{
				isfull = front->item->left && front->item->right;
				if (!isfull && front->item->right)
				{
					do {
						front = front->next;
						free(temp);
					} while ((temp = front));
					return (0);
				}
			}
			else
			{
				if (front->item->left || front->item->right)
				{
					do {
						front = front->next;
						free(temp);
					} while ((temp = front));
					return (0);
				}
			}
			front = front->next;
			free(temp);
		}
		return (1);
	}
	return (0);
}

/**
 * _binary_tree_is_heap - determine if binary tree is a max heap
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL is the tree is not a max heap, return 0.
 * Otherwise, return 1.
 */
int _binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!tree->parent || tree->parent->n >= tree->n)
			return (_binary_tree_is_heap(tree->left) &&
					_binary_tree_is_heap(tree->right));
		return (0);
	}
	return (1);
}

/**
 * binary_tree_is_heap - determine if binary tree is a max heap
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL is the tree is not a max heap, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_is_complete(tree) && _binary_tree_is_heap(tree));
	return (0);
}
