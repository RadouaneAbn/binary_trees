#include "binary_trees.h"
#include <stdio.h>

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
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the height of the @tree, 0 otherwise.
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right, left;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((left >= right ? left : right) + 1);
}

/**
 * _pow - This function return x power n
 * @x: the number
 * @n: the power
 *
 * Return: The result
 */

size_t _pow(size_t x, size_t n)
{
	return (n == 0 ? 1 : x * _pow(x, n - 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 1 if it is perfect, 0 otherwise.
 **/

size_t binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes, max_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);
	max_nodes = _pow(2, height + 1) - 1;

	return (nodes == max_nodes ? 1 : 0);
}
