#include "binary_trees.h"

/**
 * insert_node - This function inserts a value in a BST
 * @root: The root of the current tree
 * @value: The value
 *
 * Return: Pointer to the new created node or NULL if the value already exists
 */

bst_t *insert_node(bst_t *root, int value)
{
	/* if the value is less than the current roots value */
	if (value < root->n)
	{
		if (root->left)
			return (insert_node(root->left, value));
		else
			return (root->left = binary_tree_node(root, value));
	}
	/* if the value is bigger than the current roots value */
	else if (value > root->n)
	{
		if (root->right)
			return (insert_node(root->right, value));
		else
			return (root->right = binary_tree_node(root, value));
	}

	/* if the value is equal to the current roots value */
	return (NULL);
}

/**
 * bst_insert - This function adds a value to a BST
 *  or creates a new one if tree is NULL
 * @tree: Pointer to the root of the tree
 * @value: The value to be added to the tree
 *
 * Return: The return of insert_node() which is:
 *  Pointer to the new created node
 *  or NULL if the value already exists
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	return (insert_node(*tree, value));
}
