#include "binary_trees.h"
#include <stdio.h>

/**
 * depth - measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 * Return: the depth, 0 otherwise.
 **/
size_t depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 1 if it is perfect, 0 otherwise.
 **/
size_t binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		printf("leaf: %i, depth: %li\n", tree->n, depth(tree));

	binary_tree_is_perfect(tree->left);
	binary_tree_is_perfect(tree->right);
	return (0);
}
