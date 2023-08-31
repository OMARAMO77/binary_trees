#include "binary_trees.h"

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: pointer to the first node
  * @second: pointer to the second node
  *
  * Return: pointer to the lowest common ancestor node of the two given nodes
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	int visit_count = 0, i;
	binary_tree_t *ancestor;
	binary_tree_t *visited_ancestors[100];

	if (!first || !second)
		return NULL;

	ancestor = (binary_tree_t *)first;
	while (ancestor)
	{
		visited_ancestors[visit_count++] = ancestor;
		ancestor = ancestor->parent;
	}

	ancestor = (binary_tree_t *)second;
	while (ancestor)
	{
		for (i = 0; i < visit_count; i++)
		{
			if (ancestor == visited_ancestors[i])
				return ancestor;
		}
		ancestor = ancestor->parent;
	}

	return NULL;
}
