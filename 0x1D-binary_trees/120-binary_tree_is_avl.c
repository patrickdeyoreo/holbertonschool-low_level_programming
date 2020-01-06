#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the height of the tree.
 */
size_t binary_tree_height(const bt_t *tree)
{
	size_t lhs, rhs;

	if (tree)
	{
		lhs = binary_tree_height(tree->left);
		rhs = binary_tree_height(tree->right);
		return ((lhs > rhs ? lhs : rhs) + 1);
	}
	return (0);
}

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

/**
 * binary_tree_is_balanced - check if a BST qualifies as an AVL tree
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL or is not a valid AVL tree, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_balanced(const bt_t *tree)
{
	size_t lhs, rhs;

	if (tree)
	{
		lhs = binary_tree_height(tree->left);
		rhs = binary_tree_height(tree->right);
		if ((lhs > rhs ? (lhs - rhs) : (rhs - lhs)) <= 1)
			return (binary_tree_is_balanced(tree->left) &&
				binary_tree_is_balanced(tree->right));
		return (0);
	}
	return (1);
}

/**
 * binary_tree_is_avl - check if a BST qualifies as an AVL tree
 * @tree: a pointer to the root of the tree
 *
 * Return: If tree is NULL or is not a valid AVL tree, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_avl(const bt_t *tree)
{
	if (tree)
		return (binary_tree_is_bst(tree) &&
			binary_tree_is_balanced(tree));
	return (0);
}
