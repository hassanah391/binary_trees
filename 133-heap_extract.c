#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 if it fails.
 */
int heap_extract(heap_t **root)
{
    heap_t *node;
    int value, last_value;

    if (!root || !*root)
        return (0);

    /* Save the value of the root node to return */
    value = (*root)->n;

    /* Find the last node in level-order traversal */
    node = *root;
    while (node->left || node->right)
    {
        if (node->left)
            node = node->left;
        else
            node = node->right;
    }

    /* Save the value of the last node */
    last_value = node->n;

    /* Remove the last node */
    if (node->parent)
    {
        if (node->parent->left == node)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
    }

    /* Replace the root value with the last node's value */
    (*root)->n = last_value;

    /* Free the memory of the last node */
    free(node);

    /* Rebuild the heap */
    heapify(*root);

    return (value);
}

/**
 * heapify - Restores the Max Heap property in the binary heap.
 * @node: Pointer to the node to heapify down from.
 */
void heapify(heap_t *node)
{
    heap_t *largest = node;
    int temp;

    if (!node)
        return;

    /* Compare node with its left child */
    if (node->left && node->left->n > largest->n)
        largest = node->left;

    /* Compare node with its right child */
    if (node->right && node->right->n > largest->n)
        largest = node->right;

    /* Swap values if necessary and recurse */
    if (largest != node)
    {
        temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify(largest);
    }
}
