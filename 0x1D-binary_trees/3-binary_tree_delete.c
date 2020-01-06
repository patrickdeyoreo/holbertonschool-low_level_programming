#include "binary_trees.h"

/**
 * binary_tree_delete - delete an entire binary tree
 * @tree: a pointer to the root node of the tree
 */
void binary_tree_delete(bt_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
