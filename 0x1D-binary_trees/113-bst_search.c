#include "binary_trees.h"

/**
 * bst_search - search for an element in a BST
 * @tree: the tree in which to locate a value
 * @value: the value to locate
 *
 * Return: If tree is NULL or the given value cannot be found, return NULL.
 * Otherwise, return a pointer to the node containing the given value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (value < tree->n)
			return (bst_search(tree->left, value));
		if (value > tree->n)
			return (bst_search(tree->right, value));
		return ((bst_t *) tree);
	}
	return (NULL);
}
