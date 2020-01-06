#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a given node is a leaf
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const bt_t *node)
{
	return (node && !node->left && !node->right);
}
