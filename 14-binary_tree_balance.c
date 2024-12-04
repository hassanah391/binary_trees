#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height(tree->left)
		- height(tree->right));

}

/**
 * height - Helper function to calculate the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0); /* Base case: empty tree */

	/* Recursively calculate the height of left and right subtrees */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Height is the greater of the two heights plus 1 */
	return (1 + (left_height > right_height ? left_height : right_height));
}
