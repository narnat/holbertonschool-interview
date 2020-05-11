#!/usr/bin/env python3
''' N queens problem '''
import sys


def is_valid(board, row):
    # print(board)
    for i in range(row):
        diff = abs(board[i][1] - board[row][1])
        # print("col: ", board[i][1], "row: ", row)
        if diff == 0 or diff == row - i:
            return False
    return True


def n_queens(res, board, row, n):
    if row == n:
        res.append(board.copy())
    else:
        for col in range(n):
            board.append([row, col])
            if is_valid(board, row):
                n_queens(res, board, row + 1, n)
            board.pop()


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)

    res = []
    n_queens(res, [], 0, n)
    for i in res:
        print(i)
