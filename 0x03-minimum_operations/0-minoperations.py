#!/usr/bin/python3
""""

    In a text file, there is a single character H. Your text editor can
execute only two operations in this file: Copy All and Paste. Given a
number n, write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.

"""


def minOperations(n):
    if (n <= 1):
        return 0

    result = float('inf')

    def minOps(l, ops, p):
        if l == n:
            nonlocal result
            result = min(result, ops)
            return
        if l > n:
            return

        minOps(l * 2, ops + 2, l)
        minOps(l + p, ops + 1, p)

    minOps(2, 2, 1)
    return result
