#!/usr/bin/python3


def minOperations(n):
    if (n < 1):
        return 0

    result = 0

    def minOps(l, ops, p):
        if l == n:
            nonlocal result
            result = ops
            return True
        if l > n:
            return False

        return minOps(l * 2, ops + 2, l) or minOps(l + p, ops + 1, p)

    minOps(2, 2, 1)
    return result
