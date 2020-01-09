#include "binary_trees.h"

/**
 * _avl_insert_lchild - call upon return to parent from child's left subtree
 * @tree: a pointer to the node's parent
 * @value: the inserted value
 *
 * Return: the resulting AVL state
 */
avl_state_t _avl_insert_lchild(avl_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if (binary_tree_balance(*tree) > 1)
		{
			(*tree) = binary_tree_rotate_right(*tree);
		}
		return (AVL_LCHILD);
	}
	if (binary_tree_balance(*tree) < -1)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		(*tree) = binary_tree_rotate_left(*tree);
	}
	return (AVL_RCHILD);
}

/**
 * _avl_insert_rchild - call upon return to parent from child's right subtree
 * @tree: a pointer to the node's parent
 * @value: the inserted value
 *
 * Return: the resulting AVL state
 */
avl_state_t _avl_insert_rchild(avl_t **tree, int value)
{
	if (value > (*tree)->n)
	{
		if (binary_tree_balance(*tree) < -1)
		{
			(*tree) = binary_tree_rotate_left(*tree);
		}
		return (AVL_RCHILD);
	}
	if (binary_tree_balance(*tree) > 1)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		(*tree) = binary_tree_rotate_right(*tree);
	}
	return (AVL_LCHILD);
}

/**
 * _avl_insert - insert a value into an AVL tree
 * @node: a pointer to memory to store a pointer to the new node
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 *
 * Return: the current state of AVL insertion
 */
avl_state_t _avl_insert(avl_t **new, avl_t **tree, int value)
{
	avl_t **child = NULL;

	if (*tree)
	{
		if (value != (*tree)->n)
		{
			if (value < (*tree)->n)
				child = &((*tree)->left);
			else
				child = &((*tree)->right);

			switch (_avl_insert(new, child, value))
			{
			case AVL_RETURN:
				break;

			case AVL_LCHILD:
				return (_avl_insert_lchild(tree, value));

			case AVL_RCHILD:
				return (_avl_insert_rchild(tree, value));

			case AVL_CREATE:
				*new = binary_tree_node(*tree, value);
				if (*new)
				{
					*child = *new;
					if (value < (*tree)->n)
						return (AVL_LCHILD);
					else
						return (AVL_RCHILD);
				}
				break;
			}
		}
		return (AVL_RETURN);
	}
	return (AVL_CREATE);
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
	avl_t *new = NULL;

	if (tree)
	{
		if (*tree)
		{
			switch (_avl_insert(&new, tree, value))
			{
			case AVL_RETURN:
				break;

			case AVL_LCHILD:
				_avl_insert_lchild(tree, value);
				break;

			case AVL_RCHILD:
				_avl_insert_rchild(tree, value);
				break;

			case AVL_CREATE:
				new = binary_tree_node(*tree, value);
				if (new)
				{
					if (value < (*tree)->n)
						(*tree)->left = new;
					else
						(*tree)->right = new;
				}
				break;
			}
			return (new);
		}
		return ((*tree = binary_tree_node(*tree, value)));
	}
	return (NULL);
}
