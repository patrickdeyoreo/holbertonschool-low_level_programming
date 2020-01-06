#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 * @node: a pointer to the node
 *
 * Return: If node is NULL or does not have a sibling, return NULL.
 * Otherwise, return a pointer to the sibling.
 */
bt_t *binary_tree_sibling(bt_t *node)
{
	bt_t *parent = NULL;

	if (node)
	{
		parent = node->parent;
		if (parent)
			return (node == parent->left ? parent->right : parent->left);
	}
	return (NULL);
}
