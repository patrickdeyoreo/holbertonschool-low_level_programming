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
			temp->data = data;
			temp->next = *front;
			temp->pri = pri;
			return ((*front = temp));
		}
	}
	return (NULL);
}

/**
 * pqueue_pop - pop an element from a priority queue
 * @front: a pointer to the front of the queue
 *
 * Return: a pointer to the popped element
 */
const bt_t *pqueue_pop(pqueue_t **front)
{
	const bt_t *data = NULL;
	pqueue_t *temp = front ? *front : NULL;

	if (temp)
	{
		*front = temp->next;
		data = temp->data;
		free(temp);
	}
	return (data);
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
 * binary_tree_is_complete - determine if a binary tree is complete
 * @tree: a pointer to the root of the tree to examine
 *
 * Return: If tree is NULL or the tree is not complete, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_complete(const bt_t *tree)
{
	const bt_t *data = NULL;
	pqueue_t *front = NULL;
	int comp = 1, full = 1;

	if (bt_to_pqueue(&front, tree))
	{
		while (full && (data = pqueue_pop(&front)))
			full = data->left && data->right;
		if (data)
			comp = !data->right;
		while (comp && (data = pqueue_pop(&front)))
			comp = !data->left && !data->right;
		pqueue_delete(front);
		return (comp);
	}
	return (0);
}

/**
 * binary_tree_is_descending - determine if binary tree is a max heap
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL is the tree is not a max heap, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_descending(const bt_t *tree)
{
	if (!tree)
		return (1);

	return (tree->parent->n >= tree->n &&
			binary_tree_is_descending(tree->left) &&
			binary_tree_is_descending(tree->right));
}

/**
 * binary_tree_is_heap - determine if binary tree is a max heap
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL is the tree is not a max heap, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_heap(const bt_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_complete(tree) &&
			binary_tree_is_descending(tree->left) &&
			binary_tree_is_descending(tree->right));
}
