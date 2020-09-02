#include "list.h"

/**
* create_node - creates a new node
* @str: data for a new node
* Return: a new node or NULL if failed
*/
List *create_node(char *str)
{
	List *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->str = strdup(str);
	node->next = node->prev = NULL;
	return (node);
}

/**
* add_node_end - add a node at the end of circular linked list
* @list: pointer to a list
* @str: data for a new node
* Return: a new node or NULL if failed
*/
List *add_node_end(List **list, char *str)
{
	List *end, *node;

	if (!list || !str)
		return (NULL);
	node = create_node(str);
	if (!node)
		return (NULL);
	if (*list)
	{
		if ((*list)->prev)
			end = (*list)->prev;
		else
			end = *list;
		end->next = node;
		node->prev = end;
		node->next = *list;
		(*list)->prev = node;
	}
	else
		*list = node;

	return (node);
}

/**
* add_node_begin - add a node at the beginning of circular linked list
* @list: pointer to a list
* @str: data for a new node
* Return: a new node or NULL if failed
*/
List *add_node_begin(List **list, char *str)
{
	return (*list = add_node_end(list, str));
}
