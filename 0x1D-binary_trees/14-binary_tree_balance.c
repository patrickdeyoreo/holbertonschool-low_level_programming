#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lhs = 0, rhs = 0;

	if (tree)
	{
		lhs = binary_tree_height(tree->left) + 1;
		rhs = binary_tree_height(tree->right) + 1;
	}
	return (lhs > rhs ? lhs : rhs);
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
