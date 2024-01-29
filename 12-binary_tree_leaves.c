#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	if (tree->left || tree->right) /* if not leaf, return without adding 1 */
		return (left + right);

	return (left + right + 1);	/* otherwise, add it */
}
