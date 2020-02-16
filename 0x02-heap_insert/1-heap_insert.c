#include "binary_trees.h"

/**
 * find_depth - returns depth of leftmost leaf
 * @tree: root tree or subtree
 * Return: depth
 */
int find_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_recursion - recursive function to check if bt is perfect
 * @tree: root
 * @depth: depth
 * @level: checks level
 * Return: 1 if true, 0 if false
 */
int is_perfect_recursion(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursion(tree->left, depth, level + 1) &&
		is_perfect_recursion(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: binary tree
 * Return: 1 if @tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_depth(tree);

	return (is_perfect_recursion(tree, depth, 0));
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}


/**
 * heapify - heapifies node
 * @node: inserted node
 * Return: returns the current node
 */
heap_t *heapify(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);
	while (node->parent)
	{
		if (node->n < node->parent->n)
			return (node);
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: binary tree
 * @value: value of the new node
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *temp = NULL;
	int r_full, l_full, r_height, l_height;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));
	temp = *root;

	while (temp)
	{
		if (!temp->left)
		{
			temp->left = binary_tree_node(temp, value);
			if (!temp->left)
				return (NULL);
			return (heapify(temp->left));
		}
		else if (!temp->right)
		{
			temp->right = binary_tree_node(temp, value);
			if (!temp->right)
				return (NULL);
			return (heapify(temp->right));
		}
		r_full = binary_tree_is_perfect(temp->right);
		l_full = binary_tree_is_perfect(temp->left);
		r_height = binary_tree_height(temp->right);
		l_height = binary_tree_height(temp->left);
		if ((r_full && l_full && r_height == l_height)
		    || (r_full && !l_full && r_height != l_height))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (NULL);
}
