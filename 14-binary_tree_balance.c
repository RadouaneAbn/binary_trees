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
	size_t height = 0, h_l = 0, h_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_l = binary_tree_height(tree->left);
	h_r = binary_tree_height(tree->right);

	if (h_l > h_r)
		height += h_l + 1;
	else
		height += h_r + 1;

	return (height);
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
	int h_l = -1, h_r = -1;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	if (tree->left)
		h_l = binary_tree_height(tree->left);
	if (tree->right)
		h_r = binary_tree_height(tree->right);

	return (h_l - h_r);
}
