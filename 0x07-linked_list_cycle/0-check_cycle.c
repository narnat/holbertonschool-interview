#include "lists.h"

/**
 * check_cycle - checks cycle in singly linked list
 * @list: head of linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (!list || !list->next)
		return (0);

	slow = list;
	fast = list->next->next;

	while (fast && fast->next)
	{
		if (slow->n == fast->n)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}
