#include "binary_trees.h"

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