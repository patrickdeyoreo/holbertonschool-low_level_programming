#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the size of the tree.
 */
size_t binary_tree_size(const bt_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
