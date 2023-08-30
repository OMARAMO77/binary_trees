#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree:  pointer to the root node of the tree to measure the size
 *
 * Return: size of a binary tree, 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		return (size);
	}
	return (0);
}
