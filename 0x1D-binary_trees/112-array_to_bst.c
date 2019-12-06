#include "binary_trees.h"

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
		while (size-- && bst_insert(&root, *array++))
			;
	}
	return (root);
}
