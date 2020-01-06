#include "binary_trees.h"

/**
 * binary_tree_node - create a new node
 * @parent: a pointer to the parent of the node to be created
 * @value: the value to put in the new node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
bt_t *binary_tree_node(bt_t *parent, int value)
{
	bt_t *new = calloc(1, sizeof(*new));

	if (new)
	{
		new->n = value;
		new->parent = parent;
	}
	return (new);
}
