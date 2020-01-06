#include "binary_trees.h"

/**
 * _avl_child_l - execute upon return to parent from child's left subtree
 * @tree: a pointer to the node's parent
 * @value: the inserted value
 *
 * Return: the resulting AVL state
 */
avl_state_t _avl_child_l(avl_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if (binary_tree_balance(*tree) > 1)
		{
			(*tree) = binary_tree_rotate_right(*tree);
		}
		return (AVL_CHILD_L);
	}
	if (value > (*tree)->n)
	{
		if (binary_tree_balance(*tree) < -1)
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			(*tree) = binary_tree_rotate_left(*tree);
		}
		return (AVL_CHILD_R);
	}
	return (AVL_RETURN);
}

/**
 * _avl_child_r - execute upon return to parent from child's right subtree
 * @tree: a pointer to the node's parent
 * @value: the inserted value
 *
 * Return: the resulting AVL state
 */
avl_state_t _avl_child_r(avl_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if (binary_tree_balance(*tree) > 1)
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			(*tree) = binary_tree_rotate_right(*tree);
		}
		return (AVL_CHILD_L);
	}
	if (value > (*tree)->n)
	{
		if (binary_tree_balance(*tree) < -1)
		{
			(*tree) = binary_tree_rotate_left(*tree);
		}
		return (AVL_CHILD_R);
	}
	return (AVL_RETURN);
}

/**
 * _avl_insert - insert a value into an AVL tree
 * @node: a pointer to memory to store a pointer to the new node
 * @tree: a double pointer to the root of the tree
 * @value: the value to insert
 *
 * Return: the current state of AVL insertion
 */
avl_state_t _avl_insert(avl_t **node, avl_t **tree, int value)
{
	avl_t **child = NULL;

	if (!*tree)
		return (AVL_CREATE);

	if (value == (*tree)->n)
		return (AVL_RETURN);

	if (value < (*tree)->n)
		child = &((*tree)->left);
	else
		child = &((*tree)->right);

	switch (_avl_insert(node, child, value))
	{
	case AVL_CHILD_L:
		return (_avl_child_l(tree, value));

	case AVL_CHILD_R:
		return (_avl_child_r(tree, value));

	case AVL_CREATE:
		*node = *child = binary_tree_node(*tree, value);
		if (value < (*tree)->n)
			return (AVL_CHILD_L);
		if (value > (*tree)->n)
			return (AVL_CHILD_R);
		/* fallthrough */
	default:
		return (AVL_RETURN);
	}
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

	if (!tree)
		return (NULL);

	if (!*tree)
		return ((*tree = binary_tree_node(*tree, value)));

	switch (_avl_insert(&node, tree, value))
	{
	case AVL_CHILD_L:
		return (_avl_child_l(tree, value), node);

	case AVL_CHILD_R:
		return (_avl_child_r(tree, value), node);

	case AVL_CREATE:
		if (value < (*tree)->n)
			return ((*tree)->left = binary_tree_node(*tree, value));
		if (value > (*tree)->n)
			return ((*tree)->right = binary_tree_node(*tree, value));
		/* fallthrough */
	default:
		return (NULL);
	}
}
/**
 * avl_remove -
 *
 * Return:
 */
avl_t *avl_remove(avl_t *root, int value)
{

}
