#include "binary_trees.h"

/**
 * _binary_tree_postorder - operate on a tree using post-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void _binary_tree_postorder(const bt_t *tree, void (*func)(int))
{

	if (tree)
	{
		_binary_tree_postorder(tree->left, func);
		_binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}

/**
 * binary_tree_postorder - operate on a tree using pre-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void binary_tree_postorder(const bt_t *tree, void (*func)(int))
{
	if (func)
		_binary_tree_postorder(tree, func);
}
