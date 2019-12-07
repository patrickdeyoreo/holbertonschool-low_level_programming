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
		case AVL_NEW:
			if (value < (*tree)->n)
			{
				*node = (*tree)->left = binary_tree_node(*tree, value);
				return (AVL_SUBTREE_L);
			}
			else
			{
				*node = (*tree)->right = binary_tree_node(*tree, value);
				return (AVL_SUBTREE_R);
			}
		case AVL_SUBTREE_L:
			if (value < (*tree)->n)
			{
				(*tree)->left->parent = *tree;
				if (binary_tree_balance(*tree) > 1)
					*tree = binary_tree_rotate_right(*tree);
				return (AVL_SUBTREE_L);
			}
			else
			{
				(*tree)->right->parent = *tree;
				if (binary_tree_balance(*tree) > 1)
				{
					(*tree)->right = binary_tree_rotate_right((*tree)->right);
					(*tree)->right->parent = *tree;
					*tree = binary_tree_rotate_left(*tree);
				}
				return (AVL_SUBTREE_R);
			}
		case AVL_SUBTREE_R:
			if (value < (*tree)->n)
			{
				(*tree)->left->parent = *tree;
				if (binary_tree_balance(*tree) < -1)
				{
					(*tree)->left = binary_tree_rotate_left((*tree)->left);
					(*tree)->left->parent = *tree;
					*tree = binary_tree_rotate_right(*tree);
				}
				return (AVL_SUBTREE_L);
			}
			else
			{
				(*tree)->right->parent = *tree;
				if (binary_tree_balance(*tree) < -1)
					*tree = binary_tree_rotate_left(*tree);
				return (AVL_SUBTREE_R);
			}
		}
	}
	return (AVL_NEW);
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
	avl_t *node = NULL;

	if (tree)
	{
		if (*tree)
		{
			switch (_avl_insert(&node, tree, value))
			{
			case AVL_NEW:
				if (value < (*tree)->n)
					node = (*tree)->left = binary_tree_node(*tree, value);
				else
					node = (*tree)->right = binary_tree_node(*tree, value);
				break;
			case AVL_SUBTREE_L:
				if (value < (*tree)->n)
				{
					(*tree)->left->parent = *tree;
					if (binary_tree_balance(*tree) > 1)
						*tree = binary_tree_rotate_right(*tree);
				}
				else
				{
					(*tree)->right->parent = *tree;
					if (binary_tree_balance(*tree) > 1)
					{
						(*tree)->right = binary_tree_rotate_right((*tree)->right);
						(*tree)->right->parent = *tree;
						*tree = binary_tree_rotate_left(*tree);
					}
				}
				break;
			case AVL_SUBTREE_R:
				if (value < (*tree)->n)
				{
					(*tree)->left->parent = *tree;
					if (binary_tree_balance(*tree) < -1)
					{
						(*tree)->left = binary_tree_rotate_left((*tree)->left);
						(*tree)->left->parent = *tree;
						*tree = binary_tree_rotate_right(*tree);
					}
				}
				else
				{
					(*tree)->right->parent = *tree;
					if (binary_tree_balance(*tree) < -1)
						*tree = binary_tree_rotate_left(*tree);
				}
				break;
			}
			return (node);
		}
		return ((*tree = binary_tree_node(NULL, value)));
	}
	return (NULL);
}
