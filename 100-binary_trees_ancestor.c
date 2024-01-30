#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 * Return: the depth, 0 otherwise.
 **/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * get_ancestor - This is helper function that returns the lowest common
 *	ancestor of two nodes at the same depth
 *
 * @first:  a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: pointer to the ancestor node
 */

binary_tree_t *get_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *common_ancestor = first->parent;

	if (first == second)
		return ((binary_tree_t *)first);

	if (first->parent != second->parent)
		common_ancestor = get_ancestor(first->parent, second->parent);

	return (common_ancestor);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first:  a pointer to the first node
 * @second: a pointer to the second node
 * Return: pointer to the ancestor node
 **/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t f_node, s_node, i;
	const binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	f_node = binary_tree_depth(first);
	s_node = binary_tree_depth(second);

	if (f_node == s_node)
		return (get_ancestor(first, second));

	if (f_node > s_node)
	{
		tmp = first;
		for (i = f_node; i > s_node; i--)
			tmp = tmp->parent;
		return (get_ancestor(tmp, second));
	}
	else
	{
		tmp = second;
		for (i = s_node; i > f_node; i--)
			tmp = tmp->parent;
		return (get_ancestor(first, tmp));
	}
}
