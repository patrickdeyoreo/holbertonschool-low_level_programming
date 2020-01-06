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

/**
 * _binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 * @remaining: the number of levels left to recurse
 *
 * Return: If tree is NULL or the tree is not perfect, return 0.
 * Otherwise, return 1.
 */
int _binary_tree_is_perfect(const bt_t *tree, size_t remaining)
{
	if (tree)
	{
		if (remaining)
			return (_binary_tree_is_perfect(tree->left, remaining - 1) &&
					_binary_tree_is_perfect(tree->right, remaining - 1));
		return (binary_tree_is_leaf(tree));
	}
	return (0);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 *
 * Return: If tree is NULL or the tree is not perfect, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_perfect(const bt_t *tree)
{
	const bt_t *root = tree;
	size_t levels = 0;

	if (tree)
	{
		while ((tree = tree->left))
			++levels;
		return (_binary_tree_is_perfect(root, levels));
	}
	return (0);
}
