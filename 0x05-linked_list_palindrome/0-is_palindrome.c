#include "lists.h"

/**
 * check_palindrome - helper recurusive function for is_palindrome function
 *
 * @head: adress of the head pointer, passing by reference
 * @cur: current node of the linked list
 * Return: Return 1 if LL is palindrome, 0 otherwiese
 */
static int check_palindrome(listint_t **head, listint_t *cur)
{
	int res;

	if (!cur->next)
		return ((*head)->n == cur->n);
	res = check_palindrome(head, cur->next);
	*head = (*head)->next;
	return (res && (*head)->n == cur->n);
}

/**
 * is_palindrome - check whether linked list is palindrome
 *
 * @head: adress of the head pointer, passing by reference
 * Return: Return 1 if LL is palindrome, 0 otherwiese
 */
int is_palindrome(listint_t **head)
{
	listint_t **h_copy = head;

	if (!head || !*head)
		return (1);
	return (check_palindrome(h_copy, *h_copy));
}
