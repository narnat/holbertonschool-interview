#include "lists.h"

/**
 * insert_node - inserts node at correct place
 * @head: head of the linked list
 * @number: data of the new node
 * Return: sorted linked list with a new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL;
	listint_t *prev = NULL;
	listint_t *next = NULL;

	if (!head || !*head)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = number;
	next = *head;

	while (prev || next)
	{
		if ((!prev || prev->n <= number) && (!next || next->n > number))
		{
			if (!prev)
				*head = node;
			else
				prev->next = node;
			node->next = next;
		}
		prev = next;
		if (next)
			next = next->next;
	}

	return (*head);
}
