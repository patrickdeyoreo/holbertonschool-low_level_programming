#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise the number of non-leaf nodes in a tree.
 */
size_t binary_tree_nodes(const bt_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left || tree->right))
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
