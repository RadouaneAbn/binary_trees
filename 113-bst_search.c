#include "binary_trees.h"

/**
 * bst_search - This function searches for a value in Binary Search Tree
 * @tree: Pointer to the BST
 * @value: the value to be searched for
 *
 * Return: Pointer to the node with the wanted value if found
 *  or NULL if tree is NULL or if nothing found
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (tree->left && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree->right && value > tree->n)
		return (bst_search(tree->right, value));

	return (NULL);
}
