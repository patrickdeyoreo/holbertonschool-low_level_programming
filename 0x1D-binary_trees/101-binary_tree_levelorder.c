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
	queue_t *temp = malloc(sizeof(*temp));

	if (temp)
	{
		temp->data = (void *) data;
		if (*rear)
			temp->next = (*rear)->next;
		else
			*rear = temp;
		(*rear)->next = temp;
	}
	return (temp);
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
	stack_t *front = (*rear)->next;
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
 * binary_tree_levelorder - perform level-order traversal on a binary tree
 * @tree: the tree to traverse
 * @func: the function to apply
 */
void binary_tree_levelorder(const bt_t *tree, void (*func)(int))
{
	queue_t *new, *rear;

	if (tree && func)
	{
		rear = queue_push(NULL, tree);
		while (rear && (tree = queue_pop(&rear)))
		{
			if (tree->left)
			{
				new = queue_push(&rear, tree->left);
				if (!new)
				{
					queue_delete(rear);
					return;
				}
				rear = new;
			}
			if (tree->right)
			{
				new = queue_push(&rear, tree->right);
				if (!new)
				{
					queue_delete(rear);
					return;
				}
				rear = new;
			}
			func(tree->n);
		}
	}
}
