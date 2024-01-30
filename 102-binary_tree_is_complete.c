#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size of the @tree, 0 otherwise.
 **/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * bt_c_helper - This function checks if a tree is a complete binary tree
 *  using index of the node compared to the size of the tree
 * @node: the current node (the tree)
 * @index: the index of the node
 * @node_n: the number of nodes in the tree
 *
 * Return: 1 of the tree is a complete tree or 0 otherwise
 */

int bt_c_helper(const binary_tree_t *node, size_t index, size_t node_n)
{
	if (!node)
		return (1);
	if (index >= node_n)
		return (0);

	return (bt_c_helper(node->left, 2 * index + 1, node_n) &&
			bt_c_helper(node->right, 2 * index + 2, node_n));
}

/**
 * binary_tree_is_complete - This function checks if a tree is a
 *  complete binary tree
 * @tree: the tree to be checked
 *
 * Return: 1 of the tree is a complete tree or 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node_n, index = 0;

	if (!tree)
		return (0);

	node_n = binary_tree_size(tree);

	return (bt_c_helper(tree, index, node_n));
}
