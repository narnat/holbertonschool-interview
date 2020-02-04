#!/usr/bin/python3


def canUnlockAll(boxes):

    if not boxes or len(boxes) == 0:
        return True
    visited = {0}
    stack_of_keys = [0]

    while stack_of_keys:
        room = stack_of_keys.pop()
        if room >= len(boxes):
            continue
        for key in boxes[room]:

            if key not in visited:
                visited.add(key)
                stack_of_keys.append(key)

    return len(boxes) == len(visited)
