#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree perfect, otherwise return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, max_nodes;

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	max_nodes = mypow(2, height + 1) - 1;

	if (max_nodes == size)
		return (1);

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or -1 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0); /* Base case: empty tree */

	/* Recursively calculate the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Height is the greater of the two heights plus 1 */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, return 0 If tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->right)
		+ binary_tree_size(tree->left));
}

/**
 * mypow - Measures power raised to the base number
 * @base: the base value
 * @power: the power value
 *
 * Return: returns the power raised to the base number
 */
size_t mypow(size_t base, size_t power)
{
	size_t i, res;

	res = 1;

	for (i = 0; i < power; i++)
		res *= base;

	return (res);

}
