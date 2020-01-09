#include "binary_trees.h"

/**
 * queue_push - push an element into a queue
 * @rear: a double pointer to the end of the queue
 * @data: a pointer to the element to queue
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
queue_t *queue_push(queue_t **rear, heap_t *data)
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
heap_t *queue_pop(queue_t **rear)
{
	queue_t *front = (*rear)->next;
	heap_t *data = front->data;

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
 * _heap_insert - insert a value into a max heap
 * @rear: the rear of an initialized level-order queue
 * @new: the node to be inserted
 */
void _heap_insert(queue_t *rear, heap_t *new)
{
	heap_t *current;

	while (rear)
	{
		current = queue_pop(&rear);
		if (!current->left)
		{
			new->parent = current;
			current->left = new;
			queue_delete(rear);
			break;
		}
		if (!current->right)
		{
			new->parent = current;
			current->right = new;
			queue_delete(rear);
			break;
		}
		if (!queue_push(&rear, current->left))
		{
			free(new);
			queue_delete(rear);
			break;
		}
		rear = rear->next;
		if (!queue_push(&rear, current->right))
		{
			free(new);
			queue_delete(rear);
			break;
		}
		rear = rear->next;
	}
}

/**
 * heap_insert - insert a value into a max heap
 * @root: a double pointer to the root of a heap
 * @value: a value to be added to the heap
 *
 * Return: If root is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	queue_t *rear = NULL;
	heap_t *new;

	if (!root)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (!*root)
		return ((*root = new));

	if (!queue_push(&rear, *root))
		return (free(new), NULL);

	_heap_insert(rear, new);

	while (new->parent && new->n > new->parent->n)
	{
		new->n ^= new->parent->n;
		new->parent->n ^= new->n;
		new->n ^= new->parent->n;
		new = new->parent;
		if (!new->parent)
			return ((*root = new));
	}
	return (new);
}
