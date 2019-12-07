#include "binary_trees.h"

/**
 * binary_tree_delete - delete an entire binary tree
 * @tree: a pointer to the root node of the tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * array_to_bst - build a BST from an array
 * @array: the array from which to construct a BST
 * @size: the size of the array
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the root of the new BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (array)
	{
		while (size--)
		{
			if (!bst_insert(&root, *array++))
			{
				binary_tree_delete(root);
				return (NULL);
			}
		}
	}
	return (root);
}
