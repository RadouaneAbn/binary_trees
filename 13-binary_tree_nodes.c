#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: the number of nodes
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	if (!(tree->left || tree->right)) /* if not a node, return without +1 */
		return (left + right);

	return (left + right + 1);	/* otherwise, add it */

}
