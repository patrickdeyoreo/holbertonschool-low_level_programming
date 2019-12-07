#include "binary_trees.h"

/**
 * array_to_avl - build an AVL tree from an array
 * @array: source array
 * @size: size of the array
 *
 * Return: If array is NULL or memory allocation fails, return NULL.
 * Otherwise, return a pointer to the root of the resulting tree.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array)
	{
		while (size--)
			avl_insert(&tree, *array++);
	}
	return (tree);
}
