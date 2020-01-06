#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise the number of leaves in a tree.
 */
size_t binary_tree_leaves(const bt_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left || tree->right))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
