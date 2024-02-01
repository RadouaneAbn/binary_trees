#include "binary_trees.h"
#define MAX 1 /* get the max value */
#define MIN 0 /* get the min value */

/**
 * get_value - This function gets the max or min value of a tree
 * @root: Pointer to the root of the tree
 * @order: A (0/1)/(false/true) flag to help checking for max or min value
 *
 * Return: the max value of the current tree
 */

int get_value(const binary_tree_t *root, int order)
{
	/* o for order order_right .... based on the order if MAX or MIN*/
	int o_right, o_left, o_value = 0;

	if (!root)
		return (0);

	o_left = get_value(root->left, order);
	o_right = get_value(root->right, order);

	if (!root->left && !root->right)
		o_value = root->n;
	else if (!root->left)
		o_value = (root->right->n > root->n) == order ? root->right->n : root->n;
	else if (!root->right)
		o_value = (root->left->n < root->n) == order ? root->left->n : root->n;
	else
	{
		o_value = ((o_left > o_right) == order) ? o_left : o_right;
		o_value = ((o_value < root->n) == order) ? root->n : o_value;
	}

	return (o_value);
}

/**
 * BST_check - This function checks if a tree is BST valid tree
 * @root: Pointer to the root of the tree
 *
 * Return: 1 if tree is BST valid or 0 if not
 */

int BST_check(const binary_tree_t *root)
{
	if (!root)
		return (1);

	if (root->left && get_value(root->left, MAX) >= root->n)
		return (0);

	if (root->right && get_value(root->right, MIN) <= root->n)
		return (0);

	if (!BST_check(root->left) || !BST_check(root->right))
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl_helper - This is a helper function that checks
 *  if Binary Search Tree is AVL tree
 * @tree: Pointer to the tree
 *
 * Return: 1 if the tree is AVL valid or 0 if not
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int balance, left_hight = -1, right_hight = -1;

	if (!tree)
		return (1);

	if (tree->left)
		left_hight = binary_tree_height(tree->left);
	if (tree->right)
		right_hight = binary_tree_height(tree->right);

	balance =  left_hight - right_hight;
	if (balance > 1 || balance < -1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) &&
			binary_tree_is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - This function checks if a BST is valid AVL tree
 * @tree: Pointer to the tree
 *
 * Return: 1 if the tree is AVL valid
 *  0 if not or if not BST
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && BST_check(tree))
		return (binary_tree_is_avl_helper(tree));

	return (0);
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
	size_t height = 0, h_l = 0, h_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_l = binary_tree_height(tree->left);
	h_r = binary_tree_height(tree->right);

	if (h_l > h_r)
		height += h_l + 1;
	else
		height += h_r + 1;

	return (height);
}
