#include "binary_trees.h"

/**
 * _avl_insert - insert a value into an AVL tree
 * @node: a pointer to memory to store a pointer to the new node
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 *
 * Return: If tree is NULL memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
avl_state_t _avl_insert(avl_t **node, avl_t **tree, int value)
{
	avl_t **next = NULL;

	if (*tree)
	{
		next = (value < (*tree)->n ? &((*tree)->left) : &((*tree)->right));
		switch (_avl_insert(node, next, value))
		{
		case AVL_LEFT:
			if (value < (*tree)->n)
			{
				if (binary_tree_balance(*tree) > 1)
					*tree = binary_tree_rotate_right(*tree);
				return (AVL_LEFT);
			}
			if (binary_tree_balance(*tree) < -1)
			{
				*next = binary_tree_rotate_right(*next);
				*tree = binary_tree_rotate_left(*tree);
			}
			return (AVL_RIGHT);
		case AVL_RIGHT:
			if (value < (*tree)->n)
			{
				if (binary_tree_balance(*tree) > 1)
				{
					*next = binary_tree_rotate_left(*next);
					*tree = binary_tree_rotate_right(*tree);
				}
				return (AVL_LEFT);
			}
			if (binary_tree_balance(*tree) < -1)
				*tree = binary_tree_rotate_left(*tree);
			return (AVL_RIGHT);
		case AVL_NONE:
			*node = *next = binary_tree_node(*tree, value);
			return (value < (*tree)->n ? AVL_LEFT : AVL_RIGHT);
		}
	}
	return (AVL_NONE);
}

/**
 * avl_insert - insert a value into an AVL tree
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 *
 * Return: If tree is NULL memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new node.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL, **next = NULL;

	if (tree)
	{
		if (*tree)
		{
			next = (value < (*tree)->n ? &((*tree)->left) : &((*tree)->right));
			switch (_avl_insert(&node, tree, value))
			{
			case AVL_LEFT:
				if (value < (*tree)->n)
				{
					if (binary_tree_balance(*tree) > 1)
						*tree = binary_tree_rotate_right(*tree);
				}
				else if (binary_tree_balance(*tree) < -1)
				{
					*next = binary_tree_rotate_right(*next);
					*tree = binary_tree_rotate_left(*tree);
				}
				return (node);
			case AVL_RIGHT:
				if (value < (*tree)->n)
				{
					if (binary_tree_balance(*tree) > 1)
					{
						*next = binary_tree_rotate_left(*next);
						*tree = binary_tree_rotate_right(*tree);
					}
				}
				else if (binary_tree_balance(*tree) < -1)
					*tree = binary_tree_rotate_left(*tree);
				return (node);
			case AVL_NONE:
				return ((*next = binary_tree_node(*tree, value)));
			}
		}
		return ((*tree = binary_tree_node(*tree, value)));
	}
	return (NULL);
}
