#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a right-rotation on a binary tree
 * @tree: the tree to rotate
 *
 * Return: a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	bt_t *root = NULL;

	if (tree)
	{
		root = tree->left;
		if (root)
		{
			tree->left = root->right;
			if (tree->left)
				tree->left->parent = tree;
			root->right = tree;
			tree->parent = root;
			root->parent = NULL;
		}
	}
	return (root);
}
