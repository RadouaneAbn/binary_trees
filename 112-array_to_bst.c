#include "binary_trees.h"

/**
 * array_to_bst - This function bulit a Binary Search Tree from an array
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root of the new tree
 *	or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
