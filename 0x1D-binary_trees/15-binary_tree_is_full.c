#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL or the tree is not full, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_full(const bt_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left)
		return (!tree->right);

	if (!tree->right)
		return (!tree->left);

	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}
