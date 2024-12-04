#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to insert into the tree.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current;

    if (!tree)
        return (NULL);

    /* If the tree is empty, create the root node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    current = *tree;

    /* Traverse the tree to find the correct position */
    while (current)
    {
        if (value == current->n) /* Ignore duplicate values */
            return (NULL);

        if (value < current->n)
        {
            if (!current->left) /* Insert in the left subtree */
            {
                new_node = binary_tree_node(current, value);
                current->left = new_node;
                return (new_node);
            }
            current = current->left;
        }
        else
        {
            if (!current->right) /* Insert in the right subtree */
            {
                new_node = binary_tree_node(current, value);
                current->right = new_node;
                return (new_node);
            }
            current = current->right;
        }
    }

    return (NULL);
}
