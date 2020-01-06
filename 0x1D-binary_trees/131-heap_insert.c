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
 * bt_to_pqueue - build a priority queue of nodes from a binary tree
 * @front: a double pointer to the front of the queue
 * @tree: a tree from which to construct the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *bt_to_pqueue(pqueue_t **front, const bt_t *tree)
{
	if (front)
	{
		if (tree)
		{
			bt_to_pqueue(front, tree->left);
			bt_to_pqueue(front, tree->right);
			pqueue_insert(front, tree, tree->n);
		}
		return (*front);
	}
	return (NULL);
}

/**
 * heap_insert - insert a value into a max heap
 * @root: a double pointer to the root of a heap
 * @value: a value to be added to the heap
 *
 * Return: If root is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly created node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	bt_t *item = NULL;
	pqueue_t *front = NULL, *parent = NULL, *child = NULL;

	if (!root)
		return (NULL);

	item = binary_tree_node(NULL, value);
	if (!item)
		return (NULL);

	bt_to_pqueue(&front, *root);
	pqueue_insert(&front, item, value);
	if (front)
	{
		parent = child = front;
		*root = front->data;
		while ((child = child->next))
		{
			(child->data)->left = NULL;
			(child->data)->right = NULL;
			(child->data)->parent = parent->data;
			(parent->data)->left = child->data;

			child = child->next;

			if (!child)
			{
				(parent->data)->right = NULL;
				break;
			}
			(child->data)->left = NULL;
			(child->data)->right = NULL;
			(child->data)->parent = parent->data;
			(parent->data)->right = child->data;

			parent = parent->next;
		}
	}
	pqueue_delete(front);
	return (item);
}
