#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a right-rotation on a binary tree
 * @tree: the tree to rotate
 *
 * Return: a pointer to the new root
 */
bt_t *binary_tree_rotate_right(bt_t *tree)
{
	bt_t *node = NULL;

	if (tree)
	{
		node = tree->left;
		if (node)
		{
			tree->left = node->right;
			if (tree->left)
				tree->left->parent = tree;
			node->right = tree;
			node->parent = tree->parent;
			tree->parent = node;
		}
	}
	return (node);
}
