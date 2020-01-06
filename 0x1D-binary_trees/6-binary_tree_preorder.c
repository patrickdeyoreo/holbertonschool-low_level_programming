#include "binary_trees.h"

/**
 * _binary_tree_preorder - operate on a tree using pre-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void _binary_tree_preorder(const bt_t *tree, void (*func)(int))
{

	if (tree)
	{
		func(tree->n);
		_binary_tree_preorder(tree->left, func);
		_binary_tree_preorder(tree->right, func);
	}
}

/**
 * binary_tree_preorder - operate on a tree using pre-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void binary_tree_preorder(const bt_t *tree, void (*func)(int))
{
	if (func)
		_binary_tree_preorder(tree, func);
}
