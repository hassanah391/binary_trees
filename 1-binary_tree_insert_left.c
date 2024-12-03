#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_node;

	new_node = binary_tree_node(parent, value);

	if (parent == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;

	else
	{
		/* If parent already has a left-child */
		old_node = parent->left; /* a ptr to left-child (old_node) */
		parent->left = new_node; /*newnode now is left node of parent*/
		old_node->parent = new_node; /*parent of old is new node now*/
		new_node->left = old_node; /*oldnode now is the left of new*/
	}

	return (new_node);

}
