#include "binary_trees.h"

/**
 * binary_tree_insert_right -insert a new node as the right child of a node
 * @parent: a pointer to the parent of the node to be created
 * @value: the value to put in the new node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (parent)
	{
		new = binary_tree_node(parent, value);
		if (new)
		{
			if (parent->right)
			{
				new->right = parent->right;
				new->right->parent = new;
			}
			parent->right = new;
		}
	}
	return (new);
}
