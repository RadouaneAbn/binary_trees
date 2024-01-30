#include "binary_trees.h"
#include <stdio.h>

/**
 * total_nodes - gets the number of nodes
 *
 * @parent: a pointer to the parent
 * Return: the total number of nodes/leaves.
 **/
int total_nodes(binary_tree_t *parent)
{
	int left = 0, right = 0;

	if (!parent)
		return (0);

	if (parent->left)
		left += 1 + total_nodes(parent->left);
	if (parent->right)
		right += 1 + total_nodes(parent->right);

	return (right + left);
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

	return ((total_nodes(tree->left) - total_nodes(tree->right)) == 0 ? 1 : 0);
}
