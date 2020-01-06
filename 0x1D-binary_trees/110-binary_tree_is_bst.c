#include "binary_trees.h"
#include <limits.h>

/**
 * _binary_tree_is_bst - determine if a binary tree is a BST
 * @tree: the tree to examine
 * @lower: lower bound
 * @upper: upper bound
 *
 * Return: If tree is NULL or is not a BST, return 0.
 * Otherwise, return 1.
 */
int _binary_tree_is_bst(const bt_t *tree, int lower, int upper)
{
	if (tree)
	{
		if (tree->n > lower && tree->n < upper)
			return (_binary_tree_is_bst(tree->left, lower, tree->n) &&
					_binary_tree_is_bst(tree->right, tree->n, upper));
		return (0);
	}
	return (1);
}

/**
 * binary_tree_is_bst - determine if a binary tree is a BST
 * @tree: the tree to examine
 *
 * Return: If tree is NULL or is not a BST, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_bst(const bt_t *tree)
{
	if (tree)
		return (_binary_tree_is_bst(tree->left, INT_MIN, tree->n) &&
				_binary_tree_is_bst(tree->right, tree->n, INT_MAX));
	return (0);
}
