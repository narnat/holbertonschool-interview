#!/usr/bin/python3


def canUnlockAll(boxes):

    if not boxes or len(boxes) == 0:
        return True
    visited = {0}
    stack_of_keys = [0]

    # if isinstance(boxes, list):
    #     for b in boxes:
    #         if not isinstance(b, list):
    #             return False
    #         for ki in range(len(b)):
    #             if not isinstance(b[ki], int):
    #                 return False
    #             if b[ki] < 0 or b[ki] > len(boxes) - 1:
    #                 del b[ki]
    while stack_of_keys:
        room = stack_of_keys.pop()
        for key in boxes[room]:
            if isinstance(
                    key, int) and 0 <= key < len(boxes) and key not in visited:
                visited.add(key)
                stack_of_keys.append(key)

    return len(boxes) == len(visited)
