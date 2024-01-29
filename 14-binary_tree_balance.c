#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the height of the @tree, 0 otherwise.
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right, left;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((left >= right ? left : right) + 1);
}

/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the balance factor of the @tree.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
