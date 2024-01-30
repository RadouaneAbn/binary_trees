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

	if (!tree || (!tree->right && !tree->left))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((left >= right ? left : right) + 1);
}

/**
 * binary_tree_levelorder_helper - This function helps to print the nodes data
 *  at a specific level (height)
 *
 * @tree: pointer to a node
 * @func: pointer to the function that will print the data
 * @level: the level of the data that will be printed
 */

void binary_tree_levelorder_helper(const binary_tree_t *tree,
		void (*func)(int), size_t level)
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_levelorder_helper(tree->left, func, level - 1);
		binary_tree_levelorder_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - This function goes through a binary tree
 *  using level-oder traversal
 * @tree: pointer to a node
 * @func: pointer to the function that will print the data
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		binary_tree_levelorder_helper(tree, func, i);
}
