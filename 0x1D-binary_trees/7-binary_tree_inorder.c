#include "binary_trees.h"

/**
 * _binary_tree_inorder - operate on a tree using in-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void _binary_tree_inorder(const bt_t *tree, void (*func)(int))
{

	if (tree)
	{
		_binary_tree_inorder(tree->left, func);
		func(tree->n);
		_binary_tree_inorder(tree->right, func);
	}
}

/**
 * binary_tree_inorder - operate on a tree using pre-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to the function to call
 */
void binary_tree_inorder(const bt_t *tree, void (*func)(int))
{
	if (func)
		_binary_tree_inorder(tree, func);
}
