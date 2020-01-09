#include "binary_trees.h"

/**
 * queue_push - push an element into a queue
 * @rear: a double pointer to the end of the queue
 * @data: a pointer to the element to queue
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
queue_t *queue_push(queue_t **rear, const bt_t *data)
{
	queue_t *new = calloc(1, sizeof(*new));

	if (new)
	{
		new->data = (void *) data;
		if (rear)
		{
			if (*rear)
				new->next = (*rear)->next;
			else
				*rear = new;
			(*rear)->next = new;
		}
	}
	return (new);
}

/**
 * queue_pop - pop an element from a queue
 * @rear: a double pointer to the end of the queue
 *
 * Description: This function expects a pointer to a non-empty queue.
 *
 * Return: Return a pointer to the popped element.
 */
const bt_t *queue_pop(queue_t **rear)
{
	queue_t *front = (*rear)->next;
	const bt_t *data = front->data;

	if (*rear == front)
		*rear = NULL;
	else
		(*rear)->next = front->next;
	free(front);
	return (data);
}

/**
 * queue_delete - delete a queue
 * @rear: a pointer to the rear of the queue
 */
void queue_delete(queue_t *rear)
{
	queue_t *temp;

	if (rear)
	{
		temp = rear->next;
		rear->next = NULL;
		while ((rear = temp))
		{
			temp = temp->next;
			free(rear);
		}
	}
}

/**
 * binary_tree_is_complete - determine if a binary tree is complete
 * @tree: a pointer to the root of the tree to examine
 *
 * Return: If tree is NULL or the tree is not complete, return 0.
 * If memory allocation fails, return -1.
 * Otherwise, return 1.
 */
int binary_tree_is_complete(const bt_t *tree)
{
	queue_t *rear = NULL;
	bool is_full = true;

	if (!tree)
		return (0);

	if (!queue_push(&rear, tree))
		return (-1);
	while (rear)
	{
		tree = queue_pop(&rear);
		if (is_full)
		{
			is_full = tree->left && tree->right;
			if (!is_full && tree->right)
				return (queue_delete(rear), 0);
		}
		else
		{
			if (tree->left || tree->right)
				return (queue_delete(rear), 0);
		}
		if (tree->left)
		{
			if (!queue_push(&rear, tree->left))
				return (queue_delete(rear), -1);
			rear = rear->next;
		}
		if (tree->right)
		{
			if (!queue_push(&rear, tree->right))
				return (queue_delete(rear), -1);
			rear = rear->next;
		}
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
int binary_tree_is_heap(const bt_t *tree)
{
	return (tree && (
			tree->parent ?
			tree->parent->n >= tree->n :
			binary_tree_is_complete(tree) == 1
			) && (
			!tree->left ||
			binary_tree_is_heap(tree->left)
			) && (
			!tree->right ||
			binary_tree_is_heap(tree->right)
			));
}
