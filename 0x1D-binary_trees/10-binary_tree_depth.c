#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 * @tree: a pointer to the node
 *
 * Return: If tree is NULL, return 0.
 * Otherwise, return the depth of the node.
 */
size_t binary_tree_depth(const bt_t *tree)
{
	size_t depth = 0;

	if (tree)
	{
		while ((tree = tree->parent))
			++depth;
	}
	return (depth);
}
