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
	new_root = tree->right;

	new_root->left = tree;
	tree->right = tmp;
	if (tmp)
		tmp->parent = tree->left;
	tree->parent = new_root;
	new_root->parent = NULL;

	return (new_root);
}
