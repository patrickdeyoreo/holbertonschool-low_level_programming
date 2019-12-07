#include "binary_trees.h"

avl_state_t _avl_insert(avl_t **node, avl_t **tree, int value);

/**
 * _avl_insert2 - mutually recurse with _avl_insert
 * @node: a pointer to memory to store a pointer to the new node
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 * @next: a double pointer to the root of the next subtree
 *
 * Return: a value of type avl_state_t to behavior of previous frames
 */
avl_state_t _avl_insert2(avl_t **node, avl_t **tree, int value, avl_t **next)
{
	switch (_avl_insert(node, next, value))
	{
	case AVL_INSERT:
		*node = *next = binary_tree_node(*tree, value);
		return (value < (*tree)->n ? AVL_LCHILD : AVL_RCHILD);
	case AVL_LCHILD:
		if (value < (*tree)->n)
		{
			if (binary_tree_balance(*tree) > 1)
				*tree = binary_tree_rotate_right(*tree);
			return (AVL_LCHILD);
		}
		else if (binary_tree_balance(*tree) < -1)
		{
			*next = binary_tree_rotate_right(*next);
			*tree = binary_tree_rotate_left(*tree);
		}
		return (AVL_RCHILD);
	case AVL_RCHILD:
		if (value < (*tree)->n)
		{
			if (binary_tree_balance(*tree) > 1)
			{
				*next = binary_tree_rotate_left(*next);
				*tree = binary_tree_rotate_right(*tree);
			}
			return (AVL_LCHILD);
		}
		else if (binary_tree_balance(*tree) < -1)
			*tree = binary_tree_rotate_left(*tree);
		return (AVL_RCHILD);
	default:
		return (AVL_EXISTS);
	}
}

/**
 * _avl_insert - insert a value into an AVL tree
 * @node: a pointer to memory to store a pointer to the new node
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 *
 * Return: a value of type avl_state_t to behavior of previous frames
 */
avl_state_t _avl_insert(avl_t **node, avl_t **tree, int value)
{
	avl_t **next = NULL;

	if (*tree)
	{
		if (value != (*tree)->n)
		{
			next = (value < (*tree)->n ? &((*tree)->left) : &((*tree)->right));
			return (_avl_insert2(node, tree, value, next));
		}
		return (AVL_EXISTS);
	}
	return (AVL_INSERT);
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

	if (!tree)
		return (NULL);

	if (!*tree)
		return ((*tree = binary_tree_node(*tree, value)));

	next = (value < (*tree)->n ? &((*tree)->left) : &((*tree)->right));
	switch (_avl_insert(&node, tree, value))
	{
	case AVL_INSERT:
		return ((*next = binary_tree_node(*tree, value)));
	case AVL_LCHILD:
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
	case AVL_RCHILD:
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
	default:
		return (NULL);
	}
}
