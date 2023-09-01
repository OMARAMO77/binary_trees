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

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (is_complete_helper(tree, index, size));
}

/**
 * is_complete_helper - helper function to check if a binary tree is complete
 * @tree: pointer to the current node being checked
 * @index: index of the current node in a complete binary tree
 * @size: size of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_helper(tree->left, 2 * index + 1, size) &&
			is_complete_helper(tree->right, 2 * index + 2, size));
}
