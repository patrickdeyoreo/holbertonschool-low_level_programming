#include "binary_trees.h"

/**
 * _bst_insert - insert a node into a binary search tree
 * @tree: a double pointer to the root of the target tree
 * @value: the value to add to the tree
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly created node.
 */
bst_t *_bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL;

	if (*tree)
	{
		if (value < (*tree)->n)
		{
			node = _bst_insert(&((*tree)->left), value);
			if (node && !node->parent)
				node->parent = *tree;
			return (node);
		}
		if (value > (*tree)->n)
		{
			node = _bst_insert(&((*tree)->right), value);
			if (node && !node->parent)
				node->parent = *tree;
			return (node);
		}
		return (NULL);
	}
	*tree = binary_tree_node(NULL, value);
	return (*tree);
}

/**
 * bst_insert - insert a node into a binary search tree
 * @tree: a double pointer to the root of the target tree
 * @value: the value to add to the tree
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly created node.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	return (tree ? _bst_insert(tree, value) : NULL);
}
