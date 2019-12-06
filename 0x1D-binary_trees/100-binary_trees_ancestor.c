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
 * @first: a pointer to a descendant
 * @second: a pointer to a descendant
 *
 * Return: a pointer to the least common ancestor
 */
const bt_t *_binary_trees_ancestor(
	const bt_t *root, const bt_t *first, const bt_t *second
)
{
	const bt_t *lhs = NULL, *rhs = NULL;

	if (root)
	{
		if (root == first || root == second)
			return (root);

		lhs = _binary_trees_ancestor(root->left, first, second);
		rhs = _binary_trees_ancestor(root->right, first, second);

		if (lhs && rhs)
			return (root);
		if (lhs)
			return (lhs);
		if (rhs)
			return (rhs);
	}
	return (NULL);
}

/**
 * binary_trees_ancestor - find the least common ancestor of two nodes
 * @first: a pointer to a node
 * @second: a pointer to a node
 *
 * Return: a pointer to the least common ancestor
 */
bt_t *binary_trees_ancestor(const bt_t *first, const bt_t *second)
{
	const bt_t *root1 = binary_tree_find_root(first);
	const bt_t *root2 = binary_tree_find_root(second);

	if (first == second)
		return ((bt_t *) first);

	if (root1 && root2 && root1 == root2)
		return ((bt_t *) _binary_trees_ancestor(root1, first, second));

	return (NULL);
}
