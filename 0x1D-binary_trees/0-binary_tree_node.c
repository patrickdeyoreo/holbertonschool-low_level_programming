#include "binary_trees.h"

/**
 * binary_tree_node - create a new node
 * @parent: a pointer to the parent of the node to be created
 * @value: the value to put in the new node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (new)
	{
		new->n = value;
		new->parent = parent;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
