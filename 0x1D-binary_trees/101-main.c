#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
	printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root = NULL;

	binary_tree_print(root);
	binary_tree_levelorder(root, &print_num);

	root = binary_tree_node(NULL, 98);

	binary_tree_print(root);
	binary_tree_levelorder(root, &print_num);

	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->left->right->left = binary_tree_node(root->left->right, 666);
	root->left->right->left->left = binary_tree_node(root->left->right->left, 999);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	root->right->left->right = binary_tree_node(root->right->left, 123);
	root->right->right->left = binary_tree_node(root->right->right, 1024);

	binary_tree_print(root);
	binary_tree_levelorder(root, &print_num);

	binary_tree_delete(root);

	return (0);
}
