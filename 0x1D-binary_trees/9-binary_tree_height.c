#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the height of the tree.
 */
size_t binary_tree_height(const bt_t *tree)
{
	size_t lhs = 0, rhs = 0;

	if (tree)
	{
		lhs = (tree->left ? binary_tree_height(tree->left) + 1 : 0);
		rhs = (tree->right ? binary_tree_height(tree->right) + 1 : 0);
	}
	return (lhs > rhs ? lhs : rhs);
}
