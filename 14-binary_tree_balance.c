 #include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the height of the @tree, 0 otherwise.
 **/
size_t height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (!tree)
		return (0);

	left += 1 + height(tree->left);
	right += 1 + height(tree->right);

	return ((left >= right ? left : right));
}

/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the height.
 * Return: the balance factor of the @tree.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_l = -1, h_r = -1, balance = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	if (tree->left)
		h_l = binary_tree_height(tree->left);
	if (tree->right)
		h_r = binary_tree_height(tree->right);

	balance = h_l - h_r;
	return (balance);
}
