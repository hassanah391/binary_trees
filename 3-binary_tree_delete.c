#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Description: The function performs a post-order traversal to delete each node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL) /* If tree is NULL, do nothing */
		return;

	/* Recursively delete the left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Free the current node */
	free(tree);
}
