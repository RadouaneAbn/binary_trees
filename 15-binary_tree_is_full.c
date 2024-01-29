#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 1 if it is full, 0 otherwise.
 **/
size_t binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
