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

/**
 * min_value - This functino get teh min value of a tree
 * @root: Pointer to the root of a tree
 *
 * Return: Pointer to the node containing the min value
 */

bst_t *min_value(bst_t *root)
{
	while (root->left)
		root = root->left;

	return (root);
}

/**
 * get_successor - This function gets the inorder_seccessor of a node
 * @node: the current node
 *
 * Return: Pointer to successor
 */

bst_t *get_successor(bst_t *node)
{
	if (node->right)
		return (min_value(node->right));

	if (node->left)
		return (node->left);

	return (node);
}

/**
 * remove - This function removes a node from BST
 * @parent: Pointer to the parent of the node (or NULL if node is null)
 * @node: The node to be removed
 * @succ: Pointer to the successor
 */

void remove(bst_t *parent, bst_t *node, bst_t *succ)
{
	if (parent && node == parent->left)
	{
		succ->parent->left = NULL;
		succ->parent = parent;
		parent->left = succ;
		succ->right = node->right;
		succ->left = node->left;
		node->left->parent = succ;
		node->right->parent = succ;
		node->right = succ;
	}
	else if (parent && node == parent->right)
	{
		parent->right = succ;
		succ->parent = parent;
	}
	else
	{
		succ->parent->left = NULL;
		succ->parent = parent;
		succ->right = node->right;
		succ->left = node->left;
		node->left->parent = succ;
		node->right->parent = succ;
	}

	free(node);
}

/**
 * bst_remove - This function removes a node with the containing value
 *  from a BST if it exists
 * @root: Pointer to teh root of the BST
 * @value: The value to be removed
 *
 * Return: Pointer to the new root or NULL if the value isn't in the tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *succ, *parent;

	if (!root)
		return (NULL);

	node = bst_search(root, value);
	if (!node)
		return (root);
	parent = node->parent;

	succ = get_successor(node);
	remove(parent, node, succ);
	if (!parent)
		root = succ;

	return (root);
}
