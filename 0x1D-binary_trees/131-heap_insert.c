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
 * heap_insert - insert a value into a max heap
 * @root: a double pointer to the root of a heap
 * @value: a value to be added to the heap
 *
 * Return: If root is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
}
