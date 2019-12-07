#include "binary_trees.h"

/**
 * queue_insert_sorted - insert an item into a sorted priority queue
 * @head: a double pointer to the head of a queue
 * @node: a pointer to the node to be added to the queue
 *
 * Return: a pointer to the head of the queue
 */
pqueue_t *pqueue_insert_sorted(pqueue_t **head, pqueue_t *node)
{
	if (head)
	{
		if (*head)
		{
			if (node->pri >= (*head)->pri)
			{
				pqueue_insert_sorted(&((*head)->next), node);
				return (*head);
			}
			node->next = *head;
		}
		return ((*head = node));
	}
	return (NULL);
}

/**
 * binary_tree_to_queue - build the priority queue
 * @tree: the tree from which to construct a priority queue
 * @head: a double pointer to the head of the queue
 * @depth: current depth of recursion within this function
 *
 * Return: a pointer to the head of the queue
 */
pqueue_t *binary_tree_to_queue(const bt_t *tree, pqueue_t **head, size_t depth)
{
	pqueue_t *temp = NULL;

	if (head)
	{
		if (tree)
		{
			binary_tree_to_queue(tree->left, head, depth + 1);
			binary_tree_to_queue(tree->right, head, depth + 1);
			temp = calloc(1, sizeof(*temp));
			if (temp)
			{
				temp->item = tree;
				temp->pri = depth;
				pqueue_insert_sorted(head, temp);
				return (*head);
			}
			while ((temp = *head))
			{
				head = &((*head)->next);
				free(temp);
			}
		}
		return (*head);
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
	pqueue_t *head = NULL;
	pqueue_t *temp = NULL;
	int isfull = 1;

	if (tree)
	{
		head = binary_tree_to_queue(tree, &head, 0);
		while ((temp = head))
		{
			if (isfull)
			{
				isfull = head->item->left && head->item->right;
				if (!isfull && head->item->right)
				{
					do {
						head = head->next;
						free(temp);
					} while ((temp = head));
					return (0);
				}
			}
			else
			{
				if (head->item->left || head->item->right)
				{
					do {
						head = head->next;
						free(temp);
					} while ((temp = head));
					return (0);
				}
			}
			head = head->next;
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
