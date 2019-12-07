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
		node = node->right;
		if (node)
		{
			next = node;
			while ((next = next->left))
				node = next;
		}
	}
	return (node);
}

/**
 * _bst_replace - replace a node with it's successor a BST
 * @target: a pointer to the target node
 *
 * Return: a pointer to the successor
 */
bst_t *_bst_replace(bst_t *target)
{
	bst_t *successor = bst_inorder_successor(target);

	if (successor)
	{
		successor->left = target->left;
		if (successor->left)
			successor->left->parent = successor;
		if (successor != target->right)
		{
			successor->parent->left = successor->right;
			if (successor->right)
				successor->right->parent = successor->parent;
			successor->right = target->right;
			if (successor->right)
				successor->right->parent = successor;
		}
		successor->parent = target->parent;
	}
	return (successor);
}

/**
 * bst_replace - replace a node with it's successor a BST
 * @current: a double pointer to the target node
 *
 * Return: a pointer to the replaced node
 */
bst_t *bst_replace(bst_t **current)
{
	bst_t *successor = NULL, *target = *current;

	if (target)
	{
		if (target->left && target->right)
		{
			successor = _bst_replace(target);
		}
		else if (target->left)
		{
			successor = target->left;
			successor->right = target->right;
			if (successor->right)
				successor->right->parent = successor;
			successor->parent = target->parent;
		}
		else if (target->right)
		{
			successor = target->right;
			successor->left = target->left;
			if (successor->left)
				successor->left->parent = successor;
			successor->parent = target->parent;
		}
	}
	*current = successor;
	return (target);
}



/**
 * _bst_remove - remove an element from a BST
 * @tree: a pointer to the the tree from which to remove an element
 * @value: the value of the element to remove
 *
 * Return: If tree is NULL or the given value cannot be found, return NULL.
 * Otherwise, return a pointer to the root of the resulting tree.
 */
bst_t *_bst_remove(bst_t **tree, int value)
{
	if (*tree)
	{
		if (value < (*tree)->n)
			return (_bst_remove(&((*tree)->left), value), *tree);
		if (value > (*tree)->n)
			return (_bst_remove(&((*tree)->right), value), *tree);
		free(bst_replace(tree));
		return (*tree);
	}
	return (NULL);
}

/**
 * bst_remove - remove an element from a BST
 * @root: a pointer to the root of the tree from which to remove an element
 * @value: the value of the element to remove
 *
 * Return: If tree is NULL, return NULL.
 * Otherwise, return a pointer to the root of the resulting tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root)
		_bst_remove(&root, value);

	return (root);
}
