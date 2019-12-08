#include "binary_trees.h"

/**
 * binary_tree_find_root - find the root of a binary tree
 * @node: a pointer to a binary tree node
 *
 * Return: a pointer to the root of the tree
 */
const bt_t *binary_tree_find_root(const bt_t *node)
{
	const bt_t *root = node;

	if (node)
	{
		while ((node = node->parent))
			root = node;
	}
	return (root);
}

/**
 * _binary_trees_ancestor - find the least common ancestor of two nodes
 * @root: a pointer to a subtree root
 * @n1: a pointer to a descendant
 * @n2: a pointer to a descendant
 *
 * Return: a pointer to the least common ancestor
 */
bt_t *_binary_trees_ancestor(const bt_t *root, const bt_t *n1, const bt_t *n2)
{
	const bt_t *lhs = NULL;
	const bt_t *rhs = NULL;

	if (root)
	{
		if (root == n1 || root == n2)
			return ((bt_t *) root);

		lhs = _binary_trees_ancestor(root->left, n1, n2);
		rhs = _binary_trees_ancestor(root->right, n1, n2);

		if (lhs && rhs)
			return ((bt_t *) root);
		if (lhs)
			return ((bt_t *) lhs);
		if (rhs)
			return ((bt_t *) rhs);
	}
	return (NULL);
}

/**
 * binary_trees_ancestor - find the least common ancestor of two nodes
 * @n1: a pointer to a node
 * @n2: a pointer to a node
 *
 * Return: a pointer to the least common ancestor
 */
bt_t *binary_trees_ancestor(const bt_t *n1, const bt_t *n2)
{
	const bt_t *root1 = NULL;
	const bt_t *root2 = NULL;

	if (n1 == n2)
		return ((bt_t *) n1);

	root1 = binary_tree_find_root(n1);
	root2 = binary_tree_find_root(n2);

	if (root1 == root2)
		return ((bt_t *) _binary_trees_ancestor(root1, n1, n2));

	return (NULL);
}
