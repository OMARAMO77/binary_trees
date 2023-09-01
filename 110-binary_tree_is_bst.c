#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - helper function to check if a binary tree is a valid BST
 * @node: current node being checked
 * @min: minimum value the current node can have
 * @max: maximum value the current node can have
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_helper(node->left, min, node->n) &&
			is_bst_helper(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - check if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
