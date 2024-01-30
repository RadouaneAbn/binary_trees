#include "binary_trees.h"

/**
 * binary_tree_rotate_left - This function performs a left-rotation
 *  on a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Pointer to the new root or NULL in case of a failure
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *new_root;

	if (!tree || !tree->right)
		return (NULL);

	tmp = tree->right->left;
	if (tmp)
		tmp->parent = tree->left;

	new_root = tree->right;
	new_root->parent = NULL;
	new_root->left = tree;

	tree->parent = new_root;
	tree->right = tmp;

	return (new_root);
}
