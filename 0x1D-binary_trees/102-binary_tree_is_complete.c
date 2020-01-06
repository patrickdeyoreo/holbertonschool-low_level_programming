#include "binary_trees.h"

/**
 * queue_push - push an element into a queue
 * @rear: a pointer to the end of the queue
 * @data: a pointer to the element to queue
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
queue_t *queue_push(queue_t *rear, const bt_t *data)
{
	queue_t *temp = malloc(sizeof(*temp));

	if (temp)
	{
		temp->data = (bt_t *) data;
		if (rear)
		{
			temp->next = rear->next;
			rear->next = temp;
		}
		else
		{
			temp->next = temp;
		}
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
	queue_t *front = *rear ? (*rear)->next : NULL;
	const bt_t *data = front ? front->data : NULL;

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
	queue_t *new, *rear;
	bool is_full = true;

	if (tree)
	{
		rear = queue_push(NULL, tree);
		while (rear && (tree = queue_pop(&rear)))
		{
			if (!is_full)
			{
				if (tree->left || tree->right)
					return (queue_delete(rear), 0);
			}
			else
			{
				is_full = tree->left && tree->right;
				if (!is_full && tree->right)
					return (queue_delete(rear), 0);
			}
			if (tree->left)
			{
				new = queue_push(rear, tree->left);
				if (!new)
					return (queue_delete(rear), -1);
				rear = new;
			}
			if (tree->right)
			{
				new = queue_push(rear, tree->right);
				if (!new)
					return (queue_delete(rear), -1);
				rear = new;
			}
		}
		return (1);
	}
	return (0);
}
