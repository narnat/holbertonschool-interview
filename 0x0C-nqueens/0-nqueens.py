#!/usr/bin/python3
''' N queens problem '''
import sys
from copy import deepcopy


def is_valid(board, row):
    for i in range(row):
        diff = abs(board[i][1] - board[row][1])
        if diff == 0 or diff == row - i:
            return False
    return True


def n_queens(res, board, row, n):
    if row == n:
        # Deep copy is needed because board is a 2D list
        # or you can just print the board if task is to dislay solutions
        res.append(deepcopy(board))
    else:
        for col in range(n):
            board[row][1] = col
            if is_valid(board, row):
                n_queens(res, board, row + 1, n)


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
    board = [[i, -1] for i in range(n)]
    n_queens(res, board, 0, n)
    for i in res:
        print(i)
