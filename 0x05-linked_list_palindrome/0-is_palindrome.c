#include "lists.h"

/**
 * reverse - reverses linked list
 * @h: Linked list
 * Return: reversed list
 */
listint_t *reverse(listint_t **h)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*h)
	{
		next = (*h)->next;
		(*h)->next = prev;
		prev = *h;
		*h = next;
	}
	*h = prev;
	return (*h);
}

/**
 * check_palindrome - checks
 * Description: Using fast and slow pointers to find the middle of the LL
 * and reversing the second half of the list
 * Time complexity: O(n), space: O(1)
 * @head: Linked list
 * Return: Return 1 if LL is palindrome, 0 otherwiese
 */
int check_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *temp = NULL;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast)
		slow = slow->next;
	fast = *head;
	temp = reverse(&slow);
	while (slow)
	{
		if (fast->n != slow->n)
		{
			reverse(&temp);
			return (0);
		}
		fast = fast->next;
		slow = slow->next;
	}
	reverse(&temp);
	return (1);
}

/**
 * check_palindrome_rec - function for telling if Linked List is palindrome
 * Description: Uses function stack to store nodes,
 * hitting the last node of the LL and comparing it to head,
 * with each comparison head is incremented
 * Time complexity: O(n), space: O(n) for using function stack
 * @head: adress of the head pointer, passing by reference
 * @cur: current node of the linked list
 * Return: Return 1 if LL is palindrome, 0 otherwiese
 */
int check_palindrome_rec(listint_t **head, listint_t *cur)
{
	int res;

	if (!cur->next)
		return ((*head)->n == cur->n);
	res = check_palindrome_rec(head, cur->next);
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
	return (check_palindrome(h_copy)); /* Iterative function */
	/* return (check_palindrome_rec(h_copy, *h_copy));  Recursive function */
}
