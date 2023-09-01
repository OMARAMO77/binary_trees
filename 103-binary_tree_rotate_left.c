#include "binary_trees.h"

/**
  * binary_tree_rotate_left - performs a left-rotation on a binary tree
  * @tree: pointer to the root node of the tree to rotate
  *
  * Return: pointer to the new root node of the tree once rotated
  */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL;

	if (tree == NULL)
		return (NULL);

	new_parent = tree->right;
	tree->right = new_parent->left;
	new_parent->parent = tree->parent;

	if (tree->right)
		tree->right->parent = tree;

	tree->parent = new_parent;
	new_parent->left = tree;
	return (new_parent);
}
