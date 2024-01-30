#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the height of the @tree, 0 otherwise.
 **/
size_t height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (!tree)
		return (0);

	left += 1 + height(tree->left);
	right += 1 + height(tree->right);

	return ((left >= right ? left : right));
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

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (left_height - right_height);
}
