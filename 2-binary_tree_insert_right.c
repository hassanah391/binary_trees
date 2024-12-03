#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL) /* Check allocation success */
		return (NULL);

	if (parent->right == NULL)
		parent->right = new_node;

	else
	{
		/* If parent already has a right-child */
		old_node = parent->right; /* a ptr to right-child (old_node) */
		parent->right = new_node; /*newnode is right node of parent*/
		old_node->parent = new_node; /*parent of old is new node now*/
		new_node->right = old_node; /*oldnode now is the right of new*/
	}

	return (new_node);

}
