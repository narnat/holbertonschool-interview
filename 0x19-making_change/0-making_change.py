#!/usr/bin/python3
''' Coin change problem '''


def makeChange(coins, total):
    '''
    Classic Greedy algorithm problem
    '''
    if total < 1:
        return 0
    coins.sort(reverse=True)
    num_coins = 0
    for coin in coins:
        if total < 1:
            break
        res, remainder = divmod(total, coin)
        total = remainder
        num_coins += res
    return total == 0 and num_coins or -1
