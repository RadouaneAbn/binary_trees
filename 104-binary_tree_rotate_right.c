#include "binary_trees.h"

/**
 * binary_tree_rotate_right - This function performs a right-rotation
 *  on a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Pointer to the new root or NULL in case of a failure
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *new_root;

	if (!tree || !tree->left)
		return (NULL);

	tmp = tree->left->right;
	if (tmp)
		tmp->parent = tree;

	new_root = tree->left;
	new_root->parent = NULL;
	new_root->right = tree;

	tree->parent = new_root;
	tree->left = tmp;

	return (new_root);
}
