#include "binary_trees.h"

/**
 * bst_inorder_successor - find the in-order successor of a node in a BST
 * @node: the node for which the in-order successor should be found
 *
 * Return: Return a pointer to the in-order successor.
 * If no such node exists, return NULL.
 */
bst_t *bst_inorder_successor(bst_t *node)
{
	bst_t *next = node;

	if (node)
	{
		next = next->right;
		if (next)
		{
			node = next;
			while ((next = next->left))
				node = next;
		}
	}
	return (node);
}

/**
 * _bst_remove - remove an element from a BST
 * @tree: a pointer to the the tree from which to remove an element
 * @value: the value of the element to remove
 *
 * Return: If tree is NULL or the given value cannot be found, return NULL.
 * Otherwise, return a pointer to the node containing the given value.
 */
bst_t *_bst_remove(bst_t **tree, int value)
{
	bst_t *successor = NULL;

	if (*tree)
	{
		if (value < (*tree)->n)
			return (_bst_remove(&((*tree)->left), value), *tree);
		if (value > (*tree)->n)
			return (_bst_remove(&((*tree)->right), value), *tree);
		if ((*tree)->left && (*tree)->right)
		{
			successor = bst_inorder_successor(*tree);
			if (successor)
			{
				successor->left = (*tree)->left;
				if (successor->left)
					successor->left->parent = successor;
				successor->parent->left = successor->right;
				if (successor->right)
					successor->right->parent = successor->parent;
				successor->right = (*tree)->right;
				if (successor->right)
					successor->right->parent = successor;
				successor->parent = (*tree)->parent;
			}
		}
		else if ((*tree)->left)
		{
			successor = (*tree)->left;
			successor->parent = (*tree)->parent;
		}
		else if ((*tree)->right)
		{
			successor = (*tree)->right;
			successor->parent = (*tree)->parent;
		}
		return (free(*tree), (*tree = successor));
	}
	return (NULL);
}

/**
 * bst_remove - remove an element from a BST
 * @root: a pointer to the root of the tree from which to remove an element
 * @value: the value of the element to remove
 *
 * Return: If tree is NULL or the given value cannot be found, return NULL.
 * Otherwise, return a pointer to the node containing the given value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (_bst_remove(&root, value));
}
