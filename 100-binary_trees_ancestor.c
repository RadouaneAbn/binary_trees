#include "binary_trees.h"

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
	binary_tree_t *f_an, *s_an;

	if (!first || !second)
		return (NULL);

	f_an = first->parent;
	s_an = second->parent;

	if (s_an == f_an)
		return (f_an);
	else if (first == s_an)
		return (s_an);
	else if (second == f_an)
		return (f_an);

	return (binary_trees_ancestor(first->parent, second->parent));
}
