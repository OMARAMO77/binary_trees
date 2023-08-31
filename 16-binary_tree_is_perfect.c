#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_full(tree) && !binary_tree_balance(tree))
		return (1);
	return (0);
}

/**
  * binary_tree_is_full - checks if a binary tree is full
  * @tree: pointer to the root node of the tree to check
  *
  * Return: 1 if the binary tree is full, 0 otherwise
  */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		return (left_height - right_height);
	}
	return (0);
}

/**
  * binary_tree_height - measures the height of a binary tree
  * @tree: pointer to the root node of the tree to measure the height
  *
  * Return: height of the tree, 0 otherwise
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_side = 0, left_side = 0;

	if (!tree)
		return (0);

	left_side = 1 + binary_tree_height(tree->left);
	right_side = 1 + binary_tree_height(tree->right);

	return (left_side > right_side ? left_side : right_side);
}
