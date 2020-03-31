#include "palindrome.h"

/**
 * get_number_length - function to calculates the number of digits
 * @n: unsigned integer
 * Return: number of digits
*/
int get_number_length(unsigned long n)
{
	int l = 0;

	while (n != 0)
	{
		n /= 10;
		++l;
	}

	return (l);
}

/**
 * is_palindrome - function that checks whether or not a
 * given unsigned integer is a palindrome
 * @n: unsigned integer to check
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long left_mask = 1, right_mask = 1;
	int i, l = get_number_length(n);
	unsigned long left_digit, right_digit;

	for (i = 0; i < l - 1; ++i)
		left_mask *= 10;

	for (i = 0; i < l / 2; ++i, left_mask /= 10, right_mask *= 10)
	{
		left_digit = (n / left_mask) % 10;
		right_digit = (n / right_mask) % 10;
		if (left_digit != right_digit)
			return (0);
	}

	return (1);
}
