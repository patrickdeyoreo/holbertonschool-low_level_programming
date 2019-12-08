#include "binary_trees.h"

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
		if (*front && priority < (*front)->priority)
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
 * bt_to_pqueue - build a priority queue of nodes from a binary tree
 * @front: a double pointer to the front of the queue
 * @tree: a tree from which to construct the queue
 *
 * Return: a pointer to the front of the queue
 */
pqueue_t *bt_to_pqueue(pqueue_t **front, const binary_tree_t *tree)
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
		*root = (bt_t *) front->item;
		while ((child = child->next))
		{
			((bt_t *) child->item)->left = NULL;
			((bt_t *) child->item)->right = NULL;
			((bt_t *) child->item)->parent = (bt_t *) parent->item;
			((bt_t *) parent->item)->left = (bt_t *) child->item;

			child = child->next;

			if (!child)
			{
				((bt_t *) parent->item)->right = NULL;
				break;
			}
			((bt_t *) child->item)->left = NULL;
			((bt_t *) child->item)->right = NULL;
			((bt_t *) child->item)->parent = (bt_t *) parent->item;
			((bt_t *) parent->item)->right = (bt_t *) child->item;

			parent = parent->next;
		}
	}
	pqueue_delete(front);
	return (item);
}
