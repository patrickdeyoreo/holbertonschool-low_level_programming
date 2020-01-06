#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node as the left child of a node
 * @parent: a pointer to the parent of the node to be created
 * @value: the value to put in the new node
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
bt_t *binary_tree_insert_left(bt_t *parent, int value)
{
	bt_t *new = NULL;

	if (parent)
	{
		new = binary_tree_node(parent, value);
		if (new)
		{
			if (parent->left)
			{
				new->left = parent->left;
				new->left->parent = new;
			}
			parent->left = new;
		}
	}
	return (new);
}
