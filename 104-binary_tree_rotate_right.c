#include "binary_trees.h"

/**
  * binary_tree_rotate_right - performs a right-rotation on a binary tree
  * @tree: pointer to the root node of the tree to rotate
  *
  * Return: pointer to the new root node of the tree once rotated
  */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL;

	if (tree == NULL)
		return (NULL);

	new_parent = tree->left;
	tree->left = new_parent->right;
	new_parent->parent = tree->parent;

	if (tree->left)
		tree->left->parent = tree;

	tree->parent = new_parent;
	new_parent->right = tree;
	return (new_parent);
}
