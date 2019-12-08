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
		{
			return (pqueue_insert(&((*front)->next), item, priority));
		}
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
 * bt_to_pqueue - build a priority queue of nodes from a binary tree
 * @tree: a tree from which to construct the queue
 * @front: a double pointer to the front of the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *bt_to_pqueue(pqueue_t **front, const binary_tree_t *tree)
{
	static size_t priority;

	if (front)
	{
		priority += 1;
		if (tree)
		{
			bt_to_pqueue(front, tree->left);
			bt_to_pqueue(front, tree->right);
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
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const bt_t *item = NULL;
	pqueue_t *front = NULL, *temp = NULL;
	int isfull = 1;

	if (bt_to_pqueue(&front, tree))
	{
		while ((temp = front))
		{
			item = front->item;
			front = front->next;
			free(temp);

			if (isfull)
			{
				isfull = item->left && item->right;

				if (!isfull && item->right)
				{
					while ((temp = front))
						front = front->next, free(temp);
					return (0);
				}
			}
			else
			{
				if (item->left || item->right)
				{
					while ((temp = front))
						front = front->next, free(temp);
					return (0);
				}
			}
		}
		return (1);
	}
	return (0);
}

/**
 * binary_subtree_is_heap - determine if binary tree is a max heap
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL is the tree is not a max heap, return 0.
 * Otherwise, return 1.
 */
int binary_subtree_is_heap(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->parent->n >= tree->n)
			return (binary_subtree_is_heap(tree->left) &&
					binary_subtree_is_heap(tree->right));
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
		return (binary_tree_is_complete(tree) &&
				binary_subtree_is_heap(tree->left) &&
				binary_subtree_is_heap(tree->right));
	return (0);
}
