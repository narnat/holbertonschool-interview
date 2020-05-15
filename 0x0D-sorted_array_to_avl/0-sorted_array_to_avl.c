#include "binary_trees.h"

/**
 * new_node - create a new node
 * @val: value of the node
 * @parent: parent node
 * Return: a new node
 */
avl_t *new_node(int val, avl_t *parent)
{
		avl_t *node;

		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		node->n = val;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		return (node);
}

/**
 * convert_to_avl - converts array to AVL tree
 * @array: sorted array to be converted
 * @lo: low index of @array
 * @hi: high index of @array
 * @parent: parent node
 * Return: new AVL tree
*/
avl_t *convert_to_avl(int *array, size_t lo, size_t hi, avl_t *parent)
{
		size_t mid;
		avl_t *root;

		if (hi == ULONG_MAX || lo > hi)
			return (NULL);
		mid = lo + (hi - lo) / 2;
		root = new_node(array[mid], parent);
		if (!root)
			return (NULL);

		root->left = convert_to_avl(array, lo, mid - 1, root);
		root->right = convert_to_avl(array, mid + 1, hi, root);
		return (root);
}

/**
 * sorted_array_to_avl - sorted array to AVL tree
 * @array: sorted array to be converted
 * @size: size of @array
 * Return: new AVL tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (!array || !size)
			return (NULL);
		return (convert_to_avl(array, 0, size - 1, NULL));
}
