#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node, return NULL
 * if node is NULL or node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node, return NULL
 *        if node is NULL or the parent is NULL
 *        or node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/*If node is NULL or the parent is NULL, return NULL*/
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/*If node has no sibling, return NULL*/
	if ((node->parent->left != NULL
	     && node->parent->right == NULL)
	    || (node->parent->left == NULL
		&& node->parent->right != NULL))
		return (NULL);

	/*In case node is left child of parent sibling node'll be right child*/
	if (node->parent->left == node)
		return (node->parent->right);

	/*In case node is right child of parent sibling node'll be left child*/
	return (node->parent->left);

}
